#include "ros/ros.h"

   /* 演示参数查询
        实现：
            ros::NodeHandle
                param(键,默认值) 
            存在，返回对应结果，否则返回默认值

            getParam(键,存储结果的变量)
                存在,返回 true,且将值赋值给参数2
                若果键不存在，那么返回值为 false，且不为参数2赋值

            getParamCached键,存储结果的变量)--提高变量获取效率
                存在,返回 true,且将值赋值给参数2
                若果键不存在，那么返回值为 false，且不为参数2赋值

            getParamNames(std::vector<std::string>)
                获取所有的键,并存储在参数 vector 中 

            hasParam(键)
                是否包含某个键，存在返回 true，否则返回 false

            searchParam(参数1，参数2)
                搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

        ros::param ----- 与 NodeHandle 类似
        
     */

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"get_param_c");
    ros::NodeHandle nh;
    //1、param
    double radius = nh.param("radius",0.5);
    ROS_INFO("radius = %.2f",radius);
    //2、getparam
    double radius_2 = 0.0;
    bool result = nh.getParam("radius11",radius_2);
    if(result) 
       { ROS_INFO("获取的半径是%.2f",radius_2);}
    else
      {  ROS_INFO("not found");}
    //3.getparamcached实现与getparam类似，只是地层性能有提升，一般测试结果不可见
    //4.getParamNames
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("遍历的元素：%s",name.c_str());
    }
    //hasparam
    bool flag = nh.hasParam("radius");
    ROS_INFO("flag:%d",flag);
    //searchparam
    std::string key;
    if( nh.searchParam("radius",key))
    {
        ROS_INFO("key:%s",key.c_str());
    }

    return 0;
}
