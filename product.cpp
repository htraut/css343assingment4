#include "product.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default no arg constructor for class Product
Product::Product(){
	title = "";
	stock = NULL;
}

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Product
Product::Product(string n, int& s, char g){
	title = n;
	if (s >= 0){
		stock = new int(s);
	}
	else{
		cout << "ERROR: Negative Stock. ";
		cout << "Defaulting to 0 Stock" << endl;
		stock = new int(0);
	}
	genre = g;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for class Product
Product::~Product(){
	title = "";
	if(stock != NULL) delete stock;
}

// ---------------------------------------------------------------------------
// getTitle
// returns the title
string Product::getTitle(){
	return title;
}

// ---------------------------------------------------------------------------
// getStock
// returns the stock
int Product::getStock(){
	return *stock;
}

// ---------------------------------------------------------------------------
// getGenre
// returns the genre
char Product::getGenre(){
	return genre;
}

// ---------------------------------------------------------------------------
// incrementStock
// adds one to the stock
void Product::incrementStock(){
	*stock += 1;
}

// ---------------------------------------------------------------------------
// decrementStock
// subtracts one from the stock
// (stock can not be negative)
bool Product::decrementStock(){
	if (*stock > 0){
		*stock -= 1;
		return true;
	}
	else{
		cout << "ERROR: " << title << " is out of stock";
		cout << endl;
		return false;
	}
}

// --------------------------------------------------------------------------
// operator>
// Determine if a Product is greater than another
// (sorted by Title)
bool Product::operator>(const Product & other) const{
	if (title > other.title){
		return true;
	}
	else{
		return false;
	}
}

// --------------------------------------------------------------------------
// operator<
// Determine if a Product is less than another
// (sorted by Title)
bool Product::operator<(const Product & other) const{
	if (title < other.title){
		return true;
	}
	else{
		return false;
	}
}

// --------------------------------------------------------------------------
// operator==
// Determine if a Product equal to another
// (sorted by Title)
bool Product::operator==(const Product & other) const{
	if (title == other.title){
		return true;
	}
	else{
		return false;
	}
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded output operator
ostream& operator<<(ostream& output, const Product& prod){
	output << prod.title << setw(20) << *prod.stock;
	output << setw(5) << prod.genre;
	return output;
}
