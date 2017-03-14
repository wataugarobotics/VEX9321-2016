#pragma config(Motor,  port1,           motorX1,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           motorY2,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           launch1,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           launch2,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           motorX2,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           motorY1,       tmotorVex393_MC29, openLoop, reversed)
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
}


task autonomous()
{
/*
	delay(500);
	motor[motorY1] = 127;
	motor[motorY2] = 127;
	motor[motorX1] = 127;
	motor[motorX2] = 127;
	delay(3500);
	motor[motorY1] = 127;
	motor[motorY2] = 127;
	motor[motorX1] = 0;
	motor[motorX2] = 0;
	delay(3500);
	motor[motorY1] = -127;
	motor[motorY2] = 127;
	motor[motorX1] = 127;
	motor[motorX2] = -127;
	delay(500);
	motor[motorY1] = 0;
	motor[motorY2] = 0;
	motor[motorX1] = 0;
	motor[motorX2] = 0;

	motor[launch1] = 127;
	motor[launch2] = 127;
	delay(4000);
	motor[launch1] = 0;
	motor[launch2] = 0;
*/
}


task usercontrol()
{
	while (true)
	{
		//Holo Drive (simple)
		motor[motorY1] = (vexRT[Ch3] - vexRT[Ch1]);
		motor[motorY2] = (vexRT[Ch3] + vexRT[Ch1]);
		motor[motorX1] = (vexRT[Ch4] + vexRT[Ch1]);
		motor[motorX2] = (vexRT[Ch4] - vexRT[Ch1]);

		//ramp control
		if (vexRT[Btn6U] == 1){
			motor[ramp] = 127;
		}
		else if (vexRT[Btn6D] == 1) {
			motor[ramp] = -127;
		}
		else {
			motor[ramp] = 0;
		}

		//launch control
		if (vexRT[Btn8U] == 1){
			motor[launch1] = 0;
			motor[launch2] = 0;
		}
		if (vexRT[Btn8D] == 1)
		{
			motor[launch1] = 127;
			motor[launch2] = 127;
		}
	}
}
