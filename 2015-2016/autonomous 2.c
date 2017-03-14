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



//Use code below for accurate position control!!
// 627.2 ticks per revolution of the output shaft w/unmodified 393

 //Resets the motor encoder using the nMotorEncoder command
 nMotorEncoder(port1) = 0;

 //While the encoder for the motor on port 1 is less than 1000
 while(nMotorEncoder(port1) < 1000)
 {
  //Move the robot forward
  motor[port1] = 50;
  motor[port10] = 50;
 }

 //Stop the motors
 motor[port1]  = 0;
 motor[port10] = 0;
