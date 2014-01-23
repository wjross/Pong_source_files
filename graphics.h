/*
 * graphics.h
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */
#include <nds.h>
#include "defines.h"
#include "bottomBg.h"
#include "topBg.h"

void graphics_setup_main();
void graphics_init();
void start_graphics();
void draw_ball(struct Ball* ball);
void configure_BG0();
void configure_BG3();
void configure_BG2_SUB();
void draw_board(struct Ball* ball, struct Paddle* pL, struct Paddle* pR, struct Game* game);
void draw_paddles(struct Paddle* pL, struct Paddle* pR);
void draw_score(struct Game* game);
void clear_board();


