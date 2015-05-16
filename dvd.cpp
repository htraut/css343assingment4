#include "dvd.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default no arg constructor for class DVD
DVD::DVD(){
	director = "";
	year = 0;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for class DVD
DVD::~DVD(){
	director = "";
	year = 0;
}

// ---------------------------------------------------------------------------
// getDirector
// returns the director
string DVD::getDirector(){
	return director;
}

// ---------------------------------------------------------------------------
// getYear
// returns the year
int DVD::getYear(){
	return year;
}

// operator>
// Determine if a DVD is greater than another
// (sorted by Title)
bool DVD::operator>(const DVD & other) const{
	if (title > other.title){
		return true;
	}
	else{
		return false;
	}
}

// --------------------------------------------------------------------------
// operator<
// Determine if a DVD is less than another
// (sorted by Title)
bool DVD::operator<(const DVD & other) const{
	if (title < other.title){
		return true;
	}
	else{
		return false;
	}
}

// --------------------------------------------------------------------------
// operator==
// Determine if a DVD equal to another
// (sorted by Title)
bool DVD::operator==(const DVD & other) const{
	if (title == other.title){
		return true;
	}
	else{
		return false;
	}
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded output operator
ostream& operator<<(ostream& output, const DVD& prod){
	output << prod.title << setw(10) << *prod.stock;
	output << setw(5) <<prod.genre << setw(6) << prod.director;
	output << setw(10) << prod.year;
	return output;
}