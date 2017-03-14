#pragma config(Motor,  port1,           motorY1,       tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           motorX2,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           launch1,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           launch2,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           launch3,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           launch4,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           motorY2,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           motorX1,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          feed,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}


task autonomous()
{
}


task usercontrol()
{
	while (true)
	{
		//Holo Drive (simple)
		motor[motorY1] = (vexRT[Ch3] - vexRT[Ch1]);
		motor[motorY2] = (vexRT[Ch3] + vexRT[Ch1]);
		motor[motorX1] = (vexRT[Ch4] - vexRT[Ch1]);
		motor[motorX2] = (vexRT[Ch4] + vexRT[Ch1]);

		//feed control
		if (vexRT[Btn6U] == 1){
			motor[feed] = 127;
		}
		else if (vexRT[Btn6D] == 1) {
			motor[feed] = -127;
		}
		else {
			motor[feed] = 0;
		}

		//launch control
		if (vexRT[Btn8U] == 1){
			motor[launch1] = 0;
			motor[launch2] = 0;
			motor[launch3] = 0;
			motor[launch4] = 0;
		}
		if (vexRT[Btn8D] == 1)
		{
			motor[launch1] = 40;
			motor[launch2] = 40;
			motor[launch3] = 40;
			motor[launch4] = 40;
		}
		if (vexRT[Btn8L] == 1)
		{
			motor[launch1] = 80;
			motor[launch2] = 80;
			motor[launch3] = 80;
			motor[launch4] = 80;
		}
		if (vexRT[Btn8R] == 1)
		{
			motor[launch1] = 127;
			motor[launch2] = 127;
			motor[launch3] = 127;
			motor[launch4] = 127;
		}
	}
}
