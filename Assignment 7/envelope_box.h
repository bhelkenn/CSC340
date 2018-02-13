#ifndef __ENVELOPE_BOX_H__
#define __ENVELOPE_BOX_H__
#include "Tree.h"
#include "budget_envelope.h"
#include "Envelope.h"

class EnvelopeBox {
private:
	int month;
	int year;
	Tree<BudgetEnvelope> envelopes;
public:
	EnvelopeBox();
	EnvelopeBox(const Envelope*, int, int, int);
	EnvelopeBox(const EnvelopeBox*, int, int);
	Tree<BudgetEnvelope> getEnvelopes() const;
	void deposit(int, double);
	bool withdraw(int, double);
	
};

#endif