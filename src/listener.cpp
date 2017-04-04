/**
 *  @file      listener.cpp
 *  @brief     Node implementation for Listerner
 *  @author    Lamar Simpson  
 * Copyright    2017 
 * MIT LICENSE
 */


#include "ros/ros.h"
#include "std_msgs/String.h"

//handles messages for the chatter topic 
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "listener");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

    ros::spin();

    return 0;
}
