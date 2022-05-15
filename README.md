# KTH-C-lego-robot
A robot program written in C using the ROBOTC API for a KTH course

## The asignment
The asignment in the course is to use the LEGO EV3 Mindstorms kit to build a robot programmed in C which can carry an item and drop it off at a specific spot. The item in our case was the coursebook for that course. The exact tasks that the robot needs to do are:
1. Drop off the book 5 meters to the left.
2. Drop off the book 5 meters to the right.
3. Drop off the book 5 meters to the left, on the other side of the room.
4. Drop off the book 5 meters to the right, on the other side of the room.

The robot should then return to its starting position.

Lastly there is a caveat, the robot could be facing any direction and at slightly varying distances from the wall along which it should travel and place the item.

### Our program
This program tries to use what I'd call 'readability through abstraction', instead of manipulating our robot and it's parts in our .c file, we create tasks to solve our 4 problems which only call functions to control the robot. This adds a layer of abstraction and allows us to easily modify our tasks or even create new ones using the functions we already have. We add another layer of abstraction by moving these functions into seperate .h header files. This way our files don't get overly long or complicated.  

All the different functions, their use, parameters and so on are explained through comments in the files.
