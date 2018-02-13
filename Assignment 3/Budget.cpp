#include "Budget.h"

Budget::Budget() {
  title = "";
	account_count = 0;
	envelope_count = 0;
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

ostream& operator << (ostream& stream, const Budget &budget) {
  stream << "----- " << budget.getTitle() << " -----" << endl;
  stream << budget.getAccountCount() << " Accounts:" << endl;
	Account* accounts = budget.getAccounts();
  for (int loop_count = 0; loop_count < budget.getAccountCount(); loop_count++) {
    stream << accounts[loop_count].getId() << ": " 
    << accounts[loop_count].getTitle() << " - " 
    << accounts[loop_count].getBalance() << endl;
  }
  stream << endl;
  
	Envelope* envelopes = budget.getEnvelopes();
  stream << budget.getEnvelopeCount() << " Envelopes:" << endl;
  for (int loop_count = 0; loop_count < budget.getEnvelopeCount(); loop_count++) {
    stream << envelopes[loop_count].getId() << ": " 
    << envelopes[loop_count].getTitle() << endl;
  }
  stream << endl;
  
  return stream;
}

ofstream& operator << (ofstream& file, const Budget &budget) {
  file.open("BUDGET", ios::trunc | ios::out);
  
  file << budget.getTitle() << endl;
  
  file << budget.getEnvelopeCount() << endl;
  Envelope* envelopes = budget.getEnvelopes();
  for (int loop_count = 0; loop_count < budget.getEnvelopeCount(); loop_count++) {
    file << envelopes[loop_count].getId() << " " 
    << envelopes[loop_count].getTitle() << endl;
  }
  
  file << budget.getAccountCount() << endl;
  Account* accounts = budget.getAccounts();
  for (int loop_count = 0; loop_count < budget.getAccountCount(); loop_count++) {
    file << accounts[loop_count].getId() << " " 
    << accounts[loop_count].getTitle() << " " 
    << accounts[loop_count].getBalance() << endl;
  }
  
  file.close();
  return file;
}

ifstream& operator >> (ifstream& file, Budget &budget) {
  string tmp;
  
  file.open("BUDGET");
  getline(file, tmp);
	budget.setTitle(tmp);
  
  getline(file, tmp);
  budget.setEnvelopeCount(atoi(tmp.c_str()));
  Envelope* envelopes = new Envelope[budget.getEnvelopeCount()];
  for (int loop_count = 0; loop_count < budget.getEnvelopeCount(); loop_count++) {
		getline(file, tmp, ' ');
		envelopes[loop_count].setId(atoi(tmp.c_str()));
    getline(file, tmp);
		envelopes[loop_count].setTitle(tmp);
  }
	budget.setEnvelopes(envelopes);
	
  getline(file, tmp);
  budget.setAccountCount(atoi(tmp.c_str()));
  Account* accounts = new Account[budget.getAccountCount()];
  for (int loop_count = 0; loop_count < budget.getAccountCount(); loop_count++) {
    getline(file, tmp, ' ');
		accounts[loop_count].setId(atoi(tmp.c_str()));
    getline(file, tmp, ' ');
		accounts[loop_count].setTitle(tmp);
    getline(file, tmp);
		accounts[loop_count].setBalance(atof(tmp.c_str()));
  }
	budget.setAccounts(accounts);
  
  file.close();
  return file;
}