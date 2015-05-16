#include "history.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default no arg constructor for class History
History::History(){
	action = 'H';
	ID = 0;
}

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class History
History::History(char a, int idnum):Transaction(a){
	action = 'H';
	ID = idnum;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for class History
History::~History(){
	ID = 0;
}

// ---------------------------------------------------------------------------
// getID
// returns the ID
int History::getID(){
	return ID;
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded output operator
ostream& operator<<(ostream& output, const History& hist){
	output << hist.action << " " << hist.ID << endl;
	return output;
}