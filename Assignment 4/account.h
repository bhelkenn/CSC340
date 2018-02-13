#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "budget_item.h"
using namespace std;

class Account : public BudgetItem {
public:
  Account();
	
	bool withdraw(double);
};

#endif