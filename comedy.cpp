#include "comedy.h"

// --------------------------------------------------------------------------
// operator>
// Determine if a comedy is greater than another
// (sorted by Title, then Year it released)
bool Comedy::operator>(const Comedy & other) const{
	// compare titles
	if (title.compare(other.title) < 0){
		return true;
	}
	// compare years
	if (title.compare(other.title) == 0 && year > other.year){
		return true;
	}
	return false;
}

// --------------------------------------------------------------------------
// operator<
// Determine if a comedy is less than another
// (sorted by Title, then Year it released)
bool Comedy::operator<(const Comedy & other) const{
	// compare titles
	if (title.compare(other.title) > 0){
		return true;
	}
	// compare years
	if (title.compare(other.title) == 0 && year < other.year){
		return true;
	}
	return false;
}

// --------------------------------------------------------------------------
// operator==
// Determine if a comedy is equal another
// (sorted by Title, then Year it released)
bool Comedy::operator==(const Comedy & other) const{
	if (title.compare(other.title) == 0 && year == other.year){
		return true;
	}
	else{
		return false;
	}
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded output operator
ostream& operator<<(ostream& output, const Comedy& prod){
	output << left << setw(35) << prod.title << setw(4) << *prod.stock;
	output << setw(2) << prod.genre << setw(20) << prod.director;
	output << setw(5) << prod.year;
	return output;
}