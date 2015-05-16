#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// Transaction class: A Transaction is considered to be any item that:
// --has an action to be carried out
// Features:
// -- this class formats its own output

class Transaction{
	friend ostream& operator<<(ostream&, const Transaction&);
public:
	Transaction();
	Transaction(char);
	~Transaction();

	char getAction();

protected:
	char action;    // type of transaction
};

#endif