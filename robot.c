//Robot main program
//Main motors are ports A and C
//Motor to manipulate the item is port B
//Ultrasonic sensor is port S1
//Gyro is port S2

//Include our own header files with the functions we will use later
#include "movement.h"
#include "autoOrientSelf.h"
#include "item.h"

//Declare tasks for later defining after main, allowing main to be first in the file
task DropLeft();
task DropRight();
task DropOtherSideLeft();
task DropOtherSideRight();

//Loop waiting for button presses and when pressed start the correct task
task main()
{
	while(true)
	{
		if(getButtonPress(buttonLeft))
		{
			sleep(2000);
			startTask(DropLeft);
		}
		else if(getButtonPress(buttonUp))
		{
			sleep(2000);
			startTask(DropRight);
		}
		else if(getButtonPress(buttonRight))
		{
			sleep(2000);
			startTask(DropOtherSideLeft);
		}
		else if(getButtonPress(buttonDown))
		{
			sleep(2000);
			startTask(DropOtherSideRight);
		}
		else if(getButtonPress(buttonEnter))
		{
			break;
		}
	}
}

//Drops off book on the left side
task DropLeft()
{
	//Get us from our random starting point to our default indended one
	AutoOrientSelf();

	//Go to item drop off location
	Turn(-90, 25);
	Drive("Forward", 250);
	Turn(90, 25);

	//Drop off carried item
	Go("Toward", 20, 25);
	DropItem(10, 1500);
	Go("Away", 50, 25);

	//Go back to starting location
	Turn(-90, 25);
	Drive("Backward", 250);
	Turn(90, 25);
}

//Drops off book on the right side
task DropRight()
{
	//Get us from our random starting point to our default indended one
	AutoOrientSelf();

	//Go to item drop off location
	Turn(90, 25);
	Drive("Forward", 250);
	Turn(-90, 25);

	//Drop off carried item
	Go("Toward", 20, 25);
	DropItem(10, 1500);
	Go("Away", 50, 25);

	//Go back to starting location
	Turn(90, 25);
	Drive("Backward", 250);
	Turn(-90, 25);
}

//Drops off book on the left side at the other wall
task DropOtherSideLeft()
{
	//Get us from our random starting point to our default indended one
	AutoOrientSelf();

	//Go to correct distance, wrong wall
	Turn(-90, 25);
	Drive("Forward", 250);

	//Turn to other wall
	Turn(-90, 25);

	//Drop off carried item
	Go("Toward", 20, 25);
	DropItem(20, 1500);

	//Go back to starting location
	Turn(180, 250);
	Go("Toward", 50, 25);

	Turn(90, 25);

	Drive("Forward", 250);
	Turn(-90, 25);
}

//Drops off book on the right side at the other wall
task DropOtherSideRight()
{
	//Get us from our random starting point to our default indended one
	AutoOrientSelf();

	//Go to correct distance, wrong wall
	Turn(90, 25);
	Drive("Forward", 250);

	//Turn to other wall
	Turn(90, 25);

	//Drop off carried item
	Go("Toward", 20, 25);
	DropItem(20, 1500);

	//Go back to starting location
	Turn(-180, 25);
	Go("Toward", 50, 25);

	Turn(-90, 25);

	Drive("Forward", 250);
	Turn(90, 25);
}
