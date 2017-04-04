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



## Dependencies
- ROS Indigo
- catkin
- roscpp package
- std_msgs package
