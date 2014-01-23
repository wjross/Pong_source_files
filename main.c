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
//#include "audio.h"

int main(void) {
	start_graphics();
	//init_audio();
	start_gameplay();
	return 0;
}
