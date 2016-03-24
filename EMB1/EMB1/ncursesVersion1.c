#include "ncursesVersion1.h"
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
char *led[] = {
			"All blink",
			"All flashes, then on",
			"Circle blinking",
			"< -- Exit",

		};
		
int n_choices = sizeof(choices) / sizeof(char *);
int t_choices = sizeof(text) / sizeof(char *);
int l_choices = sizeof(led) / sizeof(char *);

void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

void print_second_menu(WINDOW *second_menu, int highlight)
{
	int x, y, i;	
	x = 4;
	y = 2;
	box(second_menu, 0, 0);
	wrefresh(second_menu);
}

void printInSecondMenu(WINDOW *second_menu,int choice)
{
	switch(choice)
		{	
			case 1:
				//mvwprintw(second_menu, secondY, secondX, "%s", "Button pressed : ",check(dataOut));
				//++secondY;
			break;
			case 2:
				mvwprintw(second_menu, secondY, secondX, "%s", choices[1]);
				++secondY;
			break;
			case 3:
				mvwprintw(second_menu, secondY, secondX, "%s", choices[2]);
				++secondY;
			break;
		}
	wrefresh(second_menu);
}

void leds_menu(WINDOW *led_menu,int hightlight)
{
	int x ,y ,i;
	x = 2;
	y =2;
	box(led_menu,0,0);
	for(i = 0;i< l_choices; ++i)
	{
		if(hightlight == i +1)
		{
			wattron(led_menu, A_REVERSE); 
			mvwprintw(led_menu, y, x, "%s", led[i]);
			wattroff(led_menu, A_REVERSE);
		}
		else
			mvwprintw(led_menu, y, x, "%s", led[i]);
		++y;
		}
		wrefresh(led_menu);
}
