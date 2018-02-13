#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Envelope.h"
#include "Budget.h"
#include "Account.h"
using namespace std;

enum Selection {
	EXIT,
	SHOW_BUDGET,
	DEPOSIT,
	WITHDRAW
};

void showMenu(Budget &);
void loadBudget(Budget &);
int menuInput();
double userInput();
void processSelection(int, Budget &);
void deposit(Budget &);
bool withdraw(Budget &);
void showBudget(Budget &);
void storeBudget(Budget &);
void storeEnvelopes(Budget &, ofstream &);
void storeAccounts(Budget &, ofstream &);

int main() {
	Budget budget;
	loadBudget(budget);
	showMenu(budget);
	
	return 0;
}

void showMenu(Budget &budget) {
	cout << "1. Show Budget" << endl;
	cout << "2. Make Deposit" << endl;
	cout << "3. Make Withdrawal" << endl;
	cout << "0. EXIT" << endl;
	cout << "Enter your selection: ";
	
	processSelection(menuInput(), budget);
}

void loadBudget(Budget &budget) {
	ifstream file;
	file >> budget;
}

int menuInput() {
	int input = -1;
	cin >> input;
	
	//validation
	while (input < 0 && input > 3) {
		cout << "Incorrect selection! Re-enter: ";
		cin >> input;
	}
	
	return input;
}

void processSelection(int input, Budget &budget) {
	Selection selection = static_cast<Selection>(input);
	switch (selection) {
		case SHOW_BUDGET:
			showBudget(budget);
			showMenu(budget);
			break;
		case DEPOSIT:
			deposit(budget);
			showMenu(budget);
			break;
		case WITHDRAW:
			withdraw(budget);
			showMenu(budget);
			break;
		case EXIT:
			storeBudget(budget);
			exit(0);
			break;
		default:
			cout << "Something went wrong in processSelection()" << endl;
	}
}

double userInput() {
	double input = 0.0;
	cin >> input;
	return input;
}

void deposit(Budget &budget) {
	int account_id;
	double amount;
	cout << "Enter an account ID: ";
	account_id = static_cast<int>(userInput());
	
	cout << "Enter an amount: ";
	amount = userInput();
	
	budget.account_deposit(account_id, amount);
}

bool withdraw(Budget &budget) {
	int account_id;
	double amount;
	cout << "Enter an account ID: ";
	account_id = static_cast<int>(userInput());
	
	cout << "Enter an amount: ";
	amount = userInput();
	
	return budget.account_withdrawal(account_id, amount);
}

void showBudget(Budget &budget) {
	cout << budget;
}

void storeBudget(Budget &budget) {
	ofstream file;
	file.open("BUDGET", ios::out | ios::trunc);
	
	file << budget.getTitle() << endl;
	file << budget.getEnvelopeCount() << endl;
	storeEnvelopes(budget, file);
	file << budget.getAccountCount() << endl;
	storeAccounts(budget, file);
	
	file.close();
}

void storeEnvelopes(Budget &budget, ofstream &file) {
	for (int loop_count = 0; loop_count < budget.getEnvelopeCount(); loop_count++) {
		Envelope* envelopes = budget.getEnvelopes();
		file << envelopes[loop_count].getId() << " " 
		<< envelopes[loop_count].getTitle() << endl;
	}
}

void storeAccounts(Budget &budget, ofstream &file) {
	for (int loop_count = 0; loop_count < budget.getAccountCount(); loop_count++) {
		Account* accounts = budget.getAccounts();
		file << accounts[loop_count].getId() << " " 
		<< accounts[loop_count].getTitle() << " " 
		<< accounts[loop_count].getBalance() << endl;
	}
}