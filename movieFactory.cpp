#include "movieFactory.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default no arg constructor for class MovieFactory
MovieFactory::MovieFactory(){
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for class MovieFactory
MovieFactory::~MovieFactory(){
}

// ---------------------------------------------------------------------------
// Create
// Reads through a given data file and creates different movie genre objects
// and sorts them appropriately
Product* MovieFactory::create(string data){
	//intialize variables
	Product* p = NULL;
	istringstream iss(data);
	string throwaway;
	char genre;
	int stock;
	string director;
	string title;
	int date;
	int month;
	int year;
	string first;
	string last;
	string actor;

	//read in the genre
	iss >> genre;

	switch (genre)
	{
	//Comedy Case
	case 'F':
		//read in variables
		iss >> throwaway;
		iss >> stock;
		iss >> throwaway;
		getline(iss, director, ',');
		iss.get();
		getline(iss, title, ',');
		iss >> date;

		//create comedy object
		p = new Comedy(title, director, genre, stock, date);
		break;
	//Drama Case
	case 'D':
		//read in variables
		iss >> throwaway;
		iss >> stock;
		iss >> throwaway;
		getline(iss, director, ',');
		iss.get();
		getline(iss, title, ',');
		iss >> date;

		//create drama object
		p = new Drama(title, director, genre, stock, date);
		break;
	//Classic Case
	case 'C':
		//read in variables
		iss >> throwaway;
		iss >> stock;
		iss >> throwaway;
		getline(iss, director, ',');
		iss.get();
		getline(iss, title, ',');

		iss >> first;
		iss >> last;
		actor = first + " " + last;

		iss >> month;
		iss >> year;

		//create classic object
		p = new Classic(title, director, actor, genre, stock, year, month);
		break;
	default:
		cout << "ERROR: Unrecognized Genre " << genre << endl;
		break;
	}

	return p;
}