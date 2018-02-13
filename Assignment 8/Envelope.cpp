#include "envelope.h"

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

ostream& operator << (ostream& stream, const Envelope &envelope) {
	stream << envelope.id << ": " << envelope.title << endl;
	return stream;
}
ofstream& operator << (ofstream& file, const Envelope &envelope) {
	file << envelope.id << " " << envelope.title << endl;
	return file;
}
ifstream& operator >> (ifstream& file, Envelope &envelope) {
	string tmp;
	getline(file, tmp, ' ');
	envelope.id = atoi(tmp.c_str());
	getline(file, tmp);
	envelope.title = tmp;
	
	return file;
}