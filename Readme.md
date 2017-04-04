ROS Beginner Tutorials 

## Overview

-  The tutorials were followed from: http://wiki.ros.org/ROS/Tutorials. 

 
- Create the catkin workspace and build with:
```
- mkdir catkin_ws
- cd catkin_ws
- mkdir src
- catkin_make
- cd src
- add source files 
```

## How to Run
- Open a terminal and run: ```roscore```

## Run publisher node:
- Open another terminal:
```
cd ~catkin_ws/src
source beginner_tutorials/devel/setup.bash
rosrun beginner_tutorials talker

## Launching all nodes in parallel
-  Instead of launching each node individually, you can launch all nodes by typing:
-  roslaunch src/beginner_tutorials/launch/tutorial.launch

## How to change the frequency of the talker node
- The default behavior is for the talker node to run at 10hz,change it by going to a differnt terminal windwow and type:
- roslaunch src/beginner_tutorials/launch/tutorial.launch frequency:=1

## Changing the default message
- The default behavior for the talker node is to print FEAR THE TURTLE. This can be changed by typing
- rosservice call /change_output "up"
 

## Dependencies
- ROS Indigo
- catkin
- roscpp package
- std_msgs package
