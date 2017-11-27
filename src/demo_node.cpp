//
// Created by kevin on 11/27/17.
//

#include "rosinterface_handler_tutorial/demo.hpp"

int main(int argc, char* argv[]) {

    ros::init(argc, argv, "demo_node");

    rosinterface_handler_tutorial::Demo demo(ros::NodeHandle(), ros::NodeHandle("~"));

    ros::spin();
    return 0;
}

