FROM ros:humble-ros-base

ARG INSTALL_CUDA=false
ARG INSTALL_GPU_PYTHON=false
ARG INSTALL_TENSORRT=false
ARG TENSORRT_PIP_SPEC=tensorrt==8.6.1
ARG ONNXRUNTIME_GPU_PIP_SPEC=onnxruntime-gpu==1.18.1

# Install essential build tools
RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-dev \
    libevdev-dev \
    python3-evdev \
    software-properties-common \
    gnupg \
    git \
    build-essential \
    cmake \
    ros-humble-xacro \
    ros-humble-joint-state-publisher \
    ros-humble-rviz2 \
    ros-humble-gazebo-ros-pkgs \
    && rm -rf /var/lib/apt/lists/*

# Install colcon and ROS development tools
RUN apt-get update && apt-get install -y \
    python3-colcon-common-extensions \
    python3-rosdep \
    && rm -rf /var/lib/apt/lists/*

# Optional CUDA toolkit for GPU-enabled builds.
RUN if [ "$INSTALL_CUDA" = "true" ]; then \
            apt-get update && apt-get install -y --no-install-recommends nvidia-cuda-toolkit && \
            rm -rf /var/lib/apt/lists/*; \
        fi

# Add KiCad 9 (includes kicad-cli) from the official KiCad PPA for Ubuntu 22.04
RUN add-apt-repository -y ppa:kicad/kicad-9.0-releases \
    && apt-get update \
    && apt-get install -y kicad \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y python3 python3-pip && \
    update-alternatives --install /usr/bin/python python /usr/bin/python3 10

# Install documentation tools
RUN python3 -m pip install --no-cache-dir sphinx sphinx_rtd_theme myst-parser

# Optional GPU Python stack for CUDA-enabled workflows.
RUN if [ "$INSTALL_GPU_PYTHON" = "true" ]; then \
            python3 -m pip install --no-cache-dir --upgrade pip setuptools wheel && \
            python3 -m pip install --no-cache-dir \
            --extra-index-url https://download.pytorch.org/whl/cu118 \
            torch==2.4.1 \
            torchvision==0.19.1 \
            torchaudio==2.4.1 && \
            python3 -m pip install --no-cache-dir \
            ultralytics \
            opencv-python-headless \
            onnx \
            "$ONNXRUNTIME_GPU_PIP_SPEC" \
            pycocotools \
            numpy \
            scipy \
            cuda-python \
            nvidia-ml-py3; \
        fi

# Optional TensorRT Python bindings for optimized inference.
RUN if [ "$INSTALL_TENSORRT" = "true" ]; then \
            python3 -m pip install --no-cache-dir --extra-index-url https://pypi.nvidia.com "$TENSORRT_PIP_SPEC"; \
        fi

# Create workspace
WORKDIR /micro_ros_ws

# Initialize rosdep if packages exist
RUN rosdep update || true

# Copy entrypoint
COPY docker-entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]
