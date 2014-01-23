/*
 * controls.h
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */
#include "defines.h"
#include <nds.h>
#include "gameplay.h"


void handleInput(struct Paddle* pL, struct Paddle* pR, struct Game* game);
void handleTouchScreen(struct Paddle* left, struct Paddle* right, struct Game* game);
