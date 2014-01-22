/*
 * gameplay.c
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */
//#include "defines.h"
//#include "gameplay.h"
#include "graphics.h"
#include "controls.h"
//#include <math.h>
//#include <stdio.h>

void init_ball(struct Ball* ball){

	ball->x = 0;
	ball->y = 10;

	ball->vx = 1;
	ball->vy = 1;
}

void init_paddles(struct Paddle* pL, struct Paddle* pR){
	pL->y = 10;
	pL->length = 4;
	pR->y = 10;
	pR->length = 4;
}

void game_init(struct Ball* ball, struct Paddle* pL, struct Paddle* pR, int* pause_c){
	init_ball(ball);
	init_paddles(pL, pR);
	*pause_c = 10;
}

void move_ball(struct Ball* ball, struct Paddle* pL, struct Paddle* pR){
	ball->old_x = ball->x;
	ball->old_y = ball->y;

	ball->x = ball->x + ball->vx;
	if (ball->x < 0){
		ball->x = 1;
		ball->vx = -ball->vx;
	}
	else if (ball->x > 31){
		ball->x = 30;
		ball->vx = -ball->vx;
	}
	else if (ball->x==0 && ((pL->y <= ball->y) && (ball->y <= pL->y + pL->length))){
		ball->x = 2;
		ball->vx = -ball->vx;
	}
	else if (ball->y==30 && ((pR->y <= ball->y) && (ball->y <= pR->y + pR->length))){
		ball->x = 29;
		ball->vx = -ball->vx;
	}
	ball->y = ball->y + ball->vy;
	if (ball->y < 3){
		ball->y = 4;
		ball->vy = -ball->vy;
	}
	else if (ball->y > 23){
		ball->y = 22;
		ball->vy = -ball->vy;
	}
}

void move_paddle(struct Paddle* p, int move){
	p->old_y = p->y;
	p->y = p->y + move;
	if (p->y < 3 || p->y+p->length > 24){
		p->y = p->old_y;
	}
}

void ai_move_paddle(struct Paddle* p, struct Ball* ball){
	if(ball->y > p->y){
		move_paddle(p, 1);
	}
	else if (ball->y < p->y){
		move_paddle(p, -1);
	}
}

void toggle_paused(int* pause_c){
	if(*pause_c == -1){
		*pause_c = 0;
	}
	else{
		*pause_c = -15;
	}
}

void start_gameplay(){
	//consoleDemoInit();
	struct Ball ball;
	struct Paddle left, right;
	int pause_c;
	game_init(&ball, &left, &right, &pause_c);
	for(;;){
		if(pause_c == 0){
			//handleInput(&left, &right, &pause_c);
			move_ball(&ball, &left, &right);
			ai_move_paddle(&right, &ball);
			//draw_ball(&ball);
			//draw_paddles(&left, &right);
			//printf("x: %d vx: %d\ny: %d vy: %d\n",ball.xpos, ball.vx, ball.ypos, ball.vy);
		}
		else if(pause_c > 0){
			pause_c--;
		}
		else if(pause_c <= -2){
			pause_c++;
		}
		draw_board(&ball, &left, &right);
		handleInput(&left, &right, &pause_c);
		swiDelay(2000000);
	}
}


/*
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
*/
