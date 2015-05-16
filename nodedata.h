#ifndef NODEDATA_H
#define NODEDATA_H
#include <iostream>
#include <fstream>
using namespace std;

// NodeData from assignment 2
// Modified for assignment 4 as template

template<typename t>
class NodeData {

	friend ostream & operator<<(ostream &output, const NodeData<t>&nd){
		output << *nd.data;
		return output;
	};

public:
	NodeData();          // default constructor, data is set to an empty string
	~NodeData();
	NodeData(t *);      // data is set equal to parameter
	NodeData(const NodeData &);    // copy constructor
	NodeData& operator=(const NodeData &);

	// set class data from data file
	// returns true if the data is set, false when bad data, i.e., is eof
	bool setData(t&);
	t* getData() const;

	bool operator==(const NodeData &) const;
	bool operator!=(const NodeData &) const;
	bool operator<(const NodeData &) const;
	bool operator>(const NodeData &) const;
	bool operator<=(const NodeData &) const;
	bool operator>=(const NodeData &) const;

private:
	t* data;
};


//------------------- constructors/destructor  -------------------------------
template<typename t>
NodeData<t>::NodeData() { data = NULL; }                         // default

template<typename t>
NodeData<t>::~NodeData() { delete data; }            // needed so data is deleted properly

template<typename t>
NodeData<t>::NodeData(const NodeData& nd) {
	data = NULL;
	data = nd.data;
}  // copy

template<typename t>
NodeData<t>::NodeData(t* s) {
	data = NULL;
	data = s;
}

//------------------------- operator= ----------------------------------------
template<typename t>
NodeData<t>& NodeData<t>::operator=(const NodeData<t>& rhs) {
	if (this != &rhs) {
		data = rhs.data;
	}
	return *this;
}

//------------------------- operator==,!= ------------------------------------
template<typename t>
bool NodeData<t>::operator==(const NodeData& rhs) const {
	return data == rhs.data;
}
template<typename t>
bool NodeData<t>::operator!=(const NodeData& rhs) const {
	return data != rhs.data;
}

//------------------------ operator<,>,<=,>= ---------------------------------
template<typename t>
bool NodeData<t>::operator<(const NodeData& rhs) const {
	return data < rhs.data;
}

template<typename t>
bool NodeData<t>::operator>(const NodeData& rhs) const {
	return data > rhs.data;
}

template<typename t>
bool NodeData<t>::operator<=(const NodeData& rhs) const {
	return data <= rhs.data;
}

template<typename t>
bool NodeData<t>::operator>=(const NodeData& rhs) const {
	return data >= rhs.data;
}

//------------------------------ setData -------------------------------------
template<typename t>
bool NodeData<t>::setData(t& T) {
	data = new t(T);
	return true;
}

//------------------------------ getData -------------------------------------
template<typename t>
t* NodeData<t>::getData() const{
	return data;
}

//-------------------------- operator<< --------------------------------------
/*template<typename t>
ostream& operator<<(ostream& output, const NodeData<t>& nd) {
	output << *nd->data;
	return output;
}*/


#endif
