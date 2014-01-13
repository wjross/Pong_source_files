/*
 * graphics.c
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */

#include "graphics.h"
#include "defines.h"

void drawFrame(struct State *game){
	//FillScreen(MAIN, ARGB16(1,0,31,0));
	drawBall(game->xpos,game->ypos);
	drawLeftPaddle(game->leftpos);
	drawRightPaddle(game->rightpos);

}

void drawLeftPaddle(int centrePosition){
	centrePosition = 191-centrePosition;
	int top = centrePosition-PADDLE_WIDTH/2;
	int bottom = centrePosition+PADDLE_WIDTH/2;
	FillRectangle(MAIN, top,bottom,0,PADDLE_THICK, ARGB16(1,0,0,31));
}

void drawRightPaddle(int centrePosition){
	centrePosition = 191-centrePosition;
	int top = centrePosition-PADDLE_WIDTH/2;
	int bottom = centrePosition+PADDLE_WIDTH/2;
	FillRectangle(MAIN, top,bottom,255-PADDLE_THICK,255, ARGB16(1,0,0,31));
}

void drawBall(int x, int y){
	int size = BALL_SIZE;
	y = 191-y;
	int top = y-size;
	int bottom = y+size;
	int left = x-size;
	int right = x+size;
	FillRectangle(MAIN, top,bottom,left,right, ARGB16(1,31,0,0));
}

void P_Graphics_setup_main(int mode){
	if (mode == 0){
		REG_DISPCNT = MODE_FB0;
		VRAM_A_CR = VRAM_ENABLE| VRAM_A_LCD;
	}
	else if (mode == 1){
		VRAM_A_CR = VRAM_ENABLE| VRAM_A_MAIN_BG;
		REG_DISPCNT = MODE_5_2D | DISPLAY_BG2_ACTIVE;
	}
}
void P_Graphics_assignBuffer(enum BUFFER_TYPE bT, u16* buffer, int w, int h)
{

    switch(bT)
    {
        case MAIN: P_Graphics_mainBuffer = buffer;
            P_Graphics_mainW = w;
            P_Graphics_mainH = h;
            break;
        case SUB: P_Graphics_subBuffer = buffer;
            P_Graphics_subW = w;
            P_Graphics_subH = h;
            break;
    }
}

void FillScreen(enum BUFFER_TYPE t, u16 color)
{
	int i;
	switch(t)
	{
	case MAIN:
		//Fill the whole screen (256*192) with the given color
		for(i = 0; i<P_Graphics_mainH*P_Graphics_mainW; i++)
			P_Graphics_mainBuffer[i] = color;
		break;
	case SUB:

		break;
	default:
		return;
		break;
	}
}

void FillRectangle(enum BUFFER_TYPE bT, int top, int bottom, int left, int right, u16 color)
{
	int row, col;
	if(bT == MAIN)	//Check that we want to use the Main engine
		if(top >=0 && top <=191)	//Check boundaries of top
			if(bottom >= 0 && bottom <=191)	//Check boundaries of bottom
				if(left >=0 && left <= 255)	//Check boundaries of left
					if(right >=0 && right <=255)	//Check boundaries of right
						for(row = top; row < bottom; row++)		//For rows from top to bottom
							for(col = left; col < right; col++)	//And for column from left to right
								P_Graphics_mainBuffer[row*256 + col] = color;	//Assign the color
}

void DrawHorizontalLine(enum BUFFER_TYPE bT, int x, int x2, int y, u16 color)
{
	int col;
	if(bT == MAIN) //Check that we want to use the Main engine
	if(y >= 0 && y <=191)	//Check the boundaries of y
		if(x >=0 && x <= 255)	//Check the boundaries of x
			if(x2 >=0 && x2 <=255)	//Check the boundaries of x2
				for(col = x; col < x2; col++)	//For columns from x to x2
					P_Graphics_mainBuffer[y*256 + col] = color;	//Assign the color
}
void DrawVerticalLine(enum BUFFER_TYPE bT, int y, int y2, int x, u16 color)
{
	int row;
	if(bT == MAIN) //Check that we want to use the Main engine
	if(y >= 0 && y <=191)	//Check the boundaries of y
		if(y2 >=0 && y2 <= 191)	//Check the boundaries of y2
			if(x >=0 && x <=255)	//Check the boundaries of x
				for(row = y; row < y2; row++)	//For row from y to y2
					P_Graphics_mainBuffer[row*256 + x] = color;	//Assign the color
}

void DrawRectangle(enum BUFFER_TYPE bT, int top, int bottom, int left, int right, u16 color)
{
	if(bT == MAIN)	//Check that we want to use the Main engine
			if(top >=0 && top <=191)	//Check boundaries of top
				if(bottom >= 0 && bottom <=191)	//Check boundaries of bottom
					if(left >=0 && left <= 255)	//Check boundaries of left
						if(right >=0 && right <=255)	//Check boundaries of right
							if(top < bottom && left < right)
							{
								//Vertical line on the left
								DrawVerticalLine(MAIN, top, bottom, left, color);
								//Verticla line on the right
								DrawVerticalLine(MAIN, top, bottom, right, color);
								//Horizontal line in top
								DrawHorizontalLine(MAIN, left, right, top, color);
								//Horizontal line on the bottom
								DrawHorizontalLine(MAIN, left, right, bottom, color);
							}
}

void FillRectangleUnp(enum BUFFER_TYPE bT, int top, int bottom, int left, int right, u16 color)
{
	int row, col;
	for(row = top; row < bottom; row++)		//For rows from top to bottom
		for(col = left; col < right; col++)	//And for column from left to right
			P_Graphics_mainBuffer[row*256 + col] = color;	//Assign the color
}
