#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "budget_item.h"
using namespace std;

class Account : public BudgetItem {
public:
  Account();
	
	bool withdraw(double);
	
	friend ostream& operator << (ostream&, const Account&);
	friend ofstream& operator << (ofstream&, const Account&);
	friend ifstream& operator >> (ifstream&, Account&);
};

#endif