#ifndef __ENVELOPE_H__
#define __ENVELOPE_H__
#include <cstdlib>
#include <string>
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
};

#endif