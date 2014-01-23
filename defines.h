/*
 * defines.h
 *
 *  Created on: Dec 25, 2013
 *      Author: nds
 */

#ifndef DEFINES_H_
#define DEFINES_H_

struct Ball {
	int x;//current coordinates of the ball
	int y;

	int vx;
	int vy;

	int old_x;
	int old_y;
};

struct Paddle {
	int y;
	int old_y;
	int length;
	float speed;
};

struct Game {
	int pause_c;
	int reset;//reset game flag
	int scoreLeft;//scores of left and right player
	int scoreRight;
	int ai_c; //turn ai control on / off
	int redirect;
};

//tile name shortcuts
#define EMPTY 0
#define FULL 1

#define TOPQ 2
#define TOPH 3
#define TOP3Q 4
#define BOTTOMQ 0x0802
#define BOTTOMH 0x0803
#define BOTTOM3Q 0x0804

#define LEFTQ 5
#define LEFTH 6
#define LEFT3Q 7
#define RIGHTQ 0x0405
#define RIGHTH 0x0406
#define RIGHT3Q 0x0407

#define TOPQ_LEFTQ 8
#define TOPQ_LEFTH 9
#define TOPQ_LEFT3Q 10
#define TOPQ_RIGHTQ 0x0408
#define TOPQ_RIGHTH 0x0409
#define TOPQ_RIGHT3Q 0x040A
#define BOTTOMQ_LEFTQ 0x0808
#define BOTTOMQ_LEFTH 0x0809
#define BOTTOMQ_LEFT3Q 0x080A
#define BOTTOMQ_RIGHTQ 0x0C08
#define BOTTOMQ_RIGHTH 0x0C09
#define BOTTOMQ_RIGHT3Q 0x0C0A

#define TOPH_LEFTQ 11
#define TOPH_LEFTH 12
#define TOPH_LEFT3Q 13
#define TOPH_RIGHTQ 0x040B
#define TOPH_RIGHTH 0x040C
#define TOPH_RIGHT3Q 0x040D
#define BOTTOMH_LEFTQ 0x080B
#define BOTTOMH_LEFTH 0x080C
#define BOTTOMH_LEFT3Q 0x080D
#define BOTTOMH_RIGHTQ 0x0C0B
#define BOTTOMH_RIGHTH 0x0C0C
#define BOTTOMH_RIGHT3Q 0x0C0D

#define TOP3Q_LEFTQ 14
#define TOP3Q_LEFTH 15
#define TOP3Q_LEFT3Q 16
#define TOP3Q_RIGHTQ 0x040E
#define TOP3Q_RIGHTH 0x040F
#define TOP3Q_RIGHT3Q 0x0410
#define BOTTOM3Q_LEFTQ 0x080E
#define BOTTOM3Q_LEFTH 0x080F
#define BOTTOM3Q_LEFT3Q 0x0810
#define BOTTOM3Q_RIGHTQ 0x0C0E
#define BOTTOM3Q_RIGHTH 0x0C0F
#define BOTTOM3Q_RIGHT3Q 0x0C10

#define FULL_BLUE 17



#endif /* DEFINES_H_ */
