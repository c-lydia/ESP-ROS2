# Gassify Robot System Model

This document defines a **cleaned, consistent, and structured mathematical model** of the Gassify robot system, covering kinematics, control, perception, estimation, and UI mapping.

## Coordinate System Convention

All computations use a right-handed frame:

* **x-axis:** forward
* **y-axis:** left
* **z-axis:** up
* **yaw ($\theta$):** positive counter-clockwise

Rotation about z-axis:

$$
R_z(\theta) =
\begin{bmatrix}
\cos\theta & -\sin\theta & 0 \\
\sin\theta &  \cos\theta & 0 \\
0          &  0          & 1
\end{bmatrix}
$$

## TF Tree Structure

``` bash
map
└── odom
    └── base_link
        ├── imu_link
        ├── servo_link
        │   └── camera_link
        ├── range_link
        └── wheel_link
```

### Frame definitions

| Frame | Description |
|---|---|
| `map` | Global reference frame (vision-corrected) |
| `odom` | Drift-prone dead-reckoning frame |
| `base_link` | Robot center frame (control reference) |
| `imu_link` | IMU measurement frame |
| `servo_link` | Servo pivot frame — fixed offset from `base_link`, rotates about z by $\phi$ |
| `camera_link` | Camera optical frame — fixed offset from `servo_link` |
| `range_link` | Distance sensor frame |

## Servo Kinematics

Let $\phi$ be the servo pan angle (positive counter-clockwise, same convention as $\theta$).

The transform from `base_link` to `servo_link` is:

$$
T_{\text{base}}^{\text{servo}}(\phi) =
\begin{bmatrix}
R_z(\phi) & \mathbf{t}_{bs} \\
\mathbf{0}^\top & 1
\end{bmatrix}
$$

where $\mathbf{t}_{bs} = [t_x,\, t_y,\, t_z]^\top$ is the fixed mounting offset of the servo pivot from `base_link`.

The transform from `servo_link` to `camera_link` is fixed (mechanical mounting):

$$
T_{\text{servo}}^{\text{cam}} =
\begin{bmatrix}
R_{\text{mount}} & \mathbf{t}_{sc} \\
\mathbf{0}^\top & 1
\end{bmatrix}
$$

The full camera transform in the world frame is:

$$
T_{\text{map}}^{\text{cam}} = T_{\text{map}}^{\text{odom}} \cdot T_{\text{odom}}^{\text{base}} \cdot T_{\text{base}}^{\text{servo}}(\phi) \cdot T_{\text{servo}}^{\text{cam}}
$$

### Servo Control (P controller)

#### Rate limiter (applied to command)

$$
\Delta\phi_{\max} = \dot{\phi}_{\max} \cdot dt
$$

$$
\phi^*_{\text{lim}} = \phi^*_{k-1} + \text{clip}\!\left(\phi^*_k - \phi^*_{k-1},\; -\Delta\phi_{\max},\; +\Delta\phi_{\max}\right)
$$

Hard-clip to physical servo range:

$$
\phi^*_{\text{lim}} = \text{clip}\!\left(\phi^*_{\text{lim}},\; -\phi_{\max},\; +\phi_{\max}\right)
$$

#### P controller

$$
e_\phi = \phi^*_{\text{lim}} - \phi
$$

$$
u_\phi = \text{clip}\!\left(K_p^\phi \cdot e_\phi,\; -u_{\phi,\max},\; +u_{\phi,\max}\right)
$$

#### Closed-loop

Servo mechanical plant modelled as first-order lag:

$$
G_\phi(s) = \frac{K_\phi}{\tau_\phi s + 1}
$$

Closed-loop time constant with P controller:

$$
\tau_{\phi,\text{cl}} = \frac{\tau_\phi}{1 + K_p^\phi K_\phi}
$$

Steady-state error to a step command:

$$
e_{\phi,\text{ss}} = \frac{1}{1 + K_p^\phi K_\phi} \cdot \phi^*
$$

Gain selection from measured $K_\phi$ and $\tau_\phi$:

$$
K_p^\phi = \frac{\omega_{\phi,\text{bw}} \cdot \tau_\phi - 1}{K_\phi}
$$

#### Parameter table

