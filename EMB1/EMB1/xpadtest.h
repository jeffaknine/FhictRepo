#ifndef XPADTEST_H_
#define XPADTEST_H_
#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <string.h>

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

uint8_t dataOut[20];
int error, transferred;
int speed;
int weight;
//global
libusb_device_handle *h;

//methods
int run();
void doRumble(char *state);
void dataPush(uint8_t *method);
void dataPull(uint8_t *method);
void ledChange(char *state);
char* check(uint8_t *dataOut);
#endif
