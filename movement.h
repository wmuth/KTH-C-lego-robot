//All functions related to the robots movement are found in this file

//Turn takes in the direction to turn as a long value
//The gyro counts upwards when turning right and downwards when turning left
//This means Turn(90, x) will turn right and Turn(-90, x) will turn left
void Turn(long turnDegree, int speed)
{
	//If our turn value is less than 0, we are turning left
	if(turnDegree < 0)
	{
		//Reset gyro since the input degree value is relative to current position
		resetGyro(S2);

		//Due to innacuracies in the gyro this creates more accurate turns
		turnDegree += 5;

		//Start engine to begin movement
		setMotorSpeed(motorA, -speed);
		setMotorSpeed(motorC, speed);

		waitUntil(turnDegree >= getGyroDegrees(S2));

		//Stop engines after movement
		setMotorSpeed(motorA, 0);
		setMotorSpeed(motorC, 0);
	}

	//Otherwise we are turning right
	else
	{
		//Reset gyro since the input degree value is relative to current position
		resetGyro(S2);

		//Due to innacuracies in the gyro this creates more accurate turns
		turnDegree -= 5;

		//Start engine to begin movement
		setMotorSpeed(motorA, speed);
		setMotorSpeed(motorC, -speed);

		waitUntil(turnDegree <= getGyroDegrees(S2));

		//Stop engines after movement
		setMotorSpeed(motorA, 0);
		setMotorSpeed(motorC, 0);
	}
}

//Drive takes in the direction to drive as a char array - forwards or backwards
//Checks if it is forwards then proceeds with the code for the correct direction

//Distance to drive is included as a a float measured in centimeters
//This value is then multiplied by the time it takes for the robot to move one cenimeter
//Giving us the amount of time it has to move in the specified direction

//Speed is declared and initialized on its own to facilitate easy calibration
void Drive(string *direction, float distance)
{
	//Hardcoded varibles for movement of 1 meter which are then
	//multiplied to move the full distance
	float time = 1500;
	int speed = 30;
	time = (distance/100)*time;

	if(*direction == "Forward")
	{
		//Start engines to begin movement
		setMotorSpeed(motorA, speed);
		setMotorSpeed(motorC, speed);

		//Wait for robot to travel
		sleep(time);

		//Stop engines after movement
		setMotorSpeed(motorA, 0);
		setMotorSpeed(motorC, 0);
	}

	else
	{
		//Start engines to begin movement
		setMotorSpeed(motorA, -speed);
		setMotorSpeed(motorC, -speed);

		//Wait for robot to travel
		sleep(time);

		//Stop engines after movement
		setMotorSpeed(motorA, 0);
		setMotorSpeed(motorC, 0);
	}
}

//Go is our function for moving towards or away from things
//For this assignment it is used to get close enough to the wall that we can
//drop off our item in the designated area

//We call go giving it a command either Toward Or Away, the distance we want
//to end up at and the speed we want to move towards or away
void Go(string *direction, float targetDistance, int speed)
{
	//Move toward the obstacle in front
	if(*direction == "Toward")
	{
		//Start moving
		setMotorSpeed(motorA, speed);
		setMotorSpeed(motorC, speed);

		//Keep moving until distance is acceptable given input distance
		waitUntil(targetDistance >= getUSDistance(S1));

		//Stop moving
		setMotorSpeed(motorA, 0);
		setMotorSpeed(motorC, 0);
	}

	//Or move away from the obstacle
	else
	{
		//Start moving
		setMotorSpeed(motorA, -speed);
		setMotorSpeed(motorC, -speed);

		//Keep moving until distance is acceptable given input distance
		waitUntil(targetDistance <= getUSDistance(S1));

		//Stop moving
		setMotorSpeed(motorA, 0);
		setMotorSpeed(motorC, 0);
	}
}
