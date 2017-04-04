/**
 *  @file      talker.cpp
 *  @brief     Node implementation for the publisher
 *  @author    Lamar Simpson  (https://github.com/ltsimps/beginner_tutorials) 
 *  MIT License
 *  Copyright 2017 
 */

#include <sstream>
#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/strings.h"

//std::stringstream change_output(std::string output){
//} 

std::string newMessage = "FEAR THE TURTLE";


 bool change_output(beginner_tutorials::stringsRequest &req,
                    beginner_tutorials::stringsResponse &resp) {
  
  ROS_WARN_STREAM("Now changing output to " << req.input);

  if(req.input ==""){
  ROS_ERROR_STREAM("There is no string value that you input ");
  return false;
  }else {
    resp.output = req.input;
    newMessage  = req.input;
  }
  //return  req.output;
  return true;
}


int main(int argc, char **argv) {
    ROS_DEBUG_STREAM("Initializing talker node ");

    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    
    //service to change string output that launches in xterm window 
    ros::ServiceServer service = n.advertiseService("change_output", change_output);
    
    //subscription for listener
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

   int frequency = 0;  
    // If argument is passed in change the frequency 
    if (argc > 1) {
     ROS_DEBUG_STREAM("argument passed in " << argv[1]);
     frequency = atoi(argv[1]);
     
     if (frequency <=0){
      ROS_FATAL_STREAM("Incorrect input for frequency ");
      ROS_WARN_STREAM("Setting value to default hertz value of to ");
      frequency = 10;
     }
    }else{
    
    //set to default valueof 10hz
     frequency = 10;
    }

   
    // Sets 
    ros::Rate loop_rate(frequency);

    int count = 0;
    while (ros::ok()) {

        std_msgs::String msg;
        std::stringstream ss;
        ss << newMessage <<" "  << count;
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