| Symbol | Meaning | How to obtain |
|---|---|---|
| $\phi_{\max}$ | Physical servo limit [rad] | Datasheet |
| $\dot{\phi}_{\max}$ | Max slew rate [rad/s] | Datasheet |
| $\tau_\phi$ | Servo time constant [s] | Step response |
| $K_\phi$ | Servo DC gain [rad per unit cmd] | Step response |
| $K_p^\phi$ | P gain | $\omega_{\phi,\text{bw}} \cdot \tau_\phi / K_\phi$ |
| $u_{\phi,\max}$ | Output saturation | Servo driver range |

## Differential Drive Kinematics

Let $v_r$, $v_l$ denote right/left wheel linear velocities and $L$ the **full wheel separation** (track width).

### Forward model

$$
v = \frac{v_r + v_l}{2}, \qquad \omega = \frac{v_r - v_l}{L}
$$

### Inverse model

$$
v_r = v + \frac{L}{2}\,\omega, \qquad v_l = v - \frac{L}{2}\,\omega
$$

### Robot motion model

$$
\dot{x} = v\cos\theta, \qquad \dot{y} = v\sin\theta, \qquad \dot{\theta} = \omega
$$

### Exact arc pose integration

For $\omega \neq 0$:

$$
x' = x + \frac{v}{\omega}\bigl[\sin(\theta + \omega\,dt) - \sin\theta\bigr]
$$

$$
y' = y - \frac{v}{\omega}\bigl[\cos(\theta + \omega\,dt) - \cos\theta\bigr]
$$

$$
\theta' = \theta + \omega\,dt
$$

For $\omega \approx 0$ (straight line):

$$
x' = x + v\,dt\cos\theta, \qquad y' = y + v\,dt\sin\theta, \qquad \theta' = \theta
$$

## Actuator Dynamics

First-order motor lag model:

$$
\dot{v} = \frac{v_{\text{cmd}} - v}{\tau_v}, \qquad \dot{\omega} = \frac{\omega_{\text{cmd}} - \omega}{\tau_\omega}
$$

Discrete Euler integration:

$$
v_{k+1} = v_k + \frac{v_{\text{cmd}} - v_k}{\tau_v}\,dt, \qquad
\omega_{k+1} = \omega_k + \frac{\omega_{\text{cmd}} - \omega_k}{\tau_\omega}\,dt
$$

### Rate limiting (applied to commands, not plant state)

$$
\Delta v_{\max} = a_{\max}\,dt, \qquad \Delta\omega_{\max} = \alpha_{\max}\,dt
$$

$$
v_{\text{cmd,lim}} = \text{clip}\!\left(v_{\text{cmd}},\; v_k - \Delta v_{\max},\; v_k + \Delta v_{\max}\right)
$$

$$
\omega_{\text{cmd,lim}} = \text{clip}\!\left(\omega_{\text{cmd}},\; \omega_k - \Delta\omega_{\max},\; \omega_k + \Delta\omega_{\max}\right)
$$

The plant state then evolves under physics only — it is never clipped directly.

## State Representation

$$
\mathbf{x} =
\begin{bmatrix}
x & y & \theta & v & \omega & \mathbf{q} & \phi
\end{bmatrix}^\top
$$

where $\mathbf{q} = [q_w,\, q_x,\, q_y,\, q_z]^\top$ is the orientation quaternion and $\phi \in [-\phi_{\max},\, +\phi_{\max}]$ is the servo pan angle read from servo feedback each timestep.

### $\theta$ / $\mathbf{q}$ consistency

$\theta$ and $\mathbf{q}$ both encode orientation. On flat terrain $\theta = \text{yaw}(\mathbf{q})$. Consistency must be enforced at every update step:

$$
\theta = \arctan2\!\bigl(2(q_w q_z + q_x q_y),\; 1 - 2(q_y^2 + q_z^2)\bigr)
$$

**Rule:** IMU updates $\mathbf{q}$ → extract $\theta$ from $\mathbf{q}$. Odometry updates $\theta$ → set $q_w = \cos(\theta/2)$, $q_z = \sin(\theta/2)$, $q_x = q_y = 0$. Never update $\theta$ and $\mathbf{q}$ independently.

## IMU Orientation Estimation (Mahony Filter)

### Gyroscope model

$$
\omega_m = \omega + b_g + n_g, \qquad \omega = \omega_m - b_g
$$

### Gravity estimate from quaternion

$$
\hat{g}_x = 2(q_x q_z - q_w q_y)
$$

