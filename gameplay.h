/*
 * gameplay.h
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */

#include "defines.h"

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
#define RED ARGB16(1,31,0,0)
void initGame(struct Ball *ball,struct Paddle *left, struct Paddle *right, struct Game *game);
void P_Map16x16_configureBG2();
void printState(struct Game *game);
float getVX(int speed, int direction);
float getVY(int speed, int direction);
void calcFrame(struct Ball *ball,struct Game *game);
void detectCollision(struct Paddle *left, struct Paddle *right, struct Ball *ball, struct Game *game);

#endif /* GAMEPLAY_H_ */
