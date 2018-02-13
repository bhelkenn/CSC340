#include "Envelope.h"

Envelope::Envelope() {
	id = 0;
	title = "";
}

int Envelope::getId() const {
	return id;
}

string Envelope::getTitle() const {
	return title;
}

void Envelope::setId(int id) {
	this->id = id;
}

void Envelope::setTitle(string title) {
	this->title = title;
}