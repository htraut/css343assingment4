#include "drama.h"

// --------------------------------------------------------------------------
// operator>
// Determine if a drama is greater than another
// (sorted by Director, then Title)
bool Drama::operator>(const Drama & other) const{
	// compare directors
	if (director.compare(other.director) > 0){
		return true;
	}
	// compare titles
	if (director.compare(other.director) == 0 && title.compare(other.title) < 0){
		return true;
	}
	return false;
}

// --------------------------------------------------------------------------
// operator<
// Determine if a drama is less than another
// (sorted by Director, then Title)
bool Drama::operator<(const Drama & other) const{
	// compare directors
	if (director.compare(other.director) < 0){
		return true;
	}
	// compare titles
	if (director.compare(other.director) == 0 && title.compare(other.title) < 0){
		return true;
	}
	return false;
}

// --------------------------------------------------------------------------
// operator==
// Determine if a drama equal to another
// (sorted by Director, then Title)
bool Drama::operator==(const Drama & other) const{
	if (director.compare(other.director) == 0 && title.compare(other.title) == 0){
		return true;
	}
	else{
		return false;
	}
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded output operator
ostream& operator<<(ostream& output, const Drama& prod){
	output << left << setw(35) << prod.title << setw(4) << *prod.stock;
	output << setw(2) << prod.genre << setw(20) << prod.director;
	output << setw(5) << prod.year;
	return output;
}