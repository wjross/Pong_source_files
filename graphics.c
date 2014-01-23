/*
 * graphics.c
 *
 *  Created on: Dec 14, 2013
 *      Author: nds
 */

#include "graphics.h"
//#include "defines.h"


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
	/*
	 * GRAPHICS III
	 *
	 * This function is called in the initialization of the P_Map16x16 to
	 * configure the Background 0 (on the top).
	 *
	 * This background is going to be used to draw the game field where
	 * the blocks are falling.
	 *
	 * The function does not return anything and it does not have any input
	 * arguments. Background 0 (BG0) should be configured in the tiled mode
	 * as a 32x32 tile grid and using one general color palette of 256
	 * components (256 colors). The pointer to the map 'mapMemory' must be
	 * correctly assigned before returning from the function
	 */

	//Configure BG 0 to represent the game field
	BGCTRL[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);

	//Copy the empty tile and the full tile to the corresponding RAM location
	//according to the chosen TILE_BASE. If dmaCopy is used, do not forget to
	//cast the destination pointer as a 'byte pointer'
	//Hint: Use the macro BG_TILE_RAM to get the destination address
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
	//Set the pointer mapMemory to the RAM location of the chosen MAP_BASE
	//Hint: use the macro BG_MAP_RAM

}

void configure_BG3()
{
	/*GRAPHICS III
	 *
	 * This function is called in the initialization of the P_Map16x16 to
	 * configure the Background 3.
	 *
	 * This background is going to be used to background wall-paper.
	 *
	 * In exercise 2 the Background 3 (BG3) should be configure in rotoscale
	 * mode with a 8 bits of pixel depth. Do not forget to copy the palette
	 * correctly.
	 *
	 * In exercise 5 Background 3 (BG3) should be configured in the tiled mode
	 * as a 32x32 tile grid and using one general color palette of 256
	 * components (256 colors).
	 */

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
	/*int i;
	for (i = 0; i<1023; i++){
		BG_MAP_RAM(0)[i] = 0;
	}*/
	draw_ball(ball);
	draw_paddles(pL, pR);
	draw_score(game);
}

/*
void drawFrame(struct Paddle *left, struct Paddle *right, struct Ball *ball){
	FillScreen(MAIN, ARGB16(1,0,31,0));
	drawBall(ball->xpos_old,ball->xpos_old, RED);
	drawBall(ball->xpos,ball->ypos, BLUE);

	//drawLeftPaddle(left->position_old, BG_COLOR);
	//drawLeftPaddle(left->position,BLUE);

	//drawRightPaddle(right->position_old, BG_COLOR);
	//drawRightPaddle(right->position,BLUE);


}

void drawLeftPaddle(int position, u16 color){
	position = 191-position;
	int top = position-PADDLE_WIDTH;
	int bottom = position;
	FillRectangle(MAIN, top,bottom,0,PADDLE_THICK, color);
}

void drawRightPaddle(int position, u16 color){
	position = 191-position;
	int top = position-PADDLE_WIDTH;
	int bottom = position;
	FillRectangle(MAIN, top,bottom,255-PADDLE_THICK,255, color);
}

void drawBall(int x, int y, u16 color){
	int size = BALL_SIZE;
	y = 191-y;
	int top = y-size;
	int bottom = y+size;
	int left = x-size;
	int right = x+size;
	FillRectangle(MAIN, top,bottom,left,right, color);
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
*/
