#include "Menu.h"

using namespace std;

int validatedMenuInput(int);

Menu::Menu() {
	selection = -1;
}

void Menu::show_menu() {
	cout << "1. Show Budget" << endl;
	cout << "2. Make Deposit" << endl;
	cout << "3. Make Withdrawal" << endl;
	cout << "4. Make Deposit to Envelope" << endl;
	cout << "5. Make Withdrawal from Envelope" << endl;
	cout << "0. EXIT" << endl;
	cout << "Enter your selection: ";
}

int Menu::prompt_for_selection() {
	cin >> selection;
	return validatedMenuInput(selection);
}

int Menu::last_selection() {
	return selection;
}

int validatedMenuInput(int selection) {
	while (selection < 0 || selection > 5) {
		cout << "Incorrect selection! Re-enter: ";
		cin >> selection;
	}
	
	return selection;
}