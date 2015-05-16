#include "customer.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Customer
Customer::Customer(int ID, string firstName, string lastName){
	id = ID;
	first = firstName;
	last = lastName;
	history.front = NULL;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for class Customer
Customer::~Customer(){

	id = 0;
	first = "";
	last = "";
	Transaction *temp = NULL;
	Node* cur = history.front;
	Node* pre = NULL;
	while (cur != NULL){
		temp = cur->data;
		pre = cur;
		cur = cur->next;
		if (temp->getAction() == 'B'){
			Borrow* b = static_cast<Borrow*>(temp);
			delete b;
		}
		else if (temp->getAction() == 'R'){
			Return* b = static_cast<Return*>(temp);
			delete b;
		}
		else if (temp->getAction() == 'H'){
			History* b = static_cast<History*>(temp);
			delete b;
		}
		else{
			delete temp;
		}
		temp = NULL;
		delete pre;
	}
	history.front = NULL;
	temp = NULL;
}

// ---------------------------------------------------------------------------
// checkReturn
// Checks a return transaction against a Customers history
// one Borrow to one Return transaction
bool Customer::checkReturn(Return* &check){

	Node* cur = history.front;
	Transaction* temp = NULL;
	while (cur != NULL){
		temp = cur->data;
		if (temp->getAction() == 'B'){
			Borrow* b = static_cast<Borrow*>(temp);
			if (check->getTitle() == b->getTitle()){
				if (!b->returnIsSet()){
					b->setReturn(check);
					return true;
				}
			}
		}
		cur = cur->next;
	}
	return false;

}

// ---------------------------------------------------------------------------
// getID
// returns the ID
int Customer::getID(){
	return id;
}

// ---------------------------------------------------------------------------
// getFirst
// returns the first name
string Customer::getFirst(){
	return first;
}

// ---------------------------------------------------------------------------
// getLast
// returns the last name
string Customer::getLast(){
	return last;
}

// ---------------------------------------------------------------------------
// addToHistory
// adds transactions into a customer's transaction queue
bool Customer::addToHistory(Transaction *toAdd){
	if (toAdd == NULL) return false;
	Node* temp = new Node;
	temp->data = toAdd;
	temp->next = history.front;
	history.front = temp;
	return true;
}

// ---------------------------------------------------------------------------
// getHistory
// prints a customer's history
void Customer::getHistory(){
	cout << endl;
	cout << "DISPLAYING HISTORY:" << endl << endl;
	Transaction* temp = NULL;
	Node* cur = history.front;
	while (cur != NULL){
		temp = cur->data;
		if (temp->getAction() == 'B'){
			Borrow* b = static_cast<Borrow*>(temp);
			cout << *b;
		}
		if (temp->getAction() == 'R'){
			Return* b = static_cast<Return*>(temp);
			cout << *b;
		}
		if (temp->getAction() == 'H'){
			History* b = static_cast<History*>(temp);
			cout << *b;
		}
		cur = cur->next;
	}
}
