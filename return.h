#ifndef RETURN_H
#define RETURN_H
#include <string>
#include <iostream>
#include "transaction.h"
using namespace std;

//---------------------------------------------------------------------------
// Return class: Return is a type of transaction. Return transactions are 
// ones which increment a product's stock.
// Features:
// -- this class formats its own output
class Return : public Transaction{
	friend ostream& operator<<(ostream&, const Return&);
public:
	Return();
	Return(char, char, char, int, string);
	virtual ~Return();

	virtual void setData(char, char, int, string);

	char getMediaType();
	char getGenre();
	int getID();
	string getTitle();

private:

	char media;   // type of product/media
	char genre;      //type of genre
	int ID;
	string title;
};

#endif