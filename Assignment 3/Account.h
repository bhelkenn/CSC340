#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <cstdlib>
#include <string>
using namespace std;

class Account {
private:
  int id;
  string title;
  double balance;
public:
  Account();
	int getId() const;
	string getTitle() const;
	double getBalance() const;
	void setId(int);
	void setTitle(string);
	void setBalance(double);
};

#endif