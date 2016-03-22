#include "ncursesVersion1.h"
 
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
				mvwprintw(second_menu, secondY, secondX, "%s", text[0]);
				++secondY;
			break;
			case 2:
				mvwprintw(second_menu, secondY, secondX, "%s", text[1]);
				++secondY;
			break;
			case 3:
				mvwprintw(second_menu, secondY, secondX, "%s", text[2]);
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
