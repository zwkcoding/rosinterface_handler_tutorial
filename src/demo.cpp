//
// Created by kevin on 11/27/17.
//

#include "rosinterface_handler_tutorial/demo.hpp"

namespace rosinterface_handler_tutorial {

    Demo::Demo(ros::NodeHandle node_handle, ros::NodeHandle private_node_handle)
            : reconfigSrv_{private_node_handle}, interface_{private_node_handle} {

        /**
         * Initialization
         */
        interface_.fromParamServer();

        /**
         * Set up timer and dynamic reconfigure server
         */
        timer_ = private_node_handle.createTimer(ros::Duration(1. / interface_.rate), &Demo::timerCallback, this);
        reconfigSrv_.setCallback(boost::bind(&Demo::reconfigureRequest, this, _1, _2));
    }

/*
 * Use const ConstPtr for your callbacks.
 * The 'const' assures that you can not edit incoming messages.
 * The Ptr type guarantees zero copy transportation within nodelets.
 */
    void Demo::timerCallback(const ros::TimerEvent& event) {
        ROS_INFO_STREAM("Timer callback.  Enum: " << interface_.my_enum);
    }

/**
  * This callback is called whenever a change was made in the dynamic_reconfigure window
*/
    void Demo::reconfigureRequest(DemoConfig& config, uint32_t level) {
        interface_.fromConfig(config);
        timer_.setPeriod(ros::Duration(1. / interface_.rate));
        ROS_WARN_STREAM("Parameter update:\n" << interface_);
    }

} // namespace rosinterface_handler_tutorial


