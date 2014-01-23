/*
 * graphics.c
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */

#include "graphics.h"



//Tile declarations
u8 emptyTile[64] = {
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 fullTile[64] = {
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255
};

u8 full_blue[64] = {
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254,
		254,254,254,254,254,254,254,254
};

u8 topq[64] = {
	255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 toph[64] = {
	255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 top3q[64] = {
	255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 leftq[64] = {
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0
};

u8 lefth[64] = {
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0
};

u8 left3q[64] = {
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0
};

u8 topq_leftq[64] = {
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 topq_lefth[64] = {
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 topq_left3q[64] = {
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 toph_leftq[64] = {
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 toph_lefth[64] = {
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 toph_left3q[64] = {
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 top3q_leftq[64] = {
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	255,255,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 top3q_lefth[64] = {
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	255,255,255,255,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};

u8 top3q_left3q[64] = {
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	255,255,255,255,255,255,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0
};


void graphics_setup_main(){
	//Enable a proper RAM memory bank for the main engine
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;

	//Configure the main engine in mode 0 and activate Backgrounds 3 and 0
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG3_ACTIVE;

	//Enable a proper RAM memory bank for the sub engine
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	//Configure the sub engine in mode 5 and activate Background 2
	REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG2_ACTIVE;
}

void configure_BG0()
{


	//Configure BG 0 to represent the game field
	BGCTRL[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);

	//Copy the empty tile and the full tile to the corresponding RAM location
	dmaCopy(emptyTile, (u8*)BG_TILE_RAM(1), 64); //0
	dmaCopy(fullTile, (u8*)BG_TILE_RAM(1) + 64, 64); //1

	dmaCopy(topq, (u8*)BG_TILE_RAM(1) + 128, 64); //2
	dmaCopy(toph, (u8*)BG_TILE_RAM(1) + 192, 64); //3
	dmaCopy(top3q, (u8*)BG_TILE_RAM(1) + 256, 64); //4

	dmaCopy(leftq, (u8*)BG_TILE_RAM(1) + 320, 64); //5
	dmaCopy(lefth, (u8*)BG_TILE_RAM(1) + 384, 64); //6
	dmaCopy(left3q, (u8*)BG_TILE_RAM(1) + 448, 64); //7

	dmaCopy(topq_leftq, (u8*)BG_TILE_RAM(1) + 512, 64); //8
	dmaCopy(topq_lefth, (u8*)BG_TILE_RAM(1) + 576, 64); //9
	dmaCopy(topq_left3q, (u8*)BG_TILE_RAM(1) + 640, 64); //10

	dmaCopy(toph_leftq, (u8*)BG_TILE_RAM(1) + 704, 64); //11
	dmaCopy(toph_lefth, (u8*)BG_TILE_RAM(1) + 768, 64); //12
	dmaCopy(toph_left3q, (u8*)BG_TILE_RAM(1) + 832, 64); //13

	dmaCopy(top3q_leftq, (u8*)BG_TILE_RAM(1) + 896, 64); //14
	dmaCopy(top3q_lefth, (u8*)BG_TILE_RAM(1) + 960, 64); //15
	dmaCopy(top3q_left3q, (u8*)BG_TILE_RAM(1) + 1024, 64); //16

	dmaCopy(full_blue, (u8*)BG_TILE_RAM(1) + 1088, 64); //17
	//Assign component 255, 254, 0
	BG_PALETTE[254] = ARGB16(1,0,20,31);
	BG_PALETTE[255] = ARGB16(1,31,31,31);
	BG_PALETTE[0] = ARGB16(0,0,0,0);

}

void configure_BG3()
{

	//Configure BG 3 for the background image as explained before
	BGCTRL[3] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(3) | BG_TILE_BASE(2);

	//Copy tiles, map and palette in the memory (use swicopy or memcpy)
	swiCopy(topBgTiles, BG_TILE_RAM(2), topBgTilesLen);
	swiCopy(topBgMap, BG_MAP_RAM(3), topBgMapLen);
	swiCopy(topBgPal, BG_PALETTE, topBgPalLen);
}

void configure_BG2_SUB()
{
	//Initialize Background
	BGCTRL_SUB[2] = BG_MAP_BASE(0) | BgSize_B8_256x256;

	//Affine Matrix transformation
	REG_BG2PA_SUB = 256;
	REG_BG2PB_SUB = 0;
	REG_BG2PC_SUB = 0;
	REG_BG2PD_SUB = 256;

	//Copy grit generated maps over
	swiCopy(bottomBgPal, BG_PALETTE_SUB, bottomBgPalLen);
	swiCopy(bottomBgBitmap, BG_GFX_SUB, bottomBgBitmapLen);
}

void graphics_init()
{
    //Configure BG3 for background image
    configure_BG3();
    //Configure BG0 for game
    configure_BG0();
    // Configure Bottom background
    configure_BG2_SUB(); //Commented out for DEBUG only
}

void start_graphics()
{
	graphics_setup_main();
	graphics_init();
}

void clear_board(){
	int i;
	for(i = 0; i<1024; i++){
		BG_MAP_RAM(0)[i] = EMPTY;
	}
	swiDelay(3000);
}

void draw_ball(struct Ball* ball){
	//Clear old Ball
	BG_MAP_RAM(0)[32*(ball->old_y/4) + ball->old_x/4] = EMPTY;
	BG_MAP_RAM(0)[32*(ball->old_y/4) + ball->old_x/4 + 1] = EMPTY;
	BG_MAP_RAM(0)[32*(ball->old_y/4 + 1) + ball->old_x/4] = EMPTY;
	BG_MAP_RAM(0)[32*(ball->old_y/4 + 1) + ball->old_x/4 + 1] = EMPTY;

	//Draw Ball
	switch(ball->x%4){
		case 0:
			switch(ball->y%4){
				case 0:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = FULL;
					break;
				case 1:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOM3Q;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOPQ;
					break;
				case 2:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOMH;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOPH;
					break;
				case 3:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOMQ;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOP3Q;
					break;
				}
			break;
		case 1:
			switch(ball->y%4){
				case 0:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = RIGHT3Q;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = LEFTQ;
					break;
				case 1:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOM3Q_RIGHT3Q;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = BOTTOM3Q_LEFTQ;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOPQ_RIGHT3Q;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4 + 1] = TOPQ_LEFTQ;
					break;
				case 2:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOMH_RIGHT3Q;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = BOTTOMH_LEFTQ;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOPH_RIGHT3Q;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4 + 1] = TOPH_LEFTQ;
					break;
				case 3:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOMQ_RIGHT3Q;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = BOTTOMQ_LEFTQ;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOP3Q_RIGHT3Q;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4 + 1] = TOP3Q_LEFTQ;
					break;
				}
			break;
		case 2:
			switch(ball->y%4){
				case 0:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = RIGHTH;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = LEFTH;
					break;
				case 1:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOM3Q_RIGHTH;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = BOTTOM3Q_LEFTH;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOPQ_RIGHTH;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4 + 1] = TOPQ_LEFTH;
					break;
				case 2:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOMH_RIGHTH;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = BOTTOMH_LEFTH;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOPH_RIGHTH;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4 + 1] = TOPH_LEFTH;
					break;
				case 3:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOMQ_RIGHTH;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = BOTTOMQ_LEFTH;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOP3Q_RIGHTH;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4 + 1] = TOP3Q_LEFTH;
					break;
				}
			break;
		case 3:
			switch(ball->y%4){
				case 0:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = RIGHTQ;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = LEFT3Q;
					break;
				case 1:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOM3Q_RIGHTQ;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = BOTTOM3Q_LEFT3Q;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOPQ_RIGHTQ;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4 + 1] = TOPQ_LEFT3Q;
					break;
				case 2:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOMH_RIGHTQ;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = BOTTOMH_LEFT3Q;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOPH_RIGHTQ;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4 + 1] = TOPH_LEFT3Q;
					break;
				case 3:
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4] = BOTTOMQ_RIGHTQ;
					BG_MAP_RAM(0)[32*(ball->y/4) + ball->x/4 + 1] = BOTTOMQ_LEFT3Q;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4] = TOP3Q_RIGHTQ;
					BG_MAP_RAM(0)[32*(ball->y/4 + 1) + ball->x/4 + 1] = TOP3Q_LEFT3Q;
					break;
				}
			break;
	}
}

void draw_paddles(struct Paddle* pL, struct Paddle* pR){
	int i;

	//Left paddle
	for(i = pL->old_y/4; i <= (pL->old_y + pL->length)/4; i++){
		//clear old paddle area
		BG_MAP_RAM(0)[32*i] = EMPTY;
	}

	switch(pL->y%4) {
		case 1:
			BG_MAP_RAM(0)[32*(pL->y/4)] = BOTTOM3Q;
			break;
		case 2:
			BG_MAP_RAM(0)[32*(pL->y/4)] = BOTTOMH;
			break;
		case 3:
			BG_MAP_RAM(0)[32*(pL->y/4)] = BOTTOMQ;
			break;
	}
	switch((pL->y + pL->length)%4) {
		case 1:
			BG_MAP_RAM(0)[32*((pL->y + pL->length)/4)] = TOPQ;
			break;
		case 2:
			BG_MAP_RAM(0)[32*((pL->y + pL->length)/4)] = TOPH;
			break;
		case 3:
			BG_MAP_RAM(0)[32*((pL->y + pL->length)/4)] = TOP3Q;
			break;
	}
	for(i = (pL->y+3)/4; i < (pL->y + pL->length)/4; i++){
		BG_MAP_RAM(0)[32*i] = FULL;
	}

	//Right paddle
	for(i = pR->old_y/4; i <= (pR->old_y + pR->length)/4; i++){
		//clear old paddle area
		BG_MAP_RAM(0)[32*i+31] = EMPTY;
	}
	switch(pR->y%4) {
		case 1:
			BG_MAP_RAM(0)[32*(pR->y/4) + 31] = BOTTOM3Q;
			break;
		case 2:
			BG_MAP_RAM(0)[32*(pR->y/4) + 31] = BOTTOMH;
			break;
		case 3:
			BG_MAP_RAM(0)[32*(pR->y/4) + 31] = BOTTOMQ;
			break;
	}
	switch((pR->y + pR->length)%4) {
		case 1:
			BG_MAP_RAM(0)[32*((pR->y + pR->length)/4) + 31] = TOPQ;
			break;
		case 2:
			BG_MAP_RAM(0)[32*((pR->y + pR->length)/4) + 31] = TOPH;
			break;
		case 3:
			BG_MAP_RAM(0)[32*((pR->y + pR->length)/4) + 31] = TOP3Q;
			break;
	}
	for(i = (pR->y+3)/4; i < (pR->y + pR->length)/4; i++){
		BG_MAP_RAM(0)[32*i + 31] = FULL;
	}

}

void draw_score(struct Game* game){
	if(game->scoreLeft > 0){
		BG_MAP_RAM(0)[game->scoreLeft - 1] = FULL_BLUE;
		BG_MAP_RAM(0)[game->scoreLeft - 1 + 32] = FULL_BLUE;
		BG_MAP_RAM(0)[game->scoreLeft - 1 + 64] = FULL_BLUE;
	}

	if(game->scoreRight > 0){
		BG_MAP_RAM(0)[31-(game->scoreRight - 1)] = FULL_BLUE;
		BG_MAP_RAM(0)[31-(game->scoreRight - 1) + 32] = FULL_BLUE;
		BG_MAP_RAM(0)[31-(game->scoreRight - 1) + 64] = FULL_BLUE;
	}
}

void draw_board(struct Ball* ball, struct Paddle* pL, struct Paddle* pR, struct Game* game){
	draw_ball(ball);
	draw_paddles(pL, pR);
	draw_score(game);
}

