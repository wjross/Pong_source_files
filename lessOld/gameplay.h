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
void initGame(struct State *game);
void P_Map16x16_configureBG2();
void printState(struct State *game);
float getVX(int speed, int direction);
float getVY(int speed, int direction);
void calcFrame(struct State *game);

#endif /* GAMEPLAY_H_ */
