//#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
// Main moveit libraries are included
int main(int argc, char **argv)
{
 ros::init(argc, argv, "move_group_interface_tutorial");
 ros::NodeHandle node_handle;
 ros::AsyncSpinner spinner(0);
 spinner.start(); // For moveit implementation we need AsyncSpinner, we cant use ros::spinOnce()
 static const std::string PLANNING_GROUP = "arm"; /* Now we
specify with what group we want work,
 here group1 is the name of my group controller*/
 moveit::planning_interface::MoveGroupInterface
move_group(PLANNING_GROUP); // loading move_group
 const robot_state::JointModelGroup *joint_model_group =
 move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP); //For joint control
 geometry_msgs::PoseStamped current_pose;
 geometry_msgs::PoseStamped target_pose; // Pose in ROS is implemented using geometry_msgs::PoseStamped, google what is the type of this msg
 current_pose = move_group.getCurrentPose(); /* Retrieving the
information about the
 current position and orientation of the end effector*/
 target_pose = current_pose;
 
 // lab4 2nd part, so below is how arm is moving by 1.4 in x-axis direction
		//target_pose.pose.position.x = target_pose.pose.position.x - 1.4;
 // end of lab4 2nd part
 
 /* Basically
our target pose is the same as current,
 except that we want to move it a little bit along x-axis*/

 ros::Rate loop_rate(50); //Frequency
 
 float i = 0; // this is all for 2 cases (for circle and rectangle)
 while (ros::ok()){


	//this is for rectangle (lab4 3rd part)
        
        if(i == 0){
			target_pose.pose.position.x = target_pose.pose.position.x - 1.4;
		}else if(i == 2){
			target_pose.pose.position.y = target_pose.pose.position.y - 0.5;
		}else if(i == 4){
			target_pose.pose.position.x = target_pose.pose.position.x + 1.4;
		}else if(i == 6){
			target_pose.pose.position.y = target_pose.pose.position.y + 0.5;
		}
		
        i += 0.5;
 
		if(i == 20) {
			break;
		}
        // end of lab4 3rd part
		

	/* this is for circle (lab4 4th part)
        target_pose.pose.position.x = 2.5+0.4*cos(i);
		target_pose.pose.position.y = 0.4*sin(i);

            move_group.setApproximateJointValueTarget(target_pose); // To calculate the trajectory
            move_group.move(); // Move the robot
            
        current_pose = move_group.getCurrentPose();
        i += 0.5;
        
         if(i == 200) {
			break;
		}
        // end of lab4 4th part
        */ 
        
        
        

            move_group.setApproximateJointValueTarget(target_pose); // To calculate the trajectory
            move_group.move(); // Move the robot
            
        current_pose = move_group.getCurrentPose();
        
 /*
 if (abs(current_pose.pose.position.x - target_pose.pose.position.x) < 0.01)
{
 break; // Basically, check if we reached the desired position
 }
 * */
 
 loop_rate.sleep();
 }
 ROS_INFO("Done");
 ros::shutdown();
 return 0;
}
