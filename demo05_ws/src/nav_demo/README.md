# 导航实现


## launch文件实现流程
- nav01_slam_test.launch
    - 文件一：
      - 将Urdf文件的内容加载到参数服务器`robot_description`
      - 打开gazebo导入世界
      - 倒入机器人模型
    - 文件二：
      - 设置参数use_sim_time为True
      - 启动gmapping节点
      - 发布机器人关节节点
      - 打开rviz
- nav02：map save
- nav02：map saver
- nav04test_amcl.launch
    - 文件一：
      - 将Urdf文件的内容加载到参数服务器`robot_description`
      - 打开gazebo导入世界
      - 倒入机器人模型
    - 步骤：
      - 发布机器人关节节点
      - 打开rviz
    - 文件二：加载地图服务
    - 文件三：打开amcl节点
- nav05_path:打开move_base路径规划节点
- nav06_test:完整导航流程



## 参数

> map:传感器定位
> odom：里程计定位
> base_link：机器人根坐标系
> map->odom->base_link或base_footprint 

发布话题数据：`rostopic pub -r10 /cmd_vel tab补齐` 
启动键盘控制节点：`rosrun teleop_twist_keyboard teleop_twist_keyboard.py`
