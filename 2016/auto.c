task autonomous()
{

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

}
