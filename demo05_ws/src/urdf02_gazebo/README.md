# 在gazebo中显示urdf模型

## launch步骤
1. 将Urdf文件的内容加载到参数服务器`robot_description`
2. 打开gazebo一个空白世界
3. 将`robot_description`加载到gazeo中


## urdf文件
1. **`link`标签需要添加**：`collision`连杆的碰撞属性、`Inertial`连杆的惯性矩阵
2. **`robot` 标签下要添加**`gazebo`标签
3. **添加物理属性**，能够实现传感器的调用，将传感器贴在各个`link`上，方便在gazebo中使用在*urdf/gazebo/xxx.xacro*
   - `robot`下的`gazebo`添加`sensor`和`传感器`和`plugin`
4. **`transmission`标签**用于定义机器人的传动系统。传动系统描述了关节的运动如何通过传动机构传递到其他部件，例如电机、减速器等。这对于在仿真中模拟机器人的运动以及在实际硬件中实现控制非常重要。设置`jiont`相关参数，主要为电机。
   - *urdf/gazebo/move.xacro*

## 其他
- 发布话题数据：`rostopic pub -r10 /cmd_vel tab补齐` 
- 键盘控制节点：`rosrun teleop_twist_keyboard teleop_twist_keyboard.py`