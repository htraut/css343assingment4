#ifndef MANAGER_H
#define MANAGER_H
#include "transaction.h"
#include "bintree.h"
#include "hashtable.h"
#include "movieFactory.h"
using namespace std;

const int MAXPRODUCTS = 10;

//---------------------------------------------------------------------------
// Manager class: The Manager is the class that handles the queue of daily 
// transactions(from start of the day, to end of the day). Also handles 
// building the collection of clients.
// Features:
// -- this class formats its own output
// -- this class builds a data structure of customers from a text file.
// -- this class builds a data structure of products from a text file.
// -- this class runs daily transactions out of a text file.
// -- this class allows for products to be added individually.
class Manager {
	friend ostream& operator<< (ostream&, const Manager&);

public:
	Manager();
	~Manager();

	void buildCustomers(ifstream&);
	void buildProducts(ifstream&);
	void runDailyTransaction(ifstream&);

	bool addProduct(char);

private:

	struct ProdNode{
		ProdNode *next;
		char identifier;
		BinTree<Drama> *drama;
		BinTree<Comedy> *comedy;
		BinTree<Classic> *classic;
	};
	struct ProdList{
		ProdNode *front;
	};
	

	ProdList products;
	HashTable clients;
	MovieFactory movFact;

	Product* retrieve(char, char, string);
};

#endif