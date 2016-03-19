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

	while(1)
	{
		if ((error = libusb_interrupt_transfer(h, endpOut, dataOut, sizeof dataOut, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: reading", error);
		}
		
		printf("Button pressed : %s\n",check(dataOut));
		
		unsigned char led[] = {1,2,0x00};
		
		ledChange(dataOut);
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
		unsigned char led[] = {1,2,ledOne};
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: led1", error);
		}		
	}
	else if ((dataOut[2]>>1)&one)
	{
		unsigned char led[] = {1,2,ledTwo};
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: led2", error);
		}	
	}
	else if ((dataOut[2]>>2)&one)
	{
		unsigned char led[] = {1,2,ledThree};
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: led3", error);
		}	
	}
	else if ((dataOut[2]>>3)&one)
	{
		unsigned char led[] = {1,2,ledFour};
		if ((error = libusb_interrupt_transfer(h, endpIn, led, sizeof led, &transferred, 0)) != 0)
		{
			fprintf(stderr, "Transfer failed: led4", error);
		}	
	}
	if(((dataOut[2]>>3)&one) || ((dataOut[2]>>2)&one) || ((dataOut[2])&one) || ((dataOut[2]>>1)&one)){
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

char check(uint8_t *dataOut)
{
	char value;
	printf("\n");
	if (((dataOut[3]>>4)&one) )
	{
		return value = 'A';
	}
	else if ((dataOut[3]>>5)&one)
	{
		return value ='B';
		exit(0);
	}
	else if ((dataOut[3]>>6)&one)
	{
		return value ='X';
	}
	else if ((dataOut[3]>>7)&one)
	{
		return  value ='Y';
	}
	else if ((dataOut[3]>>1)&one)
	{
		return value ="RB";
	}
	else if ((dataOut[3]>>0)&one)
	{
		return value ="LB";
	}
	else if ((dataOut[2]>>4)&one)
	{
		return value = "Start";
	}
	else if ((dataOut[2]>>5)&one)
	{
		return value = "Back";
	}
	else if ((dataOut[3]>>2)&one)
	{
		return value = "Xbox Button";

	}
	else if ((dataOut[5])> 0)
	{
		return value = "Right Trigger";
	}
	else if ((dataOut[4])> 0)
	{
		return value = "Left Trigger";
	}
	
	else if ((dataOut[2]>>6)&one)
	{
		return value = "Left Stick";
	}
	else if ((dataOut[2]>>7)&one)
	{
		return value = "Right Stick";
	}
}