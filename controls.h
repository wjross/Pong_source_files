/*
 * controls.h
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */
#include "defines.h"
#include <nds.h>
#include "gameplay.h"


void handleInput(struct Paddle* pL, struct Paddle* pR, int* pause_c);
/*
#ifndef CONTROLS_H_
#define CONTROLS_H_

void handleInput(struct Game *game,struct Paddle *left, struct Paddle *right);

void acceleratePaddle(struct Paddle *paddle, int direction);

int getPos(float v, int position);

float getV(float u, int direction);

#endif  CONTROLS_H_ */
