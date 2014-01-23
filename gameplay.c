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
#include <maxmod9.h>
//#include "soundbank.h"
//#include "soundbank_bin.h"
//#include <math.h>
//#include <stdio.h>

void init_ball(struct Ball* ball){

	ball->x = 60;
	ball->y = 50;

	ball->vx = 1;
	ball->vy = 0;
}

void reset_ball(struct Ball* ball, int vx, int vy){
	ball->x = 50;
	ball->y = 50;

	ball->vx = vx;
	ball->vy = vy;
}

void init_paddles(struct Paddle* pL, struct Paddle* pR){
	pL->y = 50;
	pL->length = 18;
	pR->y = 50;
	pR->length = 18;
}

void game_init(struct Ball* ball, struct Paddle* pL, struct Paddle* pR, struct Game* game){
	init_ball(ball);
	init_paddles(pL, pR);
	game->pause_c = -1;
	game->scoreLeft = 0;
	game->scoreRight = 0;
	game->ai_c = 1;
}

void move_ball(struct Ball* ball, struct Paddle* pL, struct Paddle* pR, struct Game* game){
	ball->old_x = ball->x;
	ball->old_y = ball->y;

	ball->x = ball->x + ball->vx;
	if (ball->x < 0){
		reset_ball(ball, 1,0);
		game->scoreRight++;
		game->pause_c = 50;
	}
	else if (ball->x > 124){
		reset_ball(ball, -1,0);
		game->scoreLeft++;
		game->pause_c = 50;
	}
	else if (ball->x < 3 && ((pL->y <= ball->y + 3) && (ball->y <= pL->y + pL->length))){
		ball->vy = -1;
	}
	else if (ball->x > 121 && ((pR->y <= ball->y + 3) && (ball->y <= pR->y + pR->length))){
		ball->vy = -1;
	}
	else if (ball->x==3 && ((pL->y <= ball->y + 3) && (ball->y <= pL->y + pL->length))){
		ball->x = 4;
		ball->vx = -ball->vx;
		if (ball->y < pL->y + pL->length/3)
			ball->vy--;
		else if (ball->y > pL->y + pL->length*2/3 - 2)
			ball->vy++;
		//mmEffect(SFX_PHASERS3);
	}
	else if (ball->x==121 && ((pR->y <= ball->y + 3) && (ball->y <= pR->y + pR->length))){
		ball->x = 120;
		ball->vx = -ball->vx;
		if (ball->y < pR->y + pR->length/3)
			ball->vy--;
		else if (ball->y > pR->y + pR->length*2/3 - 2)
			ball->vy++;
		//mmEffect(SFX_PHASERS3);
	}
	ball->y = ball->y + ball->vy;
	if (ball->y < 12){
		ball->y = 13;
		ball->vy = -ball->vy;
	}
	else if (ball->y > 92){
		ball->y = 91;
		ball->vy = -ball->vy;
	}
}

void move_paddle(struct Paddle* p, int move){
	p->old_y = p->y;
	p->y = p->y + move;
	if (p->y < 12 || p->y+p->length > 96){
		p->y = p->old_y;
	}
}

void ai_move_paddle(struct Paddle* p, struct Ball* ball){
	if(ball->x > 70 && ball->vx == 1){
		if(ball->y > (p->y + p->length/2)){
			move_paddle(p, 1);
		}
		else if (ball->y < (p->y + p->length/2)){
			move_paddle(p, -1);
		}
	}
}

void update_game(struct Paddle* pL, struct Paddle* pR, struct Ball* ball, struct Game* game){
	if(game->pause_c == 0){
		move_ball(ball, pL, pR, game);
		if (game->ai_c == 1){
			ai_move_paddle(pR, ball);
		}
	}
	else if(game->pause_c < -1){
		game->pause_c = game->pause_c + 1;
	}
	else if(game->pause_c > 0){
		game->pause_c = game->pause_c - 1;
	}
	if(game->scoreLeft == 11 || game->scoreRight == 11){
		game->reset = 1;
	}
}

void toggle_paused( struct Game* game){
	if(game->pause_c == -1){
		game->pause_c = 30;
	}
	else if(game->pause_c == 0){
		game->pause_c = -30;
	}
}

void reset_game(struct Game* game, struct Ball* ball){
	init_ball(ball);
	game->pause_c = -1;
	game->scoreLeft = 0;
	game->scoreRight = 0;
	game->reset = 0;
	game->ai_c = 1;
	clear_board();
}

void start_gameplay(){
	//consoleDemoInit();
	struct Ball ball;
	struct Paddle left, right;
	struct Game game;
	game_init(&ball, &left, &right, &game);
	draw_board(&ball, &left, &right, &game);
	for(;;){
		if(!game.reset) {
			draw_board(&ball, &left, &right, &game);
			//printf("x: %d y: %d\n\n", ball.x, ball.y);
			handleInput(&left, &right, &game);
			update_game(&left, &right, &ball, &game);
			//printf("x: %d y: %d\n", ball.x, ball.y);
		}
		else reset_game(&game, &ball);
		swiDelay(300000); //good speed 500000
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
