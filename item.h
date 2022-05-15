//All functions related to the carried item are found in this file

//DropItem takes in a speed and time value
//Speed is simply the speed the engines turn
//Time is how long we should move which depends on what item we are carrying
//For the book used in our assignment 15000ms works best
void DropItem(int speed, int time)
{
	//Start the engine moving the item off the platform
	setMotorSpeed(motorB, -speed);

	//Wait for motor movement
	sleep(time);

	//Stop the engine
	setMotorSpeed(motorB, 0);

	//Start moving back to starting position
	setMotorSpeed(motorB, speed);

	//Wait for motor movement
	sleep(time);

	//Stop the engine
	setMotorSpeed(motorB, 0);
}
