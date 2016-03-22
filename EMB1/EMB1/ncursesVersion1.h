#ifndef NCURSESVERSION1_H_
#define NCURSESVERSION1_H_
#include <stdio.h>
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10 

int startx = 0;
int starty = 0;
int secondX = 4;
int secondY = 2;

char *choices[] = { 
			"Check the states",
			"Control LED -- >",
			"Rubmle",
			"Exit",
		  };
char *text[] = {
			"Check the statesfjkgjdf",
			"Control LED",
			"Rubmle",
			"Exit",

		};
char *led[] = {
			"All blink",
			"1 by 1",
			"Circle blinking",
			"< -- Exit",

		};
		
int n_choices = sizeof(choices) / sizeof(char *);
int t_choices = sizeof(text) / sizeof(char *);
int l_choices = sizeof(led) / sizeof(char *);

void print_menu(WINDOW *menu_win, int highlight);
void print_second_menu(WINDOW *second_menu, int highlight);
void printInSecondMenu(WINDOW *second_menu, int highlight);
void leds_menu(WINDOW *led_menu, int hightlight);
#endif
