#include "budget_envelope.h"

BudgetEnvelope::BudgetEnvelope() {}

bool BudgetEnvelope::withdraw(double amount) {
	if (balance - amount < 0) {
		return false;
	}
	else {
		balance -= amount;
		return true;
	}
}