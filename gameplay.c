/*
 * gameplay.c
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */

#include "graphics.h"
#include "controls.h"
#include <maxmod9.h>
/*
#include "soundbank.h"
#include "soundbank_bin.h"
*/
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
	else if (ball->x== 50 && game->redirect) {
		if (game->scoreLeft > game->scoreRight + 2) {
			if (ball->vx == -1)
				ball->vy = -ball->vy;
		}
		else if (game->scoreRight > game->scoreLeft + 2) {
			if (ball->vx == 1)
				ball->vy = -ball->vy;
		}
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

void paddle_grow(struct Paddle* pL, struct Paddle* pR, struct Game* game){
	if (game->scoreLeft > game->scoreRight + 4){
		move_paddle(pR, -6);
		pR->length = 27;
	}
	else if (game->scoreRight > game->scoreLeft + 4){
		move_paddle(pL, -6);
		pL->length = 27;
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

void reset_game(struct Game* game, struct Ball* ball, struct Paddle* left, struct Paddle* right){
	init_ball(ball);
	init_paddles(left, right);
	game->pause_c = -1;
	game->scoreLeft = 0;
	game->scoreRight = 0;
	game->reset = 0;
	game->ai_c = 1;
	game->redirect = 0;
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
		else reset_game(&game, &ball, &left, &right);
		swiDelay(200000); //good speed 200000
	}
}