$$
\hat{g}_y = 2(q_w q_x + q_y q_z)
$$

$$
\hat{g}_z = q_w^2 - q_x^2 - q_y^2 + q_z^2
$$

$$
\hat{\mathbf{g}} = [\hat{g}_x,\; \hat{g}_y,\; \hat{g}_z]^\top
$$

### Error signal

$$
\mathbf{e} = \mathbf{a} \times \hat{\mathbf{g}}
$$

### PI correction and bias update

$$
\omega_c = \omega + K_p\,\mathbf{e} + K_i \int \mathbf{e}\,dt
$$

$$
\dot{b}_g = -K_i\,\mathbf{e}, \qquad b_g \leftarrow b_g + \dot{b}_g\,dt
$$

### Quaternion update

$$
\dot{\mathbf{q}} = \frac{1}{2}\,\mathbf{q} \otimes \omega_c
$$

$$
\mathbf{q} \leftarrow \mathbf{q} + \dot{\mathbf{q}}\,dt, \qquad \mathbf{q} \leftarrow \frac{\mathbf{q}}{\|\mathbf{q}\|}
$$

## Camera-Based Pose Correction (ArUco)

Measurement (in `camera_link` frame):

$$
z_{\text{cam}} = [\mathbf{p},\, \mathbf{q}]
$$

Since the camera sits on a servo, the ArUco measurement must be back-projected through the full kinematic chain before correcting `base_link`. The marker pose in `base_link` is:

$$
T_{\text{base}}^{\text{marker}} = T_{\text{base}}^{\text{servo}}(\phi) \cdot T_{\text{servo}}^{\text{cam}} \cdot T_{\text{cam}}^{\text{marker}}
$$

> **$\phi$ must be read from the servo at the same timestamp as the camera frame.** A stale servo angle produces a wrong correction.

The map-frame marker pose:

$$
T_{\text{map}}^{\text{marker}} = T_{\text{map}}^{\text{base}} \cdot T_{\text{base}}^{\text{marker}}
$$

Position error:

$$
\mathbf{e}_p = \mathbf{p}_{\text{cam}} - \mathbf{p}_{\text{odom}}
$$

Orientation error:

$$
\mathbf{q}_e = \mathbf{q}_{\text{cam}} \otimes \mathbf{q}_{\text{odom}}^{-1}
$$

Small-angle approximation (planar robot, yaw only):

$$
\delta\theta \approx 2\,\text{vec}(\mathbf{q}_e)_z
$$

State update ($\alpha \in (0,1]$ is a scalar blending gain):

$$
\mathbf{x} \leftarrow \mathbf{x} + \alpha
\begin{bmatrix} \mathbf{e}_p \\ \delta\theta \end{bmatrix}
$$

## TF Consistency

$$
T_{\text{map}}^{\text{base}} = T_{\text{map}}^{\text{odom}} \cdot T_{\text{odom}}^{\text{base}}
$$

### Camera correction

To update the map→odom transform without causing a discontinuous jump in the odom frame:

$$
T_{\text{map}}^{\text{odom}} \leftarrow T_{\text{map}}^{\text{marker}} \cdot \left(T_{\text{odom}}^{\text{base}} \cdot T_{\text{base}}^{\text{servo}}(\phi) \cdot T_{\text{servo}}^{\text{cam}}\right)^{-1}
$$

This ensures $T_{\text{map}}^{\text{odom}} \cdot T_{\text{odom}}^{\text{base}} = T_{\text{cam}}^{\text{map}}$.

### IMU orientation

$$
R_{\text{base}}^{\text{imu}} = R(\mathbf{q})
$$

## Range Sensor Filtering

Measurement:

$$
z = r + n
$$

Median filter over window $W$:

$$
\tilde{r} = \text{median}(W)
$$

Jump gate (reject if change exceeds threshold):

$$
|\tilde{r} - r_f| \leq \Delta_{\max}
$$

Exponential smoothing:

$$
r_f = \alpha\,\tilde{r} + (1-\alpha)\,r_f
$$

## Gas Field Mapping

Measurement model:

$$
z_g = C(x,y) + n
$$

Since the gas sensor sits on the camera which sits on the servo, the measurement location in the world frame is the camera origin projected through the full kinematic chain:

