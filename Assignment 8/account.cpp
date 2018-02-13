#include "account.h"

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

ostream& operator << (ostream& stream, const Account &account) {
	stream << account.id << ": " 
	<< account.title << " - " 
	<< fixed << setprecision(2) << account.balance << endl;
	return stream;
}
ofstream& operator << (ofstream& file, const Account &account) {
	file << account.id << " " 
	<< account.title << " " 
	<< account.balance << endl;
	return file;
}
ifstream& operator >> (ifstream& file, Account &account) {
	string tmp;
	getline(file, tmp, ' ');
	account.id = atoi(tmp.c_str());
	getline(file, tmp, ' ');
	account.title = tmp;
	getline(file, tmp);
	account.balance = atof(tmp.c_str());
	return file;
}