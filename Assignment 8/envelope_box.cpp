#include "envelope_box.h"

BudgetEnvelope find(Tree<BudgetEnvelope>&, int);

EnvelopeBox::EnvelopeBox() {}
EnvelopeBox::EnvelopeBox(const Envelope* envelope, int envelope_count, int month, int year) {
	for (int loop_count = 0; loop_count < envelope_count; loop_count++) {
		BudgetEnvelope be(envelope[loop_count].getId(), envelope[loop_count].getTitle(), 0.00);
		envelopes.insert(be);
	}
	this->month = month;
	this->year = year;
}
EnvelopeBox::EnvelopeBox(const EnvelopeBox* eb, int month, int year) {
	envelopes = eb->envelopes;
	this->month = month;
	this->year = year;
}

int EnvelopeBox::size() const {
	return envelopes.size();
}
void EnvelopeBox::traverse() const {
	envelopes.preorder_traversal();
}
BudgetEnvelope* EnvelopeBox::find(BudgetEnvelope &be) {
	return envelopes.find(be);
}

void EnvelopeBox::deposit(int id, double amount) {
	BudgetEnvelope tmp_be(id, "tmp", 0); //placeholder for find method
	envelopes.find(tmp_be)->deposit(amount);
}
bool EnvelopeBox::withdraw(int id, double amount) {
	BudgetEnvelope tmp_be(id, "tmp", 0); //placeholder for find method
	BudgetEnvelope* tmp_bep = envelopes.find(tmp_be);
	BudgetItem* tmp_bi = tmp_bep;
	cout << "tmp_bep == " << *tmp_bep;
	tmp_bi->withdraw(amount);
	return true;
}