$$
\begin{bmatrix} x_{\text{cam}} \\ y_{\text{cam}} \\ z_{\text{cam}} \\ 1 \end{bmatrix}
= T_{\text{map}}^{\text{odom}} \cdot T_{\text{odom}}^{\text{base}} \cdot T_{\text{base}}^{\text{servo}}(\phi) \cdot T_{\text{servo}}^{\text{cam}} \cdot \begin{bmatrix} 0 \\ 0 \\ 0 \\ 1 \end{bmatrix}
$$

Grid cell indices from world position (cell size $\Delta$):

$$
i = \left\lfloor \frac{x_{\text{cam}} - x_{\min}}{\Delta} \right\rfloor, \qquad
j = \left\lfloor \frac{y_{\text{cam}} - y_{\min}}{\Delta} \right\rfloor
$$

Grid update:

$$
C_{i,j} \leftarrow (1-\alpha)\,C_{i,j} + \alpha\,z_g
$$

Optional diffusion:

$$
\frac{\partial C}{\partial t} = D\,\nabla^2 C
$$

## Pure Pursuit Controller

Goal point $P_g = (x_g, y_g)$.

Distance to goal:

$$
d = \sqrt{(x_g - x)^2 + (y_g - y)^2}
$$

Transform goal into robot body frame:

$$
x_L =  \cos\theta\,(x_g - x) + \sin\theta\,(y_g - y)
$$

$$
y_L = -\sin\theta\,(x_g - x) + \cos\theta\,(y_g - y)
$$

Lookahead distance:

$$
L_d = \sqrt{x_L^2 + y_L^2}
$$

Curvature:

$$
\kappa = \frac{2\,y_L}{L_d^2}
$$

Velocity commands:

$$
\omega = v\,\kappa, \qquad v = \min(v_{\max},\; k_v\,d)
$$

Wheel conversion:

$$
v_r = v + \frac{L}{2}\,\omega, \qquad v_l = v - \frac{L}{2}\,\omega
$$

## Cascaded Control Architecture

Three explicit levels:

| Level | Loop | Input | Output | Controller |
|---|---|---|---|---|
| 1 | Position | $(x, y, \theta)$ error | $v_{\text{cmd}},\, \omega_{\text{cmd}}$ | P or pure pursuit |
| 2 | Velocity | $(v, \omega)$ error | $u_v,\, u_\omega$ | PI with saturation |
| 3 | Actuator | $u_v,\, u_\omega$ | $v,\, \omega$ | First-order lag |

> **Note on Level 1:** pure pursuit and the P position controller are alternative implementations of the same level. Use pure pursuit for path following (waypoint sequences) and the P controller for point stabilisation (single goal). Do not run both simultaneously.

### Level 1 — Position loop (P controller)

$$
e_x = x_g - x, \qquad e_y = y_g - y
$$

$$
d = \sqrt{e_x^2 + e_y^2}
$$

$$
\theta_g = \arctan2(e_y,\, e_x), \qquad e_\theta = \theta_g - \theta
$$

$$
v_{\text{cmd}} = \text{clip}\!\left(K_p^v\,d,\; v_{\max}\right)
$$

$$
\omega_{\text{cmd}} = \text{clip}\!\left(K_p^\theta\,e_\theta,\; \omega_{\max}\right)
$$

### Level 2 — Velocity loop (PI controller)

$$
e_v = v_{\text{cmd}} - v, \qquad e_\omega = \omega_{\text{cmd}} - \omega
$$

$$
u_v = K_p^v\,e_v + K_i^v \int e_v\,dt
$$

$$
u_\omega = K_p^\omega\,e_\omega + K_i^\omega \int e_\omega\,dt
$$

Integrator freeze anti-windup condition:

$$
\text{freeze} = \bigl(|u| \geq u_{\max}\bigr) \;\text{AND}\; \bigl(\text{sign}(u) = \text{sign}(e)\bigr)
$$

When frozen, the integrator state is held: $\dot{x}_I = 0$.

Output saturation:

$$
u_v = \text{clip}(u_v,\; u_{\max}), \qquad u_\omega = \text{clip}(u_\omega,\; u_{\max})
$$

### Level 3 — Actuator dynamics

$$
\dot{v} = \frac{u_v - v}{\tau_v}, \qquad \dot{\omega} = \frac{u_\omega - \omega}{\tau_\omega}
$$

## UI Projection Layer (Visualisation Only)

### Normalisation

