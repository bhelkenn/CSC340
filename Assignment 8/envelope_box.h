#ifndef __ENVELOPE_BOX_H__
#define __ENVELOPE_BOX_H__
#include "tree.h"
#include "budget_envelope.h"
#include "envelope.h"

class EnvelopeBox {
private:
	int month;
	int year;
	Tree<BudgetEnvelope> envelopes;
public:
	EnvelopeBox();
	EnvelopeBox(const Envelope*, int, int, int);
	EnvelopeBox(const EnvelopeBox*, int, int);
	int size() const;
	void traverse() const;
	BudgetEnvelope* find(BudgetEnvelope&);
	void deposit(int, double);
	bool withdraw(int, double);
	
};

#endif