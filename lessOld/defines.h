/*
 * defines.h
 *
 *  Created on: Dec 25, 2013
 *      Author: nds
 */

#ifndef DEFINES_H_
#define DEFINES_H_

struct Ball {
	int xpos;//current coordinates of the ball
	int ypos;

	int direction;

	int xpos_old;//old positions to avoid screen refill
	int ypos_old;
};

struct Paddle {
	int position;
	int position_old;
};

struct Game {
	int speed;// speed variable
	int pause;//pause flag, can be 1 or 0
	int reset;//reset game flag
	int scoreLeft;//scores of left and right player
	int scoreRight;
};

#define PI 3.14159265 //pi
#define SPEED 3 //ball speed
#define INIT_XPOS 127 //ball start position
#define INIT_YPOS 95
#define INIT_DIRECTION 45 //ball starting direction in degrees
#define BALL_SIZE 2 //ball "radius"
#define PADDLE_THICK 5 //paddle thickness
#define PADDLE_WIDTH 48 //paddle width
#define PADDLE_SPEED 5 //paddle speed
#define RED ARGB16(1,31,0,0) //colour definitions
#define GREEN ARGB16(1,0,31,0) //(transparency,R,G,B)
#define BLUE ARGB16(1,0,0,31)


#endif /* DEFINES_H_ */
