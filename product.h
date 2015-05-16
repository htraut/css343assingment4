#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//---------------------------------------------------------------------------
// Product class: A Product is considered to be any item that:
// -- has a specific title
// -- can be categorized
// -- has a stock for inventory
// Features:
// -- this class formats its own output
// -- this class can increments and decrements a product's stock
// -- this class allows for comparison by Title.
class Product{
	friend ostream& operator<<(ostream&, const Product&);
public:
	Product();
	Product(string, int&, char);
	~Product();

	string getTitle();
	int getStock();
	char getGenre();
	void incrementStock();
	bool decrementStock();

	bool operator>(const Product &) const;
	bool operator<(const Product &) const;
	bool operator==(const Product &) const;

protected:
	string title;
	int* stock;
	char genre;
};

#endif