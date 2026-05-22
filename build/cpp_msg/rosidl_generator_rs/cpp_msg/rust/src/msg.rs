#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to cpp_msg__msg__Mymsg
/// 调用原始数据类型

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Mymsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub content: std::string::String,

    /// 调用已由的消息类型
    pub image: sensor_msgs::msg::Image,

}



impl Default for Mymsg {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Mymsg::default())
  }
}

impl rosidl_runtime_rs::Message for Mymsg {
  type RmwMsg = super::msg::rmw::Mymsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        content: msg.content.as_str().into(),
        image: sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Owned(msg.image)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        content: msg.content.as_str().into(),
        image: sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Borrowed(&msg.image)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      content: msg.content.to_string(),
      image: sensor_msgs::msg::Image::from_rmw_message(msg.image),
    }
  }
}


