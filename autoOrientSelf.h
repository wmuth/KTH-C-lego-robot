//Automatically turns the robot to face the wall

//In our asignment this function is used because our robot starts facing a random direction
//However it calls for our robot to move "Left" and "Right", so we need to orient ourselves
//and figure out which way is which

void AutoOrientSelf()
{
	//Declare and initialize variables
	//Two arrays to store the values we will collect
	//Two ints to keep track of our iterations since we are using
	//A repeatUntil() loop rather than a for loop
	float distance[59];
	long degree[59];
	int arrLen = 0;
	int i = 0;

	//Every step of int degree degrees we make one measurment,
	//save and reset the gyro to easily measure the next step
	resetGyro(S2);

	//First measure
	distance[i] = getUSDistance(S1);
	degree[i] = getGyroDegrees(S2);
	arrLen += 1;
	i += 1;
	sleep(90);
	
	//Start turning
	setMotorSpeed(motorA, 20);
	setMotorSpeed(motorC, -20);
	
	//Keep measuring until we have spun a complete 360 degrees
	repeatUntil(getGyroDegrees(S2) >= 360)
	{
		distance[i] = getUSDistance(S1);
		degree[i] = getGyroDegrees(S2);
		arrLen += 1;
		i += 1;

		sleep(90);
	}

	//Declare and initialize variables for our comparisons
	float smallest = distance[0];
	int index = 0;

	//Find the smallest value of the distance array
	//Remember the index of the smallest value
	for (int j = 0; j < arrLen; j += 1)
	{
		if (distance[j] < smallest)
		{
			smallest = distance[j];
			index = j;
		}
	}

	//Reset our gyro so we can use the recorded degree value
	//Also helps with gyro accuracy
	resetGyro(S2);

	//Turn until we get to the spot that had the shortest distance
	//Harcoded value -10 helps with the gyro innacuracy
	waitUntil(getGyroDegrees(S2) >= degree[index] - 10);

	//Stop turning
	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorC, 0);
}
