#include "ros/ros.h"
#include "std_msgs/Float64.h"

#include <math.h>

float X;
float Y = 0;

void joint4angleCallback(const std_msgs::Float64 msg)
{
        X = msg.data;
        if (X > Y)
        {
			ROS_INFO("X: %f", X);
        }else{
			ROS_INFO("The number should be larger than previous!!!");
		}
        Y = X;
//according to task if we publish number less that previous one,
//it should give us alert
// and should publish only if the new value is larger that previous!

//ROS_INFO("  ");

}

int main(int argc, char **argv){
ros::init(argc, argv, "testing");
X = 0;
ros::NodeHandle nh;

ros::Publisher pub3 = nh.advertise<std_msgs::Float64>("/robot/joint4_position_controller/command", 10);
ros::Subscriber sub = nh.subscribe("/robot/joint4_position_controller/command", 10, joint4angleCallback);

// /robot/joint4_position_controller/command

// /joint4/command


// the topic was changed manually between base and end-effector
// base is /robot/joint1_position_controller/command
// end-effector is /robot/joint5_position_controller/command

ros::Rate loop_rate(1);

ros::Time startTime = ros::Time::now();

        while (ros::ok()) {
			
                  std_msgs::Float64 msg_to_send;
                  msg_to_send.data = X;
                  pub3.publish(msg_to_send);
                  ROS_INFO("Moving joint 4");
                  ros::spinOnce();
                  loop_rate.sleep();
       }
       return 0;
}
