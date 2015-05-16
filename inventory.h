#ifndef INVENTORY_H
#define INVENTORY_H
//#include <string>
#include <iostream>
#include "transaction.h"
using namespace std;

class Inventory : public Transaction{

public:
	Inventory();
	virtual ~Inventory();

	virtual void display(){};
private:
};

#endif