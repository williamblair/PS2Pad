/* test.cpp - test main for PS2Pad,
 * class, to be used with ps2sdk 
 * and libpad 
 *
 * most code taken from example
 * in ps2sdk samples rpc folder,
 * author 'pukko' 
 *
 * William (BJ) Blair
 * 04/27/2017 
 * */

#include <tamtypes.h>
#include <kernel.h>
#include <sifrpc.h>
#include <loadfile.h>
#include <stdio.h>

#include "libpad.h"

#include "PS2Pad.hpp"

int main(int argc, char *argv[])
{

	SifInitRpc(0);

	//PS2Pad pad1(0, 0);
    PS2Pad pad1;
    pad1.init(0,0);

	printf("Hi!\n"
	       "Very welcome to this small and stupid pad test application\n"
	       "Hope you will find the source useful though =)\n"
	       "Please, use & abuse the code, but I would not mind \n"
	       "a small greeting when you do :)\n"
	       "I myself would like to leave a special thanks to Gustavo "
	       "S:\nWithout your psx2lib this would've been impossible\n\n"
	       "                                                 - pukko\n\n");

	for (;;) {		// We are phorever people

		pad1.read();

		//if (pad1.padRet != 0) {

		if (pad1.clicked(PAD_DOWN)) {
			printf("DOWN\n");
		}
		if (pad1.clicked(PAD_RIGHT)) {
			printf("RIGHT\n");
			/*
			   padSetMainMode(port, slot,
			   PAD_MMODE_DIGITAL, PAD_MMODE_LOCK));
			 */
		}
		if (pad1.clicked(PAD_UP)) {
			printf("UP\n");
		}
		if (pad1.clicked(PAD_START)) {
			printf("START\n");
		}
		if (pad1.clicked(PAD_R3)) {
			printf("R3\n");
		}
		if (pad1.clicked(PAD_L3)) {
			printf("L3\n");
		}
		if (pad1.clicked(PAD_SELECT)) {
			printf("SELECT\n");
		}
		if (pad1.clicked(PAD_SQUARE)) {
			printf("SQUARE\n");
			printf("Starting big engine!\n");
			pad1.startBigEngine(255);
		}
		if (pad1.clicked(PAD_CROSS)) {
			pad1.enterPressureMode();
			printf("CROSS - Enter press mode\n");
		}
		if (pad1.clicked(PAD_CIRCLE)) {
			pad1.exitPressureMode();
			printf("CIRCLE - Exit press mode\n");
		}
		if (pad1.clicked(PAD_TRIANGLE)) {
			printf("Stopping big engine!\n");
			pad1.stopBigEngine();
		}
		if (pad1.clicked(PAD_R1)) {
			pad1.startLittleEngine();
			printf("R1 - Start little engine\n");
		}
		if (pad1.clicked(PAD_L1)) {
			pad1.stopLittleEngine();
			printf("L1 - Stop little engine\n");
		}
		if (pad1.clicked(PAD_R2)) {
			printf("R2\n");
		}
		if (pad1.clicked(PAD_L2)) {
			printf("L2\n");
		}

		/* BJ ADDED HERE */
		if (pad1.held(PAD_CROSS)) {
			printf("X\n");
		}

		if (pad1.getPressure(PAD_LEFT)) {
			printf("Left Pressure: %d\n",
			       pad1.getPressure(PAD_LEFT));
		}
		//}
	}			// for

	printf("Goto sleep!\n");
	SleepThread();

	return 0;
}
