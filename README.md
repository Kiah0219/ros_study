# ros_study
code for ros study about autolabor ROS Robotics Tutorial

## Requirements for the environment
* ubuntu20.04
* ros-noetic
* use vscode edit code

## Notice
* you may need to install other software such as g++/gcc
* each demo folder is a ros workspace，in order to make it easier for some people to use this repository directly there are not delete devel and build folders，however in practice you may need to delete the devel and build folders and catkin_make again

## Detailed description
### demo02
* Use a simple roslaunch file to run multiple nodes eliminating the need to use multiple rosrun commands
* Usage：
* open workspace folder and `catkin_make`
* then `roslaunch demo02 stat_turtle.launch`
### demo03_ws
* This demo is about the ros communication mechanism including topic communication service communication and parameter server
### demo04_ws
* Ros communication mechanism advanced，rosbag、rosnamespace、distributed communication
### demo05_ws
* Display robot URDF models in rviz
* Displayed The URDF car model in Gazebo
* Implement navigation module
### demo06_ws
* action communication、dynamic parameters、plugin mechanism

## References
1. http://www.autolabor.com.cn/book/ROSTutorials/index.html
2. https://www.bilibili.com/video/BV1Ci4y1L7ZZ/



