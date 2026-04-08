#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to custom_interfaces__msg__Gamepad

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gamepad {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Gamepad::default())
  }
}

impl rosidl_runtime_rs::Message for Gamepad {
  type RmwMsg = super::msg::rmw::Gamepad;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        left_stick_x: msg.left_stick_x,
        left_stick_y: msg.left_stick_y,
        right_stick_x: msg.right_stick_x,
        right_stick_y: msg.right_stick_y,
        left_trigger: msg.left_trigger,
        right_trigger: msg.right_trigger,
        dpad_x: msg.dpad_x,
        dpad_y: msg.dpad_y,
        a: msg.a,
        b: msg.b,
        x: msg.x,
        y: msg.y,
        lb: msg.lb,
        rb: msg.rb,
        back: msg.back,
        start: msg.start,
        home: msg.home,
        left_stick_press: msg.left_stick_press,
        right_stick_press: msg.right_stick_press,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      left_stick_x: msg.left_stick_x,
      left_stick_y: msg.left_stick_y,
      right_stick_x: msg.right_stick_x,
      right_stick_y: msg.right_stick_y,
      left_trigger: msg.left_trigger,
      right_trigger: msg.right_trigger,
      dpad_x: msg.dpad_x,
      dpad_y: msg.dpad_y,
      a: msg.a,
      b: msg.b,
      x: msg.x,
      y: msg.y,
      lb: msg.lb,
      rb: msg.rb,
      back: msg.back,
      start: msg.start,
      home: msg.home,
      left_stick_press: msg.left_stick_press,
      right_stick_press: msg.right_stick_press,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      left_stick_x: msg.left_stick_x,
      left_stick_y: msg.left_stick_y,
      right_stick_x: msg.right_stick_x,
      right_stick_y: msg.right_stick_y,
      left_trigger: msg.left_trigger,
      right_trigger: msg.right_trigger,
      dpad_x: msg.dpad_x,
      dpad_y: msg.dpad_y,
      a: msg.a,
      b: msg.b,
      x: msg.x,
      y: msg.y,
      lb: msg.lb,
      rb: msg.rb,
      back: msg.back,
      start: msg.start,
      home: msg.home,
      left_stick_press: msg.left_stick_press,
      right_stick_press: msg.right_stick_press,
    }
  }
}


