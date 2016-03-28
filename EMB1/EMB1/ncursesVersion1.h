#ifndef NCURSESVERSION1_H_
#define NCURSESVERSION1_H_
#include <stdio.h>
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10 

int startx;
int starty;
int secondX;
int secondY;

char *choices[5];
char *text[4];
char *led[4];
		
int n_choices;
int t_choices;
int l_choices;

void print_menu(WINDOW *menu_win, int highlight);
void print_second_menu(WINDOW *second_menu, int highlight);
void printInSecondMenu(WINDOW *second_menu, int highlight);
void leds_menu(WINDOW *led_menu, int hightlight);
#endif
