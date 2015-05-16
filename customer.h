#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <queue>
#include "transaction.h"
#include "history.h"
#include "borrow.h"
#include "return.h"
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// Customer class: Customers are used to keep track of the 
// processed transactions.
// Features:
// -- this class formats its own output
// -- this class allows transactions be added to its history

class Customer{
	friend ostream& operator<<(ostream&, const Customer&);

public:

	Customer(int, string, string);
	~Customer();

	int getID();
	string getFirst();
	string getLast();
	bool checkReturn(Return*&);
	bool addToHistory(Transaction*);
	void getHistory();

private:

	struct Node{
		Transaction* data;
		Node* next;
	};
	struct List{
		Node*front;
	};

	int id;
	string first;
	string last;
	List history;
	

};

#endif