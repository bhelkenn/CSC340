#ifndef __MENU_H__
#define __MENU_H__
#include <iostream>

class Menu {
private:
	int selection;
public:
	Menu();
	void show_menu();
	int prompt_for_selection();
	int last_selection();
};

#endif