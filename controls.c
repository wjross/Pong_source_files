/*
 * controls.c
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */

#include <nds.h>
//#include "defines.h"
//#include <stdio.h>
#include "controls.h"
#include "gameplay.h"
//#include "graphics.h"

void handleInput(struct Paddle* left, struct Paddle* right, int* pause_c)
{
	//Scan the keys
	u16 keys;
	scanKeys();
	keys = keysHeld();
	if (*pause_c == 0) {
		if (keys & KEY_DOWN){
			move_paddle(left, 1);
		}
		if (keys & KEY_UP){
			move_paddle(left, -1);
		}
	}
	if (keys & KEY_START){
		start_gameplay(); //DEBUG ONLY
	}
	if (keys & KEY_SELECT){
		toggle_paused(pause_c);
	}

	/*if (keys & KEY_START){
		if (game->pause == 0){
			game->pause = 1;
		}
		else{
			game->pause = 0;
		}
	}

	if (keys & KEY_SELECT){
		if (game->reset == 0){
			game->reset = 1;
		}
	}

	//left player controls
	if (keys & KEY_UP){
		acceleratePaddle(left,1);
	}
	else {
		acceleratePaddle(left,0);
	}
	if (keys & KEY_DOWN){
		acceleratePaddle(left,-1);
	}

	//right player controls
	if (keys & KEY_B){
		acceleratePaddle(right,1);
	}
	else {
		acceleratePaddle(right,0);
	}
	if (keys & KEY_X){
		acceleratePaddle(right,-1);
	}*/
}
/*
float getV(float u, int direction){//initial speed, direction of acc. 1 positive -1 negative and 0 none
	float v;

	if ( ((u < PST && u > 0) || (u > -PST && u < 0 )) && direction == 0){ // if -PST < U < PST and no acceleration is applied
		return 0;
	}

	//direction control
	if (direction == 1){
		v = u + ((float)PADDLE_ACCELERATION - (float)PADDLE_FRICTION)/10;
	}
	else if (direction == -1){
		v = u - ((float)PADDLE_ACCELERATION - (float)PADDLE_FRICTION)/10;
	}
	else {// if 0
		if (u > 0){
			v = u - (float)PADDLE_FRICTION/10;
		}
		else if (u < 0){
			v = u + (float)PADDLE_FRICTION/10;
		}
		else {//if u = 0
			return 0;
		}
	}

	//max speed control
	if (v > PADDLE_SPEED){
		v = PADDLE_SPEED;
	}
	else if (v < (0-PADDLE_SPEED)){
		v = -PADDLE_SPEED;
	}
	return v;
}

int getPos(float v, int position){
	position = (int)v + position; //speed
	if (position > (255-PADDLE_WIDTH)){
		position = 255 - PADDLE_WIDTH;//paddle length
	}
	else if (position < 0){
		position = 0;
	}
	return position;
}

void acceleratePaddle(struct Paddle *paddle, int direction) {
	paddle->position_old = paddle->position;
	paddle->speed = getV(paddle->speed,direction);
	paddle->position = getPos(paddle->speed,paddle->position);
	if (paddle->position == 0 || paddle->position == (255-PADDLE_WIDTH)){
		paddle->speed = 0;
	}
}*/
