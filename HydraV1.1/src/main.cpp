/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// leftfront            motor         1               
// leftback             motor         2               
// rightfront           motor         3               
// rightback            motor         4               
// forklift             motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {

  leftfront.setVelocity(30 , percent);
  leftback.setVelocity(30 , percent);
  rightfront.setVelocity(30 , percent);
  rightback.setVelocity(30 , percent);

  leftfront.startRotateFor(vex::directionType::fwd , 750, vex::rotationUnits::deg);
  leftback.startRotateFor(vex::directionType::fwd , 750, vex::rotationUnits::deg);
  leftfront.startRotateFor(vex::directionType::fwd , 750, vex::rotationUnits::deg);
  leftfront.startRotateFor(vex::directionType::fwd , 750, vex::rotationUnits::deg);

  //turn left pivot 

  leftfront.startRotateFor(vex::directionType::rev ,90 ,vex::rotationUnits::deg);
  leftback.startRotateFor(vex::directionType::rev ,90 ,vex::rotationUnits::deg);
  rightfront.startRotateFor(vex::directionType::fwd ,90 ,vex::rotationUnits::deg);
  rightback.rotateFor(vex::directionType::fwd ,90 ,vex::rotationUnits::deg);

 // move goal into claw 

  leftfront.setVelocity(30 , percent);
  leftback.setVelocity(30 , percent);
  rightfront.setVelocity(30 , percent);
  rightback.setVelocity(30 , percent);

  leftfront.startRotateFor(vex::directionType::fwd , 100, vex::rotationUnits::deg);
  leftback.startRotateFor(vex::directionType::fwd , 100, vex::rotationUnits::deg);
  leftfront.startRotateFor(vex::directionType::fwd , 100, vex::rotationUnits::deg);
  leftfront.startRotateFor(vex::directionType::fwd , 100, vex::rotationUnits::deg);

  // lift goal 


  forklift.spinFor(vex::directionType::fwd ,90 ,vex::rotationUnits::deg);

  vex::task::sleep(2000); //pauses 

}


//Autnonomous Notes 

// motor.startRotateFor() :
// Prepares The morotr to rotate along with other motors
// Doesnt Move the Motor!!

// motor.rotateFor() :
// Rotates a motor along with other others
// Does move the motor

// Parameters:
// x = direction 
// y = distance(degrees)
// z = degrees

// Drive fwd/rev example code 

//leftfront.startRotateFor(vex::directionType::fwd ,100 ,vex::rotationUnits::deg);
//leftback.startRotateFor(vex::directionType::fwd ,100 ,vex::rotationUnits::deg);
//rightfront.startRotateFor(vex::directionType::fwd ,100 ,vex::rotationUnits::deg);
//rightback.startRotateFor(vex::directionType::fwd ,100 ,vex::rotationUnits::deg);

// motor.setVelocity(); :
// This sets the speed of the motor while runs
//This command is placed before the rotate commands

// motor.setVelcity(value , percent); : 
// In the parenthesis, we put waht speed we want (out of 100% which is the motor's maximum speed) in the value slot , such as 80
// Then followed by the word "precent" to define the value type
// If value is not set , the defualt value is 50% 

//Velocity Example Code 

// leftfront.setVelocity(80, percent);
// leftback.setVelocity(80, percent);
// rightfront.setVelocity(80, percent);
// leftback.setVelocity(80, percent);


// Types of Turns 

// Pivot: 
// Turn in place one side moves forward, the other moves in reverse
// Swing: 
// Wider Turn,one side moves while the other is stationary (no power)

// Types of turns Codin example
// 90 degree left turn (pivot);
// 90 degree left turn (swing); 

// leftfront.startRotateFor(vex::directionType::rev ,90 ,vex::rotationUnits::deg);
// leftback.startRotateFor(vex::directionType::rev ,90 ,vex::rotationUnits::deg);
// rightfront.startRotateFor(vex::directionType::fwd ,90 ,vex::rotationUnits::deg);
// rightback.rotateFor(vex::directionType::fwd ,90 ,vex::rotationUnits::deg);


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    leftfront.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
    leftback.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
    rightfront.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
    rightback.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);

  if (Controller1.ButtonL1.pressing())

  {
    forklift.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
  }

  else if(Controller1.ButtonR1.pressing())
  {
    forklift.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
  }
  else
  {
    forklift.stop(vex::brakeType::hold);
  } 



    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}




//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
