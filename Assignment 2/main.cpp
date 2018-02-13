#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

enum Selection {
	EXIT,
	SHOW_BUDGET
};

struct Envelope {
	int id;
	string title;
};

struct Account {
	int id;
	string title;
	double balance;
};

struct Budget {
	string title;
	int account_count, envelope_count;
	Account* accounts;
	Envelope* envelopes;
};

void showMenu();
int menuInput();
void processSelection(int, Budget &);
Budget loadBudget();
void loadAccounts(Budget &, ifstream &);
void loadEnvelopes(Budget &, ifstream &);
void showBudget(Budget &);
void showAccounts(Budget &);
void showEnvelopes(Budget &);
void storeBudget(Budget &);
void storeEnvelopes(Budget &, ofstream &);
void storeAccounts(Budget &, ofstream &);
void destroyBudget(Budget &);

int main() {
	showMenu();
	
	return 0;
}

void showMenu() {
	Budget budget = loadBudget();
	
	cout << "1. Show Budget" << endl;
	cout << "0. EXIT" << endl;
	cout << "Enter your selection: ";
	
	processSelection(menuInput(), budget);
}

int menuInput() {
	int input = -1;
	cin >> input;
	
	//validation
	while (input != 0 && input != 1) {
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
			showMenu();
			break;
		case EXIT:
			storeBudget(budget);
			destroyBudget(budget);
			exit(0);
			break;
		default:
			cout << "Something went wrong in processSelection()" << endl;
	}
}

Budget loadBudget() {
	ifstream file;
	Budget budget;
	string tmp;
	
	file.open("BUDGET");
	getline(file, budget.title);
	
	getline(file, tmp);
	budget.envelope_count = atoi(tmp.c_str());
	loadEnvelopes(budget, file);
	
	getline(file, tmp);
	budget.account_count = atoi(tmp.c_str());
	loadAccounts(budget, file);
	
	file.close();
	
	return budget;
}

void loadEnvelopes(Budget &budget, ifstream &file) {
	budget.envelopes = new Envelope[budget.envelope_count];
	for (int loop_count = 0; loop_count < budget.envelope_count; loop_count++) {
		file >> budget.envelopes[loop_count].id 
		>> budget.envelopes[loop_count].title;
	}
	
	string purgeLine;
	getline(file, purgeLine);
}

void loadAccounts(Budget &budget, ifstream &file) {
	budget.accounts = new Account[budget.account_count];
	for (int loop_count = 0; loop_count < budget.account_count; loop_count++) {
		file >> budget.accounts[loop_count].id 
		>> budget.accounts[loop_count].title 
		>> budget.accounts[loop_count].balance;
	}
	
	string purgeLine;
	getline(file, purgeLine);
}

void showBudget(Budget &budget) {
	cout << "----- " << budget.title << " -----" << endl;
	showAccounts(budget);
	cout << endl;
	showEnvelopes(budget);
	cout << endl;
}

void showAccounts(Budget &budget) {
	cout << budget.account_count << " Accounts:" << endl;
	for (int loop_count = 0; loop_count < budget.account_count; loop_count++) {
		cout << budget.accounts[loop_count].id << ": " 
		<< budget.accounts[loop_count].title << " - " 
		<< budget.accounts[loop_count].balance << endl;
	}
}

void showEnvelopes(Budget &budget) {
	cout << budget.envelope_count << " Envelopes:" << endl;
	for (int loop_count = 0; loop_count < budget.envelope_count; loop_count++) {
		cout << budget.envelopes[loop_count].id << ": " 
		<< budget.envelopes[loop_count].title << endl;
	}
}

void storeBudget(Budget &budget) {
	ofstream file;
	file.open("BUDGET", ios::out | ios::trunc);
	
	file << budget.title << endl;
	file << budget.envelope_count << endl;
	storeEnvelopes(budget, file);
	file << budget.account_count << endl;
	storeAccounts(budget, file);
	
	file.close();
}

void storeEnvelopes(Budget &budget, ofstream &file) {
	for (int loop_count = 0; loop_count < budget.envelope_count; loop_count++) {
		file << budget.envelopes[loop_count].id << " " 
		<< budget.envelopes[loop_count].title << endl;
	}
}

void storeAccounts(Budget &budget, ofstream &file) {
	for (int loop_count = 0; loop_count < budget.account_count; loop_count++) {
		file << budget.accounts[loop_count].id << " " 
		<< budget.accounts[loop_count].title << " " 
		<< budget.accounts[loop_count].balance << endl;
	}
}

void destroyBudget(Budget &budget) {
	delete [] budget.accounts;
	budget.accounts = NULL;
	delete [] budget.envelopes;
	budget.envelopes = NULL;
}