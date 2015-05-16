#include "classic.h"

// ---------------------------------------------------------------------------
// Destructor
// Destructor for class Classic
Classic::~Classic(){
	actor = "";
	month = 0;
	SNode* c = matching.front;
	SNode* p = NULL;
	
	//loop to deal with classics sharing a stock
	while (c != NULL){
		p = c;
		c = c->next;
		delete p;
	}
	if (matching.front != NULL)stock = NULL;
}

// ---------------------------------------------------------------------------
// combineStock
// function to combine the stocks of classics with the same titles but 
// different actors
void Classic::combineStock(Classic& other){
	if (*&stock == *&other.stock) return;
	*stock = *stock + *other.stock;
	delete other.stock;
	other.stock = stock;
}

// --------------------------------------------------------------------------
// operator>
// Determine if a classic is greater than another
// (sorted by Release date, then Major actor)
bool Classic::operator>(const Classic & other) const{
	if (year > other.year){
		return true;
	}
	if (year == other.year && month > other.month){
		return true;
	}
	if (year == other.year && month == other.month){
		if (actor.compare(other.actor) > 0) return true;
	}
	return false;
}

// --------------------------------------------------------------------------
// operator<
// Determine if a classic is less than another
// (sorted by Release date, then Major actor)
bool Classic::operator<(const Classic & other) const{
	// compare release years
	if (year < other.year){
		return true;
	}
	// compare release dates
	if (year == other.year && month < other.month){
		return true;
	}
	// compare major actors
	if (year == other.year && month == other.month){
		if (actor.compare(other.actor) < 0) return true;
	}
	return false;
}

// --------------------------------------------------------------------------
// operator==
// Determine if a classic equal to another
// (sorted by Release date, then Major actor)
bool Classic::operator==(Classic & other){
	// compare release dates
	if (year == other.year && month == other.month){
		// compare title & director(combine stock check)
		if (title == other.title && director == other.director){
			combineStock(other);
			SNode* st = new SNode;
			st->next = matching.front;
			st->same = this;
			other.matching.front = st;
		}
	}
	// compare major actors
	if (year == other.year && month == other.month && actor.compare(other.actor) == 0){
		return true;
	}
	else{
		return false;
	}
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded output operator
ostream& operator<<(ostream& output, const Classic& prod){
	output << left << setw(35) << prod.title << setw(4) << *prod.stock;
	output << setw(2) << prod.genre << setw(17) << prod.director;
	output << prod.actor << endl;
	output << " " << setw(3) << prod.month << setw(5) << prod.year;
	return output;
}