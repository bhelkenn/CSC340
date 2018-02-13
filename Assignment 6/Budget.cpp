#include "Budget.h"

Budget::Budget() {
  title = "";
	account_count = 0;
	envelope_count = 0;
	current_month = 0;
	current_year = 0;
}
Budget::~Budget() {
  delete [] accounts;
  accounts = NULL;
  delete [] envelopes;
  envelopes = NULL;
}

string Budget::getTitle() const {
	return title;
}
int Budget::getAccountCount() const {
	return account_count;
}
int Budget::getEnvelopeCount() const {
	return envelope_count;
}
Account* Budget::getAccounts() const {
	return accounts;
}
Envelope* Budget::getEnvelopes() const {
	return envelopes;
}
int Budget::getCurrentMonth() const {
	return current_month;
}
int Budget::getCurrentYear() const {
	return current_year;
}

void Budget::setTitle(string title) {
	this->title = title;
}
void Budget::setAccountCount(int account_count) {
	this->account_count = account_count;
}
void Budget::setEnvelopeCount(int envelope_count) {
	this->envelope_count = envelope_count;
}
void Budget::setAccounts(Account* accounts) {
	this->accounts = accounts;
}
void Budget::setEnvelopes(Envelope* envelopes) {
	this->envelopes = envelopes;
}
void Budget::setCurrentMonth(int current_month) {
	this->current_month = current_month;
}
void Budget::setCurrentYear(int current_year) {
	this->current_year = current_year;
}

void Budget::account_deposit(int account_id, double amount) {
	for (int loop_count = 0; loop_count < account_count; loop_count++) {
		if (accounts[loop_count].getId() == account_id) {
			accounts[loop_count].deposit(amount);
			return;
		}
	}
}
bool Budget::account_withdrawal(int account_id, double amount) {
	for (int loop_count = 0; loop_count < account_count; loop_count++) {
		if (accounts[loop_count].getId() == account_id) {
			return accounts[loop_count].withdraw(amount);
		}
	}
	//if account_id not found
	return false;
}

Envelope* loadEnvelopes(ifstream& file, Budget &budget) {
	Envelope* envelopes = new Envelope[budget.getEnvelopeCount()];
  for (int loop_count = 0; loop_count < budget.getEnvelopeCount(); loop_count++) {
		file >> envelopes[loop_count];
  }
	return envelopes;
}
Account* loadAccounts(ifstream& file, Budget &budget) {
	Account* accounts = new Account[budget.getAccountCount()];
  for (int loop_count = 0; loop_count < budget.getAccountCount(); loop_count++) {
    file >> accounts[loop_count];
  }
	return accounts;
}

ostream& operator << (ostream& stream, const Budget &budget) {
  stream << "----- " << budget.title << " -----" << endl;
	stream << "Current Budget Month: " << budget.current_month << " " << budget.current_year << endl;
  stream << budget.account_count << " Accounts:" << endl;
	
	for (int loop_count = 0; loop_count < budget.account_count; loop_count++) {
    stream << budget.accounts[loop_count];
  }
  stream << endl;
  
	stream << budget.envelope_count << " Envelopes:" << endl;
  for (int loop_count = 0; loop_count < budget.envelope_count; loop_count++) {
    stream << budget.envelopes[loop_count];
  }
  stream << endl;
  
  return stream;
}
ofstream& operator << (ofstream& file, const Budget &budget) {
  file.open("BUDGET", ios::trunc | ios::out);
  
  file << budget.title << endl;
  file << budget.envelope_count << endl;
	
  for (int loop_count = 0; loop_count < budget.envelope_count; loop_count++) {
    file << budget.envelopes[loop_count];
  }
  
  file << budget.account_count << endl;
	
  for (int loop_count = 0; loop_count < budget.account_count; loop_count++) {
    file << budget.accounts[loop_count];
  }
	
	file << budget.current_month << " " << budget.current_year << endl;
  
  file.close();
  return file;
}
ifstream& operator >> (ifstream& file, Budget &budget) {
  string tmp;
  file.open("BUDGET");
  
	getline(file, tmp);
	budget.title = tmp;
  
  getline(file, tmp);
  budget.envelope_count = atoi(tmp.c_str());
	
	budget.envelopes = loadEnvelopes(file, budget);
	
  getline(file, tmp);
  budget.account_count = atoi(tmp.c_str());
	
	budget.accounts = loadAccounts(file, budget);
	
	getline(file, tmp, ' ');
	budget.current_month = atoi(tmp.c_str());
	getline(file, tmp);
	budget.current_year = atoi(tmp.c_str());
  
  file.close();
  return file;
}