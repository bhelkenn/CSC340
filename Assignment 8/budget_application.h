#ifndef __BUDGETAPPLICATION_H__
#define __BUDGETAPPLICATION_H__
#include <string>
#include "budget.h"
#include "menu.h"
#include "tree.h"
#include "envelope_box.h"
using namespace std;

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
	void testTreeFunctions();
	void testEnvelopeBox();
};

double userInput();
int collectAccountId();
double collectAmount();
void testTreeInsert(BudgetEnvelope*, Tree<BudgetEnvelope>&);
void testTreeFind(BudgetEnvelope*, Tree<BudgetEnvelope>&);
void testTreeTraverse(Tree<BudgetEnvelope>&);

#endif