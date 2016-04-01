#include "xpadtest.h"
#include "ncursesVersion1.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef enum
{
	STATE_IDLE,
	STATE_ACTIVE,
}	STATE_t;

typedef enum
{
	EVENT_A,
	EVENT_UP,
	EVENT_DOWN,
	EVENT_NONE
}	EVENT_t;

EVENT_t ev;
STATE_t state;
EVENT_t event;
EVENT_t getEvent(void)
{
	ev = EVENT_NONE;
	char* value = check();
	if (strcmp(value,"D-Pad down        ")==0){ev = EVENT_DOWN;}
	if (strcmp(value,"D-Pad up          ")==0){ev = EVENT_UP;}
	if (strcmp(value,"A                 ")==0){ev = EVENT_A;}
	return (ev);
}
int main()
{
	WINDOW *menu_win;
	WINDOW *second_menu;
	WINDOW *led_menu;
	
	int highlight = 1;
	int ledhighlight = 1;
	int choice = 0;
	int ledchoice = 0;
	int c;
	int l;
	bool led_menu_selected = false;
	libusb_init(NULL);

	h = libusb_open_device_with_vid_pid(NULL, vid, pid);
	libusb_set_auto_detach_kernel_driver(h,0);
	libusb_claim_interface(h, 0);
	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = 10;
	starty = (24 - HEIGHT) / 2;
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	second_menu = newwin(HEIGHT, (WIDTH*2), (starty),(startx*4));
	led_menu = newwin(HEIGHT, (WIDTH*2), (starty),(startx*4));
	keypad(menu_win, TRUE);
	refresh();
	print_menu(menu_win, highlight);
	print_second_menu(second_menu,highlight);
	scrollok(second_menu,TRUE);
	while(1)
	{	
		if(led_menu_selected == false)
		{
			event = getEvent();
			usleep(100000);
			state = STATE_IDLE;
			switch(state)
			{	
				
				case STATE_IDLE:
				switch (event)
				{
					case EVENT_UP:
					if(highlight == 1){highlight = n_choices;}
					else{--highlight;}
					state=STATE_ACTIVE;
					break;
					case EVENT_DOWN:
					if(highlight == n_choices){highlight = 1;}
					else{++highlight;}
					state=STATE_ACTIVE;
					break;
					case EVENT_NONE:
					state = STATE_ACTIVE;
					break;
					case EVENT_A:
					choice = highlight;
					printInSecondMenu(second_menu,choice);
					if(choice==1)
					{
						
						while(strcmp(check(),"Back              ")!=0)
						{
							mvwprintw(second_menu, secondY, secondX, "Button pressed : %s",check());
							printInSecondMenu(second_menu,choice);
							refresh();
							print_second_menu(second_menu,1);

						}
					}
					if(choice == 3 ){doRumble(choices[3]);}
					if(choice == 4 ){doRumble(choices[4]);}
					if(choice == 2 ){led_menu_selected=true;keypad(menu_win,FALSE);keypad(led_menu,TRUE);leds_menu(led_menu,ledhighlight);refresh();}
					if(led_menu_selected == true)
					{
						while(1)
						{
							event = getEvent();
							usleep(100000);
							state = STATE_IDLE;
							switch(state)
							{
								case STATE_IDLE:
								switch(event)
								{	
									case EVENT_UP:
									if(ledhighlight == 1){ledhighlight = l_choices;}
									else{--ledhighlight;}
									state=STATE_ACTIVE;
									break;
									case EVENT_DOWN:
									if(ledhighlight == l_choices){ledhighlight = 1;}
									else{++ledhighlight;}
									state=STATE_ACTIVE;
									break;
									case EVENT_NONE:
									state = STATE_ACTIVE;
									break;
									case EVENT_A:
										ledchoice = ledhighlight;
										leds_menu(led_menu,ledhighlight);
										if (ledchoice == 1){ledChange(led[1]);printf("plop\n");}
										if (ledchoice == 2){ledChange(led[2]);printf("slop\n");}
										if (ledchoice == 3){ledChange(led[3]);printf("blop\n");}
										if (ledchoice == 4){led_menu_selected=false;keypad(menu_win,TRUE);keypad(led_menu,FALSE);print_second_menu(second_menu,highlight);refresh(); l= 0;ledchoice=0;break;}//ledmenuOFF
								}
							}
							
							
						}
					}
					if(choice == 5){exit(0);}
					break;	
				}
				case STATE_ACTIVE:
				break;
			}
			
		}
			
			
		
		
		print_menu(menu_win, highlight);
		refresh();
	}	
	clrtoeol();
	refresh();
	endwin();
}

