/*
 * gameplay.c
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */
#include "defines.h"
#include "gameplay.h"
#include "graphics.h"
#include <math.h>
#include <stdio.h>

void initGame(struct Ball *ball,struct Paddle *left, struct Paddle *right, struct Game *game){
	ball->xpos = ball->xpos_old= INIT_XPOS;
	ball->ypos = ball->ypos_old =  INIT_YPOS;
	ball->direction = INIT_DIRECTION;

	game->scoreLeft = 0;
	game->scoreRight = 0;
	left->position = right->position = 71;//192/2-48/2

	game->speed = SPEED;
	game->pause = 0;
	game->reset = 0;


	P_Graphics_setup_main(1);

    //for framebuffer
    //P_Graphics_assignBuffer(MAIN, (u16*)VRAM_A,256,192);

    //for rotoscale
    P_Graphics_assignBuffer(MAIN, (u16*)BG_GFX,256,192);
    P_Map16x16_configureBG2();
    FillScreen(MAIN, GREEN);
}

void P_Map16x16_configureBG2()
{
    //Initialize Background
    BGCTRL[2] = BG_MAP_BASE(0) | BgSize_B16_256x256;

    //Affine Marix Transformation
    REG_BG2PA = 256;
    REG_BG2PC = 0;
    REG_BG2PB = 0;
    REG_BG2PD = 256;

    //Initialize pointer to the graphic memory
    //mapMemory = ...
    mapMemory = BG_GFX;
}

void printState(struct Game *game){
	printf("scoreLeft = %d\n",game->scoreLeft);
	printf("scoreRight = %d\n",game->scoreRight);
}

void printBall(struct Ball *ball){
	printf("Ball X = %d\n",ball->xpos);
	printf("Ball Y = %d\n",ball->ypos);
	printf("Ball X OLD= %d\n",ball->xpos_old);
	printf("Ball Y OLD= %d\n",ball->ypos_old);
}

void printPaddle(struct Paddle *paddle){
	printf("Paddle position is: %d\n",paddle->position);
	printf("Paddle speed is: %f\n",paddle->speed);
	printf("Paddle old position is\n: %d",paddle->position_old);
}
float getVX(int speed, int direction){
	float vx = speed*cos((float)direction*PI/180.0);
	return vx;
}

float getVY(int speed, int direction){
	float vy = speed*sin((float)direction*PI/180.0);
	return vy;
}

int getX(float vx, int xcoord){
	int x = (int)vx + xcoord;
	return x;
}

int getY(float vy, int ycoord){
	int y = (int)vy + ycoord;
	return y;
}

void reflectX(struct Ball *ball){
	ball->direction = 360-ball->direction;
}

void reflectY(struct Ball *ball){
	ball->direction = 180-ball->direction;
}

void reflectYY(direction){
	direction = 180-direction;
}

void detectCollision(struct Paddle *left, struct Paddle *right, struct Ball *ball, struct Game *game){
	int balltop = ball->ypos+BALL_SIZE;
	int ballbottom = ball->ypos-BALL_SIZE;
	int ballleft = ball->xpos-BALL_SIZE;
	int ballright = ball->xpos+BALL_SIZE;

	int lpaddletop = left->position+PADDLE_WIDTH;
	int lpaddlebottom = left->position;

	int rpaddletop = right->position+PADDLE_WIDTH;
	int rpaddlebottom = right->position;

	if (game->collision_lead == 0){
		if (ballleft <= PADDLE_THICK){
			if (balltop <= lpaddlebottom || ballbottom >= lpaddletop){
				reflectY(ball);
				game->collision_lead = 2;
			}
		}
		else if (ballright >=(255-PADDLE_THICK)){
			if (balltop <= rpaddlebottom || ballbottom >= rpaddletop){
				reflectY(ball);
				game->collision_lead = 2;
			}
		}
	}
	else {
		game->collision_lead--;
	}
}

void calcFrame(struct Ball *ball, struct Game *game){
	ball->xpos_old = ball->xpos;
	ball->ypos_old = ball->ypos;

	float vx = getVX(game->speed,ball->direction);
	float vy = getVY(game->speed,ball->direction);

	ball->xpos = getX(vx,ball->xpos);
	ball->ypos = getY(vy,ball->ypos);

	if (ball->ypos <= 0 || ball->ypos >= 191){
		reflectX(ball);
	}
	if (ball->xpos <= 0 || ball->xpos >= 255){
		reflectY(ball);
	}
}
