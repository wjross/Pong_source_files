/*
 * gameplay.h
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */

#include <nds.h>
#include <stdio.h>


//#include "defines.h"

//#ifndef GAMEPLAY_H_
//#define GAMEPLAY_H_
//#define RED ARGB16(1,31,0,0)

void game_init(struct Ball *ball, struct Paddle* pL, struct Paddle* pR, struct Game* game);
void start_gameplay();
void move_paddle(struct Paddle* paddle, int move);
void ai_move_paddle(struct Paddle* paddle, struct Ball* ball);
void toggle_paused( struct Game* game);
void move_ball(struct Ball* ball, struct Paddle* pL, struct Paddle* pR, struct Game* game);
void update_game(struct Paddle* pL, struct Paddle* pR, struct Ball* ball, struct Game* game);
void reset_ball(struct Ball* ball, int vx, int vy);


/*void P_Map16x16_configureBG2();
void printState(struct Game *game);
float getVX(int speed, int direction);
float getVY(int speed, int direction);
void calcFrame(struct Ball *ball,struct Game *game);
void detectCollision(struct Paddle *left, struct Paddle *right, struct Ball *ball, struct Game *game);
*/
//#endif /* GAMEPLAY_H_ */
