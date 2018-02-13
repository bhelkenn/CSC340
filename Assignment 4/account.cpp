#include "Account.h"

Account::Account() {
	id = 0;
	title = "";
	balance = 0.0;
}

bool Account::withdraw(double amount) {
	balance -= amount;
	if (balance < 0) {
		return false;
	}
	else {
		return true;
	}
}