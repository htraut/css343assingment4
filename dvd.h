#ifndef DVD_H
#define DVD_H
#include <iostream>
#include "product.h"
using namespace std;

//---------------------------------------------------------------------------
// DVD class: DVD is a type of Product. 
// Features:
// -- this class formats its own output
// -- this class allows for comparison by Director, then Title
class DVD : public Product{
	friend ostream& operator<<(ostream&, const DVD&);
public:
	DVD();
	DVD(string n, string d, char g, int& s, int y) :Product(n, s, g){
		director = d;
		year = y;
	};
	virtual ~DVD();

	string getDirector();
	int getYear();

	virtual bool operator>(const DVD &) const;
	virtual bool operator<(const DVD &) const;
	virtual bool operator==(const DVD &) const;
protected:
	string director;
	int year;
};

#endif