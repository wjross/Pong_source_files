/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>

int main(void) {
	
    consoleDemoInit();
    printf("\nPong test\n");

    while(1)
        swiWaitForVBlank();	
}
