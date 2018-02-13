#include "budget_item.h"

void BudgetItem::deposit(double amount) {
	balance += amount;
}

int BudgetItem::getId() const {
	return id;
}
string BudgetItem::getTitle() const {
	return title;
}
double BudgetItem::getBalance() const {
	return balance;
}

void BudgetItem::setId(int id) {
	this->id = id;
}
void BudgetItem::setTitle(string title) {
	this->title = title;
}
void BudgetItem::setBalance(double balance) {
	this->balance = balance;
}