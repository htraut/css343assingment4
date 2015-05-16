#ifndef COMEDY_H
#define COMEDY_H
#include <iostream>
#include "dvd.h"
using namespace std;

//---------------------------------------------------------------------------
// Comedy class: Comedy is a type of DVD. Comedy DVDs are sorted and 
// retrieved differently than other DVDs.
// Features:
// -- this class formats its own output
// -- this class allows for comparison by Title, then Year it released
class Comedy : public DVD{
	friend ostream& operator<<(ostream&, const Comedy&);
public:
	Comedy();
	Comedy(string n, string d, char g, int& s, int y):DVD(n, d, g, s, y){};

	virtual bool operator>(const Comedy &) const;
	virtual bool operator<(const Comedy &) const;
	virtual bool operator==(const Comedy &) const;
private:
};

#endif