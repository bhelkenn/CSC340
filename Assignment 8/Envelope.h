#ifndef __ENVELOPE_H__
#define __ENVELOPE_H__
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Envelope {
private:
  int id;
  string title;
public:
  Envelope();
	int getId() const;
	string getTitle() const;
	void setId(int);
	void setTitle(string);
	
	friend ostream& operator << (ostream&, const Envelope&);
	friend ofstream& operator << (ofstream&, const Envelope&);
	friend ifstream& operator >> (ifstream&, Envelope&);
};

#endif