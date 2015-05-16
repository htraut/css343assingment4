#ifndef CLASSIC_H
#define CLASSIC_H
#include <iostream>
#include "dvd.h"
using namespace std;

//---------------------------------------------------------------------------
// Classic class: Classic is a type of DVD. Classic DVDs are sorted and 
// retrieved differently than other DVDs.
// Features:
// -- this class formats its own output
// -- this class allows for comparison by Release date, then Major actor.
class Classic : public DVD{
	friend ostream& operator<<(ostream&, const Classic&);
public:
	Classic(string n, string d, string a, char g, int& s, int y, int m): DVD(n, d, g, s, y){
		actor = a;
		month = m;
		matching.front = NULL;
	};
	virtual ~Classic();
	
	string getActor();
	int getMonth();

	virtual bool operator>(const Classic &) const;
	virtual bool operator<(const Classic &) const;
	virtual bool operator==(Classic &);
private:
	
	void combineStock(Classic&);
	string actor;
	int month;
	
	struct SNode{
		SNode* next;
		Classic* same;
	};
	struct Shared{
		SNode *front;
	};
	Shared matching;
};

#endif