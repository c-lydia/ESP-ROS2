#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "custom_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_interfaces__msg__Gamepad() -> *const std::ffi::c_void;
}

#[link(name = "custom_interfaces__rosidl_generator_c")]
extern "C" {
    fn custom_interfaces__msg__Gamepad__init(msg: *mut Gamepad) -> bool;
    fn custom_interfaces__msg__Gamepad__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Gamepad>, size: usize) -> bool;
    fn custom_interfaces__msg__Gamepad__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Gamepad>);
    fn custom_interfaces__msg__Gamepad__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Gamepad>, out_seq: *mut rosidl_runtime_rs::Sequence<Gamepad>) -> bool;
}

// Corresponds to custom_interfaces__msg__Gamepad
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gamepad {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left_stick_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left_stick_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right_stick_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right_stick_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left_trigger: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right_trigger: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub dpad_x: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub dpad_y: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub b: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub lb: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rb: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub back: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub start: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub home: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left_stick_press: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right_stick_press: bool,

}



impl Default for Gamepad {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_interfaces__msg__Gamepad__init(&mut msg as *mut _) {
        panic!("Call to custom_interfaces__msg__Gamepad__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Gamepad {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__Gamepad__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__Gamepad__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__Gamepad__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Gamepad {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Gamepad where Self: Sized {
  const TYPE_NAME: &'static str = "custom_interfaces/msg/Gamepad";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_interfaces__msg__Gamepad() }
  }
}


