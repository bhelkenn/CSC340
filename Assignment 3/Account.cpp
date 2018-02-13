#include "Account.h"

Account::Account() {
	id = 0;
	title = "";
	balance = 0.0;
}

int Account::getId() const {
	return id;
}

string Account::getTitle() const {
	return title;
}

double Account::getBalance() const {
	return balance;
}

void Account::setId(int id) {
	this->id = id;
}

void Account::setTitle(string title) {
	this->title = title;
}

void Account::setBalance(double balance) {
	this->balance = balance;
}