#ifndef __BUDGETAPPLICATION_H__
#define __BUDGETAPPLICATION_H__
#include "Budget.h"
#include "Menu.h"

class BudgetApplication {
private:
	Budget budget;
	Menu menu;
	void process_menu_selection();
public:
	BudgetApplication();
	~BudgetApplication();
	bool is_running();
	void prompt_loop();
};

#endif