#include "return.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default no arg constructor for class Return
Return::Return(){
	action = 'R';
	media = '\0';
	genre = '\0';
	ID = 0;
	title = "";
}

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Return
Return::Return(char a, char m, char g, int i, string t):Transaction(a){
	action = 'R';
	media = m;
	genre = g;
	ID = i;
	title = t;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for class Return
Return::~Return(){
	media = '\0';
	genre = '\0';
	ID = 0;
	title = "";
}

// ---------------------------------------------------------------------------
// setData
// allows the data of a return transaction to be set
void Return::setData(char m, char g, int i, string t){
	media = m;
	genre = g;
	ID = i;
	title = t;
}

// ---------------------------------------------------------------------------
// getMediaType
// returns the media type
char Return::getMediaType(){
	return media;
}

// ---------------------------------------------------------------------------
// getGenre
// returns the genre
char Return::getGenre(){
	return genre;
}

// ---------------------------------------------------------------------------
// getID
// returns the ID
int Return::getID(){
	return ID;
}

// ---------------------------------------------------------------------------
// getTitle
// returns the title
string Return::getTitle(){
	return title;
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded output operator
ostream& operator<<(ostream& output, const Return& ret){
	output << ret.action << " " << ret.ID << " " << ret.media;
	output << " " << ret.genre << " " << ret.title << endl;
	return output;
}