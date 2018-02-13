#ifndef __BUDGET_H__
#define __BUDGET_H__
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Account.h"
#include "Envelope.h"
#include "budget_envelope.h"
using namespace std;

class Budget {
private:
  string title;
  int account_count, envelope_count;
	int current_month, current_year;
  Account* accounts;
  Envelope* envelopes;
public:
  Budget();
  ~Budget();
	string getTitle() const;
	int getAccountCount() const;
	int getEnvelopeCount() const;
	Account* getAccounts() const;
	Envelope* getEnvelopes() const;
	int getCurrentMonth() const;
	int getCurrentYear() const;
	void setTitle(string);
	void setAccountCount(int);
	void setEnvelopeCount(int);
	void setAccounts(Account*);
	void setEnvelopes(Envelope*);
	void setCurrentMonth(int);
	void setCurrentYear(int);
	
	void account_deposit(int, double);
	bool account_withdrawal(int, double);

	friend ostream& operator << (ostream&, const Budget&);
	friend ofstream& operator << (ofstream&, const Budget&);
	friend ifstream& operator >> (ifstream&, Budget&);
};

#endif