#include "borrow.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default no arg constructor for class Borrow
Borrow::Borrow(){
	action = 'B';
	media = '\0';
	genre = '\0';
	ID = 0;
	title = "";
	ret = NULL;
}

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Borrow
Borrow::Borrow(char a,char m, char g, int i, string t):Transaction(a){
	action = 'B';
	media = m;
	genre = g;
	ID = i;
	title = t;
	ret = NULL;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for class Borrow
Borrow::~Borrow(){
	media = '\0';
	genre = '\0';
	ID = 0;
	title = "";
	ret = NULL;
}

// ---------------------------------------------------------------------------
// setData
// allows the data of a borrow transaction to be set
void Borrow::setData(char m, char g, int i, string t){
	media = m;
	genre = g;
	ID = i;
	title = t;
}

// ---------------------------------------------------------------------------
// getMediaType
// returns the media type
char Borrow::getMediaType(){
	return media;
}

// ---------------------------------------------------------------------------
// getGenre
// returns the genre
char Borrow::getGenre(){
	return genre;
}

// ---------------------------------------------------------------------------
// getID
// returns the ID
int Borrow::getID(){
	return ID;
}

// ---------------------------------------------------------------------------
// getTitle
// returns the title
string Borrow::getTitle(){
	return title;
}

// ---------------------------------------------------------------------------
// setReturn
// pairs with a return
// assumes correct pairing
void Borrow::setReturn(Transaction* match){
	ret = match;
}

// ---------------------------------------------------------------------------
// returnIsSet
// true is set
// false is not set
bool Borrow::returnIsSet(){
	return ret != NULL;
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded output operator
ostream& operator<<(ostream& output, const Borrow& bor){
	output << bor.action << " " << bor.ID << " " << bor.media;
	output << " " << bor.genre << " " << bor.title << endl;
	return output;
}