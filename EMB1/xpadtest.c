#include "xpadtest.h"
int speed = 0x00;
int weight = 0x00;

int run()
{
	//libusb_set_auto_detach_kernel_driver(h,0);
	libusb_init(NULL);
	h = libusb_open_device_with_vid_pid(NULL, vid, pid);
	libusb_set_auto_detach_kernel_driver(h,0);
	libusb_claim_interface(h, 0);
	if (h == NULL) {return 1;}//return 0;
}

void doRumble(char *state)
{	
	uint8_t	rumble[]={0x00, 0x08, 0x00, speed, weight, 0x00, 0x00, 0x00};
	if (strcmp(state,"Rumble")!=0)
	{
		speed = mid;
		weight = mid;	
	}

	if (strcmp(state,"Stop Rumble")!=0)
	{
		speed = 0x00;
		weight = 0x00;
	}
	if ((error = libusb_interrupt_transfer(h, endpIn, rumble, sizeof rumble, &transferred, 0)) != 0)
	 	{
	 		fprintf(stderr, "Transfer failed: rumble", error);
	 	}
	//dataPush(rumble);
}

// void dataPush(uint8_t *plop)
// {
// 	if ((error = libusb_interrupt_transfer(h, endpIn, plop, sizeof plop, &transferred, 0)) != 0)
// 		{
// 			fprintf(stderr, "Transfer failed: rumble", error);
// 		}
// 	//else return 0;			
// }

// void dataPull(uint8_t *plop)
// {
// 	libusb_interrupt_transfer(h, endpOut, plop, sizeof plop, &transferred, 0);//) != 0){return 1;}
// 	//return 0;
// }

void ledChange(char *state)
{
	uint8_t led[3];
	led[0] = 1;
	led[1] = 2;
	led[2] = 0x00;
	if (strcmp(state,"All Blink")!=0)
	{
		led[2] = 0x01;
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: rumble", error);
		}
	}
	if (strcmp(state,"All flashes, then on")!=0)
	{
		led[2] = 0x05;
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: rumble", error);
		}
		//dataPush(led);
	}
	if (strcmp(state,"Circle blinking")!=0)
	{
		led[2] = 0x0A;
		int error;
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: %d\n", error);
		}
		//dataPush(led);
	}
}

char* check()
{
	uint8_t dataOut[20];
		if ((error = libusb_interrupt_transfer(h, endpOut, dataOut, sizeof dataOut, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: reading", error);
		}
		if (((dataOut[3]>>4)&one)){return "A                 ";}
	else if ((dataOut[3]>>5)&one){return  "B                 ";}
	else if ((dataOut[3]>>6)&one){return  "X                 ";}
	else if ((dataOut[3]>>7)&one){return  "Y                 ";}
	else if ((dataOut[2]>>0)&one){return  "D-Pad up          ";}
	else if ((dataOut[2]>>1)&one){return  "D-Pad down        ";}
	else if ((dataOut[2]>>2)&one){return  "D-Pad left        ";}
	else if ((dataOut[2]>>3)&one){return  "D-Pad Right       ";}
	else if ((dataOut[3]>>1)&one){return  "RB                ";}
	else if ((dataOut[3]>>0)&one){return  "LB                ";}
	else if ((dataOut[2]>>4)&one){return  "Start             ";}
	else if ((dataOut[2]>>5)&one){return  "Back              ";}
	else if ((dataOut[3]>>2)&one){return  "XBox button       ";}
	else if ((dataOut[5])> 0)    {return  "RT                ";}
	else if ((dataOut[4])> 0)    {return  "LT                ";}
	else if ((dataOut[2]>>6)&one){return  "Left Stick        ";}
	else if ((dataOut[2]>>7)&one){return  "Right stick       ";}
	//else if (((dataOut[6]>0)&one)){return "Left Stick X-Axis %d",dataOut[11];}
	return "                      ";		
}
