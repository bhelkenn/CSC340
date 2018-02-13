#include "budget_envelope.h"

BudgetEnvelope::BudgetEnvelope() {}
BudgetEnvelope::BudgetEnvelope(int id, string title, double balance) {
	this->id = id;
	this->title = title;
	this->balance = balance;
}

bool BudgetEnvelope::withdraw(double amount) {
	if (balance - amount < 0) {
		return false;
	}
	else {
		balance -= amount;
		return true;
	}
}

bool operator < (const BudgetEnvelope &be1, const BudgetEnvelope &be2) {
	if (be1.id < be2.id)
		return true;
	else
		return false;
}
bool operator == (const BudgetEnvelope &be1, const BudgetEnvelope &be2) {
	if (be1.id == be2.id)
		return true;
	else
		return false;
}
ostream& operator << (ostream& stream, const BudgetEnvelope &be) {
	stream << be.id << " " << be.title << " " << be.balance << ".";
	return stream;
}