/*
 * controls.c
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */

#include <nds.h>
#include "controls.h"
#include "gameplay.h"

void handleInput(struct Paddle* left, struct Paddle* right, struct Game* game)
{
	//Scan the keys
	u16 keys;
	scanKeys();
	keys = keysHeld();
	if (game->pause_c == 0) {
		if (keys & KEY_DOWN){
			move_paddle(left, 1);
			}
		if (keys & KEY_UP){
			move_paddle(left, -1);
		}
		if (keys & KEY_X){
			move_paddle(right, -1);
			game->ai_c = 0;
		}
		if (keys & KEY_B){
			move_paddle(right, 1);
			game->ai_c = 0;
		}
	}
	if (keys & KEY_START){
		toggle_paused(game);
	}
	if (keys & KEY_SELECT){
		game->reset = 1;
	}
	handleTouchScreen(left, right, game);
}


void handleTouchScreen(struct Paddle* left, struct Paddle* right, struct Game* game){
	touchPosition t;
	touchRead(&t);
	if(game->pause_c == 0){
		if (t.px || t.py) { //only if they're not both zero
			if (t.px <= 40) {
				if (t.py <= 80) {
					move_paddle(left, -(((80-t.py)/60) + 1));
				}
				else if (112 <= t.py) {
					move_paddle(left, (t.py - 112)/60 + 1);
				}
			}
			if (t.px >= 220) {
				if (t.py <= 80) {
					move_paddle(right, -(((80-t.py)/60) + 1));
					game->ai_c = 0;
				}
				else if (112 <= t.py) {
					move_paddle(right, (t.py - 112)/60 + 1);
					game->ai_c = 0;
				}
			}
		}
	}
	if (t.px || t.py) {
		if(t.py > 125 && t.py < 180) {
			if(t.px > 60 && t.px < 110){
				game->reset = 1;
			}
			else if(t.px > 140 && t.px < 190){
				toggle_paused(game);
			}
		}
		else if(t.py > 50 && t.py < 100) {
			if(t.px > 60 && t.px < 110){
				paddle_grow(left, right, game);
			}
			else if(t.px > 140 && t.px < 190){
				game->redirect = 1;
			}
		}
	}
}


