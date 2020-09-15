#include "ros/ros.h"
#include "std_msgs/Float64.h"


#include <math.h>

float X;

void joint4angleCallback(const std_msgs::Float64 msg)
{
        X = msg.data;
	ROS_INFO("X: %f", X);
        
//ROS_INFO("  ");

}

int main(int argc, char **argv){
ros::init(argc, argv, "testing");
X = 0;
ros::NodeHandle nh;

ros::Publisher pub3 = nh.advertise<std_msgs::Float64>("/robot/joint1_position_controller/command", 10);
ros::Subscriber sub = nh.subscribe("/robot/joint1_position_controller/command", 10, joint4angleCallback);

// /robot/joint4_position_controller/command

// /joint4/command

// the topic was changed manually between base and end-effector
// base is /robot/joint1_position_controller/command
// end-effector is /robot/joint5_position_controller/command

ros::Rate loop_rate(1);

ros::Time startTime = ros::Time::now();

float i = 0.0;  //again variables are intialized
float s;

        while (ros::ok()) {
			
			s = sin(i);
			if (s > 0){
				s = 1;
				
			}else{
				s = 0;
			}
                  std_msgs::Float64 msg_to_send;


                  msg_to_send.data = s;
                  pub3.publish(msg_to_send);
                  ROS_INFO("Moving joint 1");
				  i = i + 1;
                  ros::spinOnce();
                  loop_rate.sleep();
       }
       return 0;
}

