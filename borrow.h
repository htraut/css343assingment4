#ifndef BORROW_H
#define BORROW_H
#include <string>
#include <iostream>
#include "transaction.h"
using namespace std;

//---------------------------------------------------------------------------
// Borrow class: Borrow is a type of transaction. Borrow transactions are 
// ones which decrement a product's stock.
// Features:
// -- this class formats its own output
class Borrow : public Transaction{
	friend ostream& operator<<(ostream&, const Borrow&);
public:
	Borrow();
	Borrow(char, char, char, int, string);
	virtual ~Borrow();

	void setData(char, char, int, string);

	char getMediaType();
	char getGenre();
	int getID();
	string getTitle();
	void setReturn(Transaction*);
	bool returnIsSet();


private:

	char media;   // type of product/media
	char genre;   // type of genre
	int ID;		  // customer ID
	string title; // title of product
	Transaction* ret; //shared return of movie
};

#endif