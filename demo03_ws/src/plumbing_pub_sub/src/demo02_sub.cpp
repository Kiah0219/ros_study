#include "ros/ros.h"
#include "std_msgs/String.h"

/**订阅方实现：
 * 1.头文件
 * 2.初始化ros节点
 * 3.创建节点句柄
 * 4.创建订阅者对象
 * 5.处理订阅数据
 * 6.生命一个spin（）
*/

void doMsg(const std_msgs::String::ConstPtr &msg)
{
    //通过msg获取并操作订阅到的数据
    ROS_INFO("翠花订阅到的数据是%s",msg->data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //  2.初始化ros节点
    ros::init(argc,argv,"cuihua");
    //  3.创建节点句柄
    ros::NodeHandle nh;
    //  4.创建订阅者对象
    ros::Subscriber sub = nh.subscribe("fangzi",10,doMsg);
    //  5.处理订阅数据

    ros::spin();
    return 0;
}
