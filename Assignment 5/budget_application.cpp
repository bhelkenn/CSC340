#include "budget_application.h"

double userInput();
int collectAccountId();
double collectAmount();

enum Selection {
	EXIT,
	SHOW_BUDGET,
	DEPOSIT,
	WITHDRAW
};

BudgetApplication::BudgetApplication() {
	ifstream load_file;
	load_file >> budget;
}
BudgetApplication::~BudgetApplication() {
	ofstream store_file;
	store_file << budget;
}

void BudgetApplication::prompt_loop() {
	menu.show_menu();
	BudgetApplication::process_menu_selection();
}

bool BudgetApplication::is_running() {
	if (menu.last_selection() == 0) {
		return false;
	}
	else {
		return true;
	}
}

void BudgetApplication::process_menu_selection() {
	Selection selection = static_cast<Selection>(menu.prompt_for_selection());
	switch (selection) {
		case SHOW_BUDGET:
			cout << budget;
			break;
		case DEPOSIT:
			budget.account_deposit(collectAccountId(), collectAmount());
			break;
		case WITHDRAW:
			budget.account_withdrawal(collectAccountId(), collectAmount());
			break;
		case EXIT:
			break;
		default:
			cout << "Something went wrong in BudgetApplication::process_menu_selection()" << endl;
	}
}

double userInput() {
	double input = 0.0;
	cin >> input;
	return input;
}

int collectAccountId() {
	cout << "Enter an account ID: ";
	return static_cast<int>(userInput());
}

double collectAmount() {
	cout << "Enter an amount: ";
	return userInput();
}