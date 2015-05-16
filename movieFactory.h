#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include "product.h"
#include "dvd.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include <sstream>
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// MovieFactory class: This class handles the creation and processing the
// creation of products.
// Features:
// -- this class formats its own output
// -- this class creates Product objects
class MovieFactory {
	friend ostream& operator<< (ostream&, const MovieFactory&);

public:
	MovieFactory();
	~MovieFactory();

	Product* create(string);

private:
};

#endif