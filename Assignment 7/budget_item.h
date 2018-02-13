#ifndef __BUDGETITEM_H__
#define __BUDGETITEM_H__
#include <string>
using namespace std;

class BudgetItem {
protected:
	int id;
	string title;
	double balance;
public:
	void deposit(double);
	virtual bool withdraw(double amount) = 0;
	
	int getId() const;
	string getTitle() const;
	double getBalance() const;
	void setId(int);
	void setTitle(string);
	void setBalance(double);
};

#endif