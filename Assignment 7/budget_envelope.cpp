#include "budget_envelope.h"

BudgetEnvelope::BudgetEnvelope() {}
BudgetEnvelope::BudgetEnvelope(int id, string title, double balance) {
	this->id = id;
	this->title = title;
	this->balance = balance;
}

bool BudgetEnvelope::withdraw(double amount) {
	if (balance >= amount) {
		balance -= amount;
		return true;
	}
	else
		return false;
}

bool operator < (const BudgetEnvelope &be1, const BudgetEnvelope &be2) {
	return be1.id < be2.id;
}
bool operator == (const BudgetEnvelope &be1, const BudgetEnvelope &be2) {
	return be1.id == be2.id;
}
ostream& operator << (ostream& stream, const BudgetEnvelope &be) {
	stream << "[" << be.id << "] " << be.title << ": " << be.balance << endl;
	return stream;
}
ofstream& operator << (ofstream& file, const BudgetEnvelope &be) {
	file << be.id << endl;
	file << be.title << endl;
	file << be.balance << endl;
	
	return file;
}
ifstream& operator >> (ifstream& file, BudgetEnvelope &be) {
	string tmp;
	getline(file, tmp);
	be.id = atoi(tmp.c_str());
	
	getline(file, be.title);
	
	getline(file, tmp);
	be.id = atof(tmp.c_str());
	
	return file;
}