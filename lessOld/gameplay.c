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
	ball->xpos = INIT_XPOS;
	ball->ypos = INIT_YPOS;
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

void printState(struct State *game){
	printf("scoreLeft = %d\n",game->scoreLeft);
	printf("scoreRight = %d\n",game->scoreRight);
	printf("xpos = %d\n",game->xpos);
	printf("ypos = %d\n",game->ypos);
	printf("leftpos = %d\n",game->leftpos);
	printf("rightpos = %d\n",game->rightpos);
	printf("DOWN = %d\n",game->keyDOWN);
	printf("UP = %d\n",game->keyUP);
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
	int x = vx + xcoord;
	return x;
}

int getY(float vy, int ycoord){
	int y = vy + ycoord;
	return y;
}

void reflectX(struct State *game){
	game->direction = 360-game->direction;
}

void reflectY(struct State *game){
	game->direction = 180-game->direction;
}

void detectCollision(struct State *game){
	int balltop = game->ypos+BALL_SIZE;
	int ballbottom = game->ypos-BALL_SIZE;
	int ballleft = game->xpos-BALL_SIZE;
	int ballright = game->xpos+BALL_SIZE;

	int lpaddletop = game->leftpos-PADDLE_WIDTH/2;
	int lpaddlebottom = game->leftpos+PADDLE_WIDTH/2;

	int rpaddletop = game->rightpos-PADDLE_WIDTH/2;
	int rpaddlebottom = game->rightpos+PADDLE_WIDTH/2;

	if (ballleft <= PADDLE_THICK){
		if (balltop <= lpaddletop || ballbottom >= lpaddlebottom){
			reflectY(game);
		}
	}
	else if (ballright >=(255-PADDLE_THICK)){
		if (balltop <= rpaddletop || ballbottom >= rpaddlebottom){
			reflectY(game);
		}
	}
}

void calcFrame(struct State *game){
	game->xpos = getX(getVX(game->speed,game->direction),game->xpos);
	game->ypos = getY(getVY(game->speed,game->direction),game->ypos);

	if (game->ypos <= 0 || game->ypos >= 191){
		reflectX(game);
	}
	if (game->xpos <= 0 || game->xpos >= 255){
		reflectY(game);
		if (game->xpos <= 0){
			game->scoreLeft += 1;
		}
		else if (game->xpos <= 0){
			game->scoreRight += 1;
		}
	}
}
