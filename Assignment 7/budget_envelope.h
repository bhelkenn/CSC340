#ifndef __BUDGETENVELOPE_H__
#define __BUDGETENVELOPE_H__
#include <iostream>
#include <fstream>
#include "budget_item.h"

class BudgetEnvelope : public BudgetItem {
private:
	
public:
	BudgetEnvelope();
	BudgetEnvelope(int, string, double);
	bool withdraw(double);
	
	friend bool operator < (const BudgetEnvelope&, const BudgetEnvelope&);
	friend bool operator == (const BudgetEnvelope&, const BudgetEnvelope&);
	friend ostream& operator << (ostream&, const BudgetEnvelope&);
	friend ofstream& operator << (ofstream&, const BudgetEnvelope&);
	friend ifstream& operator >> (ifstream&, BudgetEnvelope&);
};

#endif