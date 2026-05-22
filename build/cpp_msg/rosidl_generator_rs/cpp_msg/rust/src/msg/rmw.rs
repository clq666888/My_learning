#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "cpp_msg__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__cpp_msg__msg__Mymsg() -> *const std::ffi::c_void;
}

#[link(name = "cpp_msg__rosidl_generator_c")]
extern "C" {
    fn cpp_msg__msg__Mymsg__init(msg: *mut Mymsg) -> bool;
    fn cpp_msg__msg__Mymsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Mymsg>, size: usize) -> bool;
    fn cpp_msg__msg__Mymsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Mymsg>);
    fn cpp_msg__msg__Mymsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Mymsg>, out_seq: *mut rosidl_runtime_rs::Sequence<Mymsg>) -> bool;
}

// Corresponds to cpp_msg__msg__Mymsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// 调用原始数据类型

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Mymsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub content: rosidl_runtime_rs::String,

    /// 调用已由的消息类型
    pub image: sensor_msgs::msg::rmw::Image,

}



impl Default for Mymsg {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !cpp_msg__msg__Mymsg__init(&mut msg as *mut _) {
        panic!("Call to cpp_msg__msg__Mymsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Mymsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cpp_msg__msg__Mymsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cpp_msg__msg__Mymsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { cpp_msg__msg__Mymsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Mymsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Mymsg where Self: Sized {
  const TYPE_NAME: &'static str = "cpp_msg/msg/Mymsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__cpp_msg__msg__Mymsg() }
  }
}


