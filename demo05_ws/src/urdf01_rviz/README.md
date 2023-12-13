# 在rviz中显示urdf模型

## 一、主要实现步骤
在rviz中显示机器人：
1. urdf文件文件编写
   - robot 根标签

   - link 连杆标签
     - visual ---> 描述外观(对应的数据是可视的)
       - geometry 设置连杆的形状
       - origin 设置偏移量与倾斜弧度
       - metrial 设置材料属性(颜色)
     - collision ---> 连杆的碰撞属性
     - Inertial ---> 连杆的惯性矩阵
   - joint 关节标签
     - parent(必需的)
     - child(必需的)
     - origin
     - axis
  [详细阅读](http://www.autolabor.com.cn/book/ROSTutorials/di-6-zhang-ji-qi-ren-xi-tong-fang-zhen/62-fang-zhen-urdf-ji-cheng-rviz/625-urdfyu-fa-xiang-jie-03-joint.html)
2. launch文件编写
   - 将urdf文件传入`robot_description`
   - 启动rviz


## 二、launch文件参数解释
### `robot_description`
1. `robot_description`是一个`ROS`参数，通常用于存储机器人的描述信息，比如URDF（Unified Robot Description Format）文件的内容。在ROS系统中，`robot_description`参数通常被用于传递机器人的几何形状、连接关系、关节信息等描述，以便在运行时被其他ROS节点使用。
2. 在使用机器人模拟、控制或感知方面的ROS应用中，`robot_description`参数常常被用于以下几个方面：
- **机器人状态发布**： 通过使用`robot_state_publisher`节点，将机器人的状态（由`URDF`描述）发布到`ROS`中，使得其他节点可以获取机器人的状态信息。
- **运动规划**：机器人的几何描述对于运动规划是至关重要的。在运动规划中，机器人的几何形状和连接关系帮助规划器理解机器人的空间结构，从而生成有效的运动轨迹。
- **`RViz`可视化**：在`RViz`中可视化机器人模型时，`robot_description`参数用于提供机器人的`URDF`描述，以便`RViz`可以正确地显示机器人的外观和结构。
- **仿真环境中的模型加载**：在仿真环境（比如`Gazebo`）中，`robot_description` 也经常被用于加载机器人模型。


## 三、launch文件实现
在启动文件（launch file）中，可以使用`robot_state_publisher`节点或其他相关节点，将 URDF文件的内容加载到`robot_description`参数中，以便在整个ROS系统中共享和使用。例如：
```xml
<node name="robot_state_publisher" pkg="robot_state_publisher" type="robot_state_publisher">
  <param name="robot_description" command="$(find xacro)/xacro --inorder '$(find my_robot_description_package)/urdf/my_robot.urdf.xacro'" />
</node>
```
其中`robot_state_publisher`节点通过`param`标签将`URDF`文件的内容加载到`robot_description`参数中。



