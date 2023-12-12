#include "ros/ros.h"


int main(int argc, char  *argv[])
{
    /* code */
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello");

    ROS_INFO("HELLO,你好");

    return 0;
}
