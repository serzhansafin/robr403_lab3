#include "ros/ros.h"
#include "std_msgs/Float64.h"

#include <math.h>

float X;
float Y;
float i = 0.0; //intialization

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

ros::Publisher pub3 = nh.advertise<std_msgs::Float64>("/robot/joint5_position_controller/command", 10);
ros::Subscriber sub = nh.subscribe("/robot/joint5_position_controller/command", 10, joint4angleCallback);

// the topic was changed manually between base and end-effector
// base is /robot/joint1_position_controller/command
// end-effector is /robot/joint5_position_controller/command

ros::Rate loop_rate(10);

ros::Time startTime = ros::Time::now();

        while (ros::ok()) {
			
				  Y = sin(i); //just the sine function itself

                  std_msgs::Float64 msg_to_send;
                  msg_to_send.data = Y; //copied to data
                  pub3.publish(msg_to_send); //and then published
                  ROS_INFO("Moving joint 1");
				  i = i + 0.1; //for the changing of sine function
                  ros::spinOnce();
                  loop_rate.sleep();
       }
       return 0;
}

