#ifndef __BUDGETENVELOPE_H__
#define __BUDGETENVELOPE_H__
#include "budget_item.h"

class BudgetEnvelope : public BudgetItem {
private:
	
public:
	BudgetEnvelope();
	bool withdraw(double);
};

#endif