#ifndef HISTORY_H
#define HISTORY_H
//#include <string>
#include <iostream>
#include "transaction.h"
using namespace std;

//---------------------------------------------------------------------------
// History class: History is a type of transaction. History transactions
// output all the transactions of a customer.
// Features:
// -- this class formats its own output
class History : public Transaction{
	friend ostream& operator<<(ostream&, const History&);
public:
	History();
	History(char, int);
	virtual ~History();

	int getID();

private:
	int ID;
};

#endif