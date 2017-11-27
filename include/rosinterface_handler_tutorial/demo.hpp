//
// Created by kevin on 11/27/17.
//

#ifndef ROSINTERFACE_HANDLER_TUTORIAL_DEMO_HPP
#define ROSINTERFACE_HANDLER_TUTORIAL_DEMO_HPP

#include <dynamic_reconfigure/server.h>
#include <ros/ros.h>
#include "rosinterface_handler_tutorial/DemoInterface.h"

namespace rosinterface_handler_tutorial {

    class Demo {
    public:
        Demo(ros::NodeHandle, ros::NodeHandle);

    private:
        DemoInterface interface_;

        ros::Timer timer_;
        dynamic_reconfigure::Server<DemoConfig> reconfigSrv_; // Dynamic reconfiguration service

        void timerCallback(const ros::TimerEvent& event);
        void reconfigureRequest(DemoConfig&, uint32_t);
    };

} // namespace rosinterface_handler_tutorial

#endif //ROSINTERFACE_HANDLER_TUTORIAL_DEMO_HPP
