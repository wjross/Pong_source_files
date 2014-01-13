/*
 * controls.c
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */

#include "nds.h"
#include "defines.h"
#include <stdio.h>
#include "controls.h"
#include "graphics.h"

void handleInput(struct Game *game)
{
	//Scan the keys
	scanKeys();
	unsigned keys = keysHeld();
	if (keys & KEY_START){
		if (game->pause == 0){
			game->pause = 1;
		}
		else{
			game->pause = 0;
		}
	}

	if (keys & KEY_SELECT){
		if (game->reset == 0){
			game->reset = 1;
		}
	}

	if (keys & KEY_L){
		if (game->speed > 1)
			game->speed -= 1;
	}
	if (keys & KEY_R){
		if (game->speed < 10)
			game->speed += 1;
	}
	if (keys & KEY_UP){
		//accelerate up
	}
	if (keys & KEY_DOWN){
		//accelerate down
	}
	if (keys & KEY_B){
		//acc up
	}
	if (keys & KEY_X){
		//acc up
	}
}
