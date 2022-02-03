#include "vex.h"
 
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                   
// ---- END VEXCODE CONFIGURED DEVICES ----
 
using namespace vex;
//naming variables or parts of robot
//always start with vex::motor  Motor2 = vex::motor( vex::PORT2, true);
//always start with vex::controller  MyController = vex::controller();
vex::brain        Brain;
vex::competition  Competition;
vex::motor        RightFrontMotor = vex::motor( vex::PORT1);
vex::motor        LeftFrontMotor  = vex::motor( vex::PORT2, true);
vex::motor        RightBackMotor = vex::motor( vex::PORT3);
vex::motor        LeftBackMotor = vex::motor( vex::PORT4);
vex::motor        ArmLiftMotor = vex::motor(vex::PORT5);
vex::controller   Controller1 = vex::controller();

//JugalOnlyFans
 
void usercontrol (void)
{
//user control code here, inside the loop:
int ArmSpeed = 100;
 
 while(1)
 {
   //This is the main execution loop for the user control program.
   //Each time through the loop, your program should update motor + servo.
   //Values based on feedback from the joysticks.
 
   //******************************************************************
   //Insert user code here. This is where you use the joystick values to
   //update your motors, etc.
   //******************************************************************
   //this is where I tell it to do stuff based on analog sticks.
   //Drive Program
   //on the vex controller, (left side motor) Axis3 is front and back, Axis4 is left and right
   //on the vex controller, (right side motor) Axis2 is front and back, Axis1 is left and right
   RightFrontMotor.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
   LeftFrontMotor.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
   RightFrontMotor.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
   LeftFrontMotor.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
   vex::task::sleep(20); //sleep the task for a short amount of time to prevent wasted resources.
 
   //Arm Control Program
   if(Controller1.ButtonR1.pressing())
   {
     ArmLiftMotor.spin(vex::directionType::fwd, ArmSpeed, vex::velocityUnits::pct); 
   }
   else if(Controller1.ButtonR2.pressing())
   {
     ArmLiftMotor.spin(vex::directionType::rev, ArmSpeed, vex::velocityUnits::pct);
   }
   else
   {
     ArmLiftMotor.stop(vex::brakeType::brake);
   }
  
 
 }
}
 
 
 
//RightFrontMotor.spin(vex::dirrectionType);
 
 
 
int main() {
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
 
 }
 

