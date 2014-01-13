/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include <string.h>
#include "controls.h"
#include "gameplay.h"
#include "graphics.h"
#include "defines.h"

int main(void) {
	struct Ball ball;
	struct Paddle left;
	struct Paddle right;
	struct Game game;
	initGame(&ball,&left,&right,&game);
    consoleDemoInit();
    for(;;){
    	consoleClear();
    	handleInput(&game,&left,&right);
    	printState(&game);
    	printPaddle(&left);
    	printBall(&ball);
    	drawFrame(&left,&right,&ball);
    	if (game.pause == 0){
    		calcFrame(&ball,&game);
    		//detectCollision(&left, &right,&ball,&game);
    	}
    	if (game.reset == 1){
    		if (game.pause == 1){
    			initGame(&ball,&left,&right,&game);
    			game.pause = 1;
    		}
    		else{
    			initGame(&ball,&left,&right,&game);
    		}
    		game.reset = 0;
    	}
    	swiWaitForVBlank();
    }
}
