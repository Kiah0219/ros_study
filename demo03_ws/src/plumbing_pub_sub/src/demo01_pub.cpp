#include "ros/ros.h"
#include "std_msgs/String.h"//普通文本类型的消息
#include <sstream>

/**发布方实现：
 * 1.头文件
 * 2.初始化ros节点
 * 3.创建节点句柄
 * 4.创建发布者对象
 * 5.编写发布逻辑、发布数据
 * 
*/

int main(int argc, char *argv[])
{
    //初始化ros节点
    ros::init(argc, argv ,"ergouzi");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("fangzi",10);
    //编写发布逻辑、发布数据
    //要求以10hz发布出去，并且文本后加编号
    //创建被发布的消息
    std_msgs::String msg;
    ros::Rate rate(1);
    
    int count = 0;
    ros::Duration(3);
    //编写循环，循环中发布数据
    //ros::ok()：只要ROS节点处于运行状态，就会一直执行循环体中的代码。
    while (ros::ok())
    {
        setlocale(LC_ALL,"");
        count++;
        //msg.data = "hello";
        std::stringstream ss;
        ss<<"hello ===> "<< count;
        msg.data = ss.str();
        pub.publish(msg);
        ROS_INFO("发布的数据是%s",ss.str().c_str());
        rate.sleep();
        ros::spinOnce();//官方加以添加，处理回调函数
    }
    
   


    return 0;
}
