#include "xpadtest.h"
int run()
{
	//libusb_set_auto_detach_kernel_driver(h,0);
	libusb_init(NULL);
	h = libusb_open_device_with_vid_pid(NULL, vid, pid);
	libusb_claim_interface(h, 0);
	if (h == NULL) {return 0;}return 1;
}

void doRumble(uint8_t *dataOut)
{	
	if (((dataOut[3]>>4)&one) ){
		speed = mid;
		weight = mid;	
	}

	else{
		speed = 0x00;
		weight = 0x00;
	}
	uint8_t	rumble[8]={0x00, 0x08, 0x00, speed, weight, 0x00, 0x00, 0x00};
}

int dataPush(uint8_t *method)
{
	if ((error = libusb_interrupt_transfer(h, endpIn, method, sizeof method, &transferred, 0)) != 0){return 0;}
	else return 1;			
}

int dataPull(uint8_t *method)
{
	if ((error = libusb_interrupt_transfer(h, endpOut, method, sizeof method, &transferred, 0)) == 0){return 0;}
	return 1;
}

void ledChange(uint8_t *dataOut)
{
	uint8_t led[3];
	led[0] = 1;
	led[1] = 2;
	led[2] = 0x00;
	if ((dataOut[2])&one)        {led[2] = ledOne;}//printf("D-pad Up was pressed");
	else if ((dataOut[2]>>1)&one){led[2] = ledTwo;}//printf("D-pad Down was pressed");
	else if ((dataOut[2]>>2)&one){led[2]=ledThree;}//printf("D-pad Left was pressed");
	else if ((dataOut[2]>>3)&one){led[2] = ledFour;}//printf("D-pad Right was pressed");
	else{led[2] = 0x00;}
}

char* check(uint8_t *dataOut)
{
	if      (((dataOut[3]>>4)&one)){return "A was pressed";}
	else if ((dataOut[3]>>5)&one){return "B was pressed";}
	else if ((dataOut[3]>>6)&one){return "X was pressed";}
	else if ((dataOut[3]>>7)&one){return "Y was pressed";}
	else if ((dataOut[3]>>1)&one){return "RB was pressed";}
	else if ((dataOut[3]>>0)&one){return "LB was pressed";}
	else if ((dataOut[2]>>4)&one){return "Start was pressed";}
	else if ((dataOut[2]>>5)&one){return "Back was pressed";}
	else if ((dataOut[3]>>2)&one){return "XBox button was pressed";}
	else if ((dataOut[5])> 0)    {return "RT was pressed";}
	else if ((dataOut[4])> 0)    {return "LT was pressed";}
	else if ((dataOut[2]>>6)&one){return "Left Stick was pressed";}
	else if ((dataOut[2]>>7)&one){return "Right stick was pressed";}
	return "0";
}
