
#include "transaction.h"
// ---------------------------------------------------------------------------
// Constructor 
// Default no arg constructor for class Transaction
Transaction::Transaction(){
	action = '\0';
}

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Transaction
Transaction::Transaction(char a){
	action = a;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for class Transaction
Transaction::~Transaction(){
	action = '\0';
}

// ---------------------------------------------------------------------------
// getAction
// returns the action
char Transaction::getAction(){
	return action;
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded output operator
ostream& operator<<(ostream& output, const Transaction& tran){
	output << tran.action << endl;
	return output;
}