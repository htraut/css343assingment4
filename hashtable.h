#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h"
using namespace std;

const int SIZE = 100;

//---------------------------------------------------------------------------
// Hashtable class: This hashtable. 
// Features:
// -- this class allows users to insert customers into it
// -- this class allows users to retrieve customers from it
class HashTable{

public:
	HashTable();
	~HashTable();

	bool insert(Customer*&);
	Customer* retrieve(int);

private:

	struct HashNode{
		HashNode* next;
		Customer* data;
	};

	struct Table{
		HashNode* front;
	};


	Table hashtable[SIZE];		//points to a hashtable implemented with an array
	int hashFunction(int);

};

#endif