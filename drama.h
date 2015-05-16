#ifndef DRAMA_H
#define DRAMA_H
#include <iostream>
#include "dvd.h"
using namespace std;

//---------------------------------------------------------------------------
// Drama class: Drama is a type of DVD. Drama DVDs are sorted and 
// retrieved differently than other DVDs.
// Features:
// -- this class formats its own output
// -- this class allows for comparison by Director, then Title
class Drama : public DVD{
	friend ostream& operator<<(ostream&, const Drama&);
public:
	Drama();
	Drama(string n, string d, char g, int& s, int y):DVD(n, d, g, s, y){};
	//virtual ~Drama();

	virtual bool operator>(const Drama &) const;
	virtual bool operator<(const Drama &) const;
	virtual bool operator==(const Drama &) const;
private:
};

#endif