#define vid 0x045e	//vendor ID
#define pid 0x028e	//product ID
#define one 0x01
#define endpOut 0x81 // to read
#define endpIn 0x01	//to write


#define ledOne 0x06
#define ledTwo 0x07
#define ledThree 0x08
#define ledFour 0x09
#define blink 0x01
#define off 0x00

#define mid 0x7F

#include <libusb-1.0/libusb.h>
#include <stdio.h>

uint8_t speed = 0x00;
uint8_t weight = 0x00;

int error, transferred;
libusb_device_handle *h;

int main(int argc, char *argv[])
{
	uint8_t dataOut[20];
	unsigned char dataIn[] = {1,3,0x00};

	libusb_init(NULL);

	h = libusb_open_device_with_vid_pid(NULL, vid, pid);
	libusb_set_auto_detach_kernel_driver(h,0);
	libusb_claim_interface(h, 0);
	
	unsigned char led = off;

	if (h == NULL) {
		fprintf(stderr, "Failed to open device\n");
		return (1);
	}

	// if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
	// 	{
	// 		fprintf(stderr, "Transfer failed: off led", error);
	// 	}

	while(1)
	{
		if ((error = libusb_interrupt_transfer(h, endpOut, dataOut, sizeof dataOut, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: reading", error);
		}
		
		check(dataOut);

		if ((dataOut[2])&one)
	{
		printf("D-pad Up was pressed");	
		unsigned char led[] = {1,2,ledOne};
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: led1", error);
		}		
	}
		
		unsigned char led[] = {1,2,0x00};
		
		// ledChange(dataOut);
		rumble(dataOut);
		
	}
	return (0);
}


void rumble(uint8_t *dataOut)
{
		uint8_t rumble[] = {0x00, 0x08, 0x00, speed, weight, 0x00, 0x00, 0x00};	

		if (((dataOut[3]>>4)&one) )
		{
			speed = mid;
			weight = mid;	
		}

		else
		{
			speed = 0x00;
			weight = 0x00;
		}
		if ((error = libusb_interrupt_transfer(h, endpIn, rumble, sizeof rumble, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: rumble", error);
		}
}

void ledChange(uint8_t *dataOut)
{
	if ((dataOut[2])&one)
	{
		printf("D-pad Up was pressed");	
		unsigned char led[] = {1,2,ledOne};
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: led1", error);
		}		
	}
	else if ((dataOut[2]>>1)&one)
	{
		printf("D-pad Down was pressed");
		unsigned char led[] = {1,2,ledTwo};
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: led2", error);
		}	
	}
	else if ((dataOut[2]>>2)&one)
	{
		printf("D-pad Left was pressed");
		printf("D-pad Up was pressed");	
		unsigned char led[] = {1,2,ledThree};
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: led3", error);
		}	
	}
	else if ((dataOut[2]>>3)&one)
	{
		printf("D-pad Right was pressed");
		printf("D-pad Up was pressed");	
		unsigned char led[] = {1,2,ledFour};
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: led4", error);
		}	
	}
	if(((dataOut[2]>>3)&one) || ((dataOut[2]>>2)&one) || ((dataOut[2])&one) || ((dataOut[2]>>1)&one)){
		printf("all pressed");
	}
	else
	{
		unsigned char led[] = {1,2,0x00};
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: led1", error);
		}	
	}
}

void check(uint8_t *dataOut)
{
	printf("\n");
	if (((dataOut[3]>>4)&one) )
	{
		printf("A was pressed");
	}
	else if ((dataOut[3]>>5)&one)
	{
		printf("B was pressed");
		exit(0);
	}
	else if ((dataOut[3]>>6)&one)
	{
		printf("X was pressed");
	}
	else if ((dataOut[3]>>7)&one)
	{
		printf("Y was pressed");
	}
	else if ((dataOut[3]>>1)&one)
	{
		printf("RB was pressed");
	}
	else if ((dataOut[3]>>0)&one)
	{
		printf("LB was pressed");
	}
	else if ((dataOut[2]>>4)&one)
	{
		printf("Start was pressed");
	}
	else if ((dataOut[2]>>5)&one)
	{
		printf("Back was pressed");
	}
	else if ((dataOut[3]>>2)&one)
	{
		printf("XBox button was pressed\n");
		printf("Xbox off");

	}
	else if ((dataOut[5])> 0)
	{
		printf("RT was pressed");
	}
	else if ((dataOut[4])> 0)
	{
		printf("LT was pressed");
	}
	
	else if ((dataOut[2]>>6)&one)
	{
		printf("Left Stick was pressed");
	}
	else if ((dataOut[2]>>7)&one)
	{
		printf("Right stick was pressed");
	}
	printf("\n");
}
// void exchange(libusb_device_handle *h, unsigned char endp, unsigned char data,int* transferred)
// {
	// if ((error = libusb_interrupt_transfer(h, endp, data, sizeof data, &transferred, 0)) != 0)
	// 	{
	// 		fprintf(stderr, "Transfer failed: out", error);
	// 	}
// }