$$
x_n = \frac{x - x_{\min}}{x_{\max} - x_{\min}}, \qquad
y_n = \frac{y - y_{\min}}{y_{\max} - y_{\min}}
$$

### Screen mapping

$$
x_{\text{pix}} = x_n\,W, \qquad y_{\text{pix}} = (1 - y_n)\,H
$$

### Inverse mapping

$$
x = x_{\min} + x_{\text{pix}}\,\frac{x_{\max} - x_{\min}}{W}
$$

$$
y = y_{\min} + (H - y_{\text{pix}})\,\frac{y_{\max} - y_{\min}}{H}
$$

### Waypoint set

$$
\mathcal{W} = \{(x_i,\, y_i,\, \text{label}_i)\}
$$

## Closed-Loop System Summary

Full state:

$$
\mathbf{x} = [x,\; y,\; \theta,\; v,\; \omega,\; \mathbf{q},\; \phi]^\top
$$

System update:

$$
\mathbf{x}_{k+1} = f\!\left(\mathbf{x}_k,\; u_k,\; z_{\text{imu}},\; z_{\text{cam}},\; z_{\text{range}},\; \phi_k\right)
$$

Control hierarchy:

$$
\text{Position} \;\rightarrow\; \text{Velocity (PI)} \;\rightarrow\; \text{Actuator dynamics} \;\rightarrow\; \text{Saturation} \;\rightarrow\; \text{Wheels}
$$

$$
\text{Servo target} \;\rightarrow\; \text{Rate limit} \;\rightarrow\; \text{P control} \;\rightarrow\; \text{Saturation} \;\rightarrow\; \phi
$$

$$
\boxed{\text{Nonlinear, stochastic, cascaded, sensor-fused mobile robot system}}
$$

## References

[1] G. Welch and G. Bishop, "An Introduction to the Kalman Filter," University of North Carolina at Chapel Hill, Tech. Rep. TR 95-041, 2006.

[2] R. Siegwart, I. R. Nourbakhsh, and D. Scaramuzza, *Introduction to Autonomous Mobile Robots*, 2nd ed. MIT Press, 2011.

[3] S. Thrun, W. Burgard, and D. Fox, *Probabilistic Robotics*. MIT Press, 2005.

[4] B. Siciliano and O. Khatib, Eds., *Springer Handbook of Robotics*, 2nd ed. Springer, 2016.

[5] T. Madgwick, "An efficient orientation filter for inertial and inertial/magnetic sensor arrays," Univ. Bristol, Tech. Rep., 2010.

[6] R. Mahony, T. Hamel, and J.-M. Pflimlin, "Nonlinear complementary filters on the special orthogonal group," *IEEE Trans. Autom. Control*, vol. 53, no. 5, pp. 1203–1218, 2008.

[7] F. Chaumette and S. Hutchinson, "Visual servo control. I. Basic approaches," *IEEE Robot. Autom. Mag.*, vol. 13, no. 4, pp. 82–90, 2006.

[8] E. Olson, "AprilTag: A robust and flexible visual fiducial system," in *Proc. ICRA*, 2011, pp. 3400–3407.

[9] S. Garrido-Jurado et al., "Automatic generation and detection of highly reliable fiducial markers under occlusion," *Pattern Recognition*, vol. 47, no. 6, pp. 2280–2292, 2014.

[10] ROS 2 Design Team, "REP-103: Standard Units of Measure and Coordinate Conventions," Open Robotics, 2010.

[11] ROS 2 Design Team, "REP-105: Coordinate Frames for Mobile Platforms," Open Robotics, 2010.

[12] R. Coulter, "Implementation of the Pure Pursuit Path Tracking Algorithm," CMU-RI-TR-92-01, 1992.

[13] K. J. Åström and T. Hägglund, *PID Controllers: Theory, Design, and Tuning*, 2nd ed. ISA, 1995.

[14] H. K. Khalil, *Nonlinear Systems*, 3rd ed. Prentice Hall, 2002.

[15] J. J. Craig, *Introduction to Robotics: Mechanics and Control*, 4th ed. Pearson, 2017.

[16] OpenCV Development Team, "OpenCV: Open Source Computer Vision Library." https://opencv.org/

[17] Open Robotics, "tf2: ROS 2 Transform Library." https://docs.ros.org/

[18] Open Robotics, "micro-ROS: ROS 2 for Microcontrollers." https://micro.ros.org/