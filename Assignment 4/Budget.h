#ifndef __BUDGET_H__
#define __BUDGET_H__
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "Account.h"
#include "Envelope.h"
using namespace std;

class Budget {
private:
  string title;
  int account_count, envelope_count;
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
	void setTitle(string);
	void setAccountCount(int);
	void setEnvelopeCount(int);
	void setAccounts(Account*);
	void setEnvelopes(Envelope*);
	
	void account_deposit(int, double);
	bool account_withdrawal(int, double);

	friend ostream& operator << (ostream&, const Budget&);
	friend ofstream& operator << (ofstream&, const Budget&);
	friend ifstream& operator >> (ifstream&, Budget&);
};

#endif