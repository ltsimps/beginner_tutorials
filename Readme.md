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
```
- Open another terminal:
- cd ~catkin_ws/src
- source beginner_tutorials/devel/setup.bash
- rosrun beginner_tutorials talker
```
## Launching all nodes in parallel

```
-  Instead of launching each node individually, you can launch all nodes by typing:
-  roslaunch src/beginner_tutorials/launch/tutorial.launch

```
## How to change the frequency of the talker node
```
- The default behavior is for the talker node to run at 10hz,change it by going to a differnt terminal windwow and type:
- roslaunch src/beginner_tutorials/launch/tutorial.launch frequency:=1
```
## Changing the default message
```
- The default behavior for the talker node is to print FEAR THE TURTLE. This can be changed by typing
- rosservice call /change_output "up"


```
## Running a ROS Transform
The ROS TF transform is broadcast relative to the world frame using 'world', 'talk'. Roscore must be  already running, see above commands. With roscore running enter the command below.
```
- rosrun tf tf_echo  world talk
```

#Result from running the ROS Transform
![Alt text](./tf.png?raw=true "Transform Output")




## Recording with Rosbag

To record and and playback ROS messages you need to use the rosbag package. This can be activated by setting a flag for the
tutorial.launch XML file. Enter the command below to record messages. This command can also be ran with frequency if you seperate the arguments using spaces.

```
- roslaunch beginner_tutorials tutorials.launch record:=true
- roslaunch beginner_tutorials tutorials.launch  frequency:= 1 record:=true
```


# To play back the bagfile and then run the bag file
Usually this fille is saved in ~/.ros directory. After finding this file  run the command below

```
- rosbag play tutorial.bag
```

## Dependencies
Below are the dependencies for the project included in the CMake file.

```
- ROS Indigo
- catkin
- roscpp package
- std_msgs package
- rostest
- tf
```
