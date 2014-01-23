/*
 * gameplay.h
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */

#include <nds.h>
#include <stdio.h>


void game_init(struct Ball *ball, struct Paddle* pL, struct Paddle* pR, struct Game* game);
void start_gameplay();
void move_paddle(struct Paddle* paddle, int move);
void ai_move_paddle(struct Paddle* paddle, struct Ball* ball);
void toggle_paused( struct Game* game);
void move_ball(struct Ball* ball, struct Paddle* pL, struct Paddle* pR, struct Game* game);
void update_game(struct Paddle* pL, struct Paddle* pR, struct Ball* ball, struct Game* game);
void reset_ball(struct Ball* ball, int vx, int vy);
void reset_game(struct Game* game, struct Ball* ball, struct Paddle* left, struct Paddle* right);
void paddle_grow(struct Paddle* pL, struct Paddle* pR, struct Game* game);

