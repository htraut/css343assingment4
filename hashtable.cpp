#include "hashtable.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class HashTable
HashTable::HashTable(){
	for (int i = 0; i < SIZE; i++){
		hashtable[i].front = NULL;
	}
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for class HashTable
HashTable::~HashTable(){
	HashNode* current = NULL;
	HashNode* previous = NULL;

	for (int i = 0; i < SIZE; i++){
		current = hashtable[i].front;
		while (current != NULL){
			previous = current;
			current = current->next;
			delete previous->data;
			delete previous;
		}
		hashtable[i].front = NULL;
	}
}

// ---------------------------------------------------------------------------
// Insert
// Inserts customer objects into the hashtable
bool HashTable::insert(Customer *&info){
	bool success = false;
	int key = hashFunction(info->getID());
	if (key >= 0 && key <= 99){
		HashNode *temp = NULL;
		if (hashtable[key].front != NULL){
			temp = hashtable[key].front;
		}
		hashtable[key].front = new HashNode;
		hashtable[key].front->data = info;
		hashtable[key].front->next = temp;
		temp = NULL;
		return success = true;
	}
	else{
		return success;
	}
}

// ---------------------------------------------------------------------------
// Retrieve
// Retrieve customer objects from the hashtable
Customer* HashTable::retrieve(int id){
	int targetID = hashFunction(id);

	if (hashtable[targetID].front != NULL){
		HashNode* retVal = hashtable[targetID].front;
		while (retVal != NULL && retVal->data->getID() != id){
			retVal = retVal->next;
		}
		return retVal->data;
	}
	return NULL;
}

// ---------------------------------------------------------------------------
// HashFunction
// takes the digit fromt he ones place and the hundreds place in an ID and 
// concatonates the digits into a 2 digit number
int HashTable::hashFunction(int ID){
	int d1 = ID % 10;
	int d2 = ID % 1000;  
	d2 /= 100;

	return (d2 * 10) + d1;
}