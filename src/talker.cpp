/**
 *  @file      talker.cpp
 *  @brief     Node implementation for the publisher
 *  @author    Lamar Simpson  (https://github.com/ltsimps/beginner_tutorials) 
 *  MIT License
 *  Copyright 2017 
 */

#include <sstream>

#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    // Sets a rate of 10 Hz
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok()) {

        std_msgs::String msg;
        std::stringstream ss;
        ss << " FEAR the turtle " << count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        //publishes the messages to be consumed.
        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();

        ++count;
    }

    return 0;
}



