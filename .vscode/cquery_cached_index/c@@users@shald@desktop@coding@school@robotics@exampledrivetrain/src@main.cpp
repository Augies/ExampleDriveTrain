/*
 * @author Augies
 * This is an example program demonstrating how a drive Train
 * can be made in Vex PROS for tank mode
 */


#include "../include/main.h"

/**
 * Initializing the motors and Controller.
 * THESE MUST BE WRITTEN IN LINES BEFORE ANY FUNCTIONS
 * This tells the cortex these exist, and what ports they are in
 */
 pros::Controller controller(CONTROLLER_MASTER);
 pros::Motor DriveTrainL(1); //Left motor in port 1
 pros::Motor DriveTrainR(2, true); //Right motor in port 2, and reversed
 //Reverse R because R and L are facing opposite directions.

/**
 * Controls use of the Drive Train for the bot.
 * Uses the left stick to control left motor's velocity,
 * And right stick for right motor's velocity
 * Check ./include/main.h for more info
 */
void setDriveTrain(int velocityL, int velocityR){
	DriveTrainL.move_velocity(velocityL);
	DriveTrainR.move_velocity(velocityR);
}

void initialize() {}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
  //Put in forever loop because as long as bot is in opcontrol, we want it to be able to drive.
  //Avoid putting Forever loops within forever loops. write a function as if it is being called once
  while(true){
    //Runs the function setDriveTrain and passes in the y positions of both joystickcs
  	setDriveTrain(
  		controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y),
  		controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)
  	);
  }
}
