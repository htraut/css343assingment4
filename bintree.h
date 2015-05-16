// BinTree class by Herbert Traut

#ifndef BINTREE_H
#define BINTREE_H
#include "nodedata.h"
#include <iostream>
using namespace std;

// BinTree from assignment 2
// Modified for assignment 4 as template

//---------------------------------------------------------------------------
// BinTree class: Binary Tree for storing NodeData
//
// Implementation and assumptions:
//   -- root defaults to NULL
//   -- Binary tree built using Node struct
//   -- Uses Node struct with NodeData pointer
//   -- Assumes sorted array for arrayToBSTree
//---------------------------------------------------------------------------

template<typename t>
class BinTree {

public:

	BinTree();								// constructor
	BinTree(const BinTree &);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	

	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true


	BinTree& operator=(const BinTree &);
	bool operator==(const BinTree &) const;
	bool operator!=(const BinTree &) const;

	int getHeight(const NodeData<t> &) const;  // returns the height of a specific NodeData

	bool insert(NodeData<t>*);
	bool retrieve(const NodeData<t> &, NodeData<t>* &) const;

	void bstreeToArray(NodeData<t>*[]);
	void arrayToBSTree(NodeData<t>*[]);
	void displaySideways() const;
	void display() const;


private:

	struct Node {
		NodeData<t>* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

	// utility functions

	void inorderHelper(Node*) const;
	void sideways(Node*, int) const;
	void makeEmptyHelper(Node*);

	Node* arrayToBSTreeHelp(NodeData<t>*[], Node*, int, int);
	void bstreeToArrayHelp(NodeData<t>*[], Node*, int&);

	int heightHelper(const Node*)const;
	Node* findTarget(const NodeData<t>&, Node*) const;

	bool equalHelper(Node*, const Node*) const;

	bool insertHelper(NodeData<t>*, Node*);
	bool retrieveHelper(const NodeData<t> &, NodeData<t>* &, Node*)const;
	Node* copyHelper(const Node*);

};

//-------------------------- Constructor ------------------------------------
template<typename t>
BinTree<t>::BinTree(){
	root = NULL;
}

//--------------------------Copy Constructor --------------------------------
// Calls copyHelper, a recursive function
template<typename t>
BinTree<t>::BinTree(const BinTree& other){

	if (other.root != NULL){
		root = copyHelper(other.root);
	}
}

// copyHelper
// Deep copy of another tree
// Recursively copies data from one tree into another
template<typename t>
typename BinTree<t>::Node* BinTree<t>::copyHelper(const Node* other){

	if (other == NULL) return NULL;
	Node* subRoot = new Node;
	subRoot->data = new NodeData<t>(*other->data);
	subRoot->left = copyHelper(other->left);
	subRoot->right = copyHelper(other->right);
	return subRoot;

}
//--------------------------- Destructor ------------------------------------
// Calls makeEmpty
template<typename t>
BinTree<t>::~BinTree(){
	makeEmpty();
}

// makeEmpty
// Calls makeEmptyHelper, a recursive function
template<typename t>
void BinTree<t>::makeEmpty(){
	makeEmptyHelper(root);
	root = NULL;
}

// makeEmptyhelper
// Recursively deletes NodeData and Nodes from tree
template<typename t>
void BinTree<t>::makeEmptyHelper(Node* subRoot){

	if (subRoot == NULL) return;
	makeEmptyHelper(subRoot->left);
	makeEmptyHelper(subRoot->right);
	delete subRoot->data;
	delete subRoot;
	subRoot = NULL;
}

//--------------------------- isEmpty ---------------------------------------
template<typename t>
bool BinTree<t>::isEmpty() const{
	return root == NULL ? true : false;
}
//--------------------------- getHeight -------------------------------------
// Retrieves the height of a NodeData object from the tree
// Height is determined by longest path from Node to leaf in a sub tree
// Counts upwards from furthest leaf in a sub tree
// Calls recursive functions findTarget and heightHelper
template<typename t>
int BinTree<t>::getHeight(const NodeData<t> &target) const{

	Node* find = NULL;
	find = findTarget(target, root);
	int height = heightHelper(find);
	return height;
}

// findTarget
// Written for randomly ordered tree (assignment2 instructions)
// Recursively searches all of a tree
// Checks current data, checks to left, then right.
template<typename t>
typename BinTree<t>::Node* BinTree<t>::findTarget(const NodeData<t> &target, Node* subRoot) const{

	Node* retVal = NULL;
	if (*subRoot->data == target){
		return subRoot;
	}

	if (subRoot->left != NULL && (retVal = findTarget(target, subRoot->left))){
		return retVal;
	}

	if (subRoot->right != NULL){
		return findTarget(target, subRoot->right);
	}
	return NULL;
}

// heightHelper
// Recursively finds the height from a Node
// Takes longest path of sub tree as height
template<typename t>
int BinTree<t>::heightHelper(const Node* subRoot)const{

	if (subRoot == NULL) return 0;

	int left = heightHelper(subRoot->left);
	int right = heightHelper(subRoot->right);

	return 1 + (left > right ? left : right);
}

//------------------------- bstreeToArray -----------------------------------
// Empties a tree into an array
// Assumes array to be no more than size 100
// Calls bstreeToArrayHelp
template<typename t>
void BinTree<t>::bstreeToArray(NodeData<t>* elements[]){

	int index = 0;
	bstreeToArrayHelp(elements, root, index);
	root = NULL;
}

// bstreeToArrayHelp
// Recursively empties a tree into an array from smallest element to largest
template<typename t>
void BinTree<t>::bstreeToArrayHelp(NodeData<t>* elements[], Node* subRoot, int &index) {

	if (index >= 0 && index <= 100){
		if (subRoot == NULL) return;
		bstreeToArrayHelp(elements, subRoot->left, index);
		elements[index++] = subRoot->data;
		subRoot->data = NULL;
		bstreeToArrayHelp(elements, subRoot->right, index);
		delete subRoot;
		subRoot = NULL;
	}
}

//------------------------- arrayToBSTree -----------------------------------
// Empties an array into an empty tree
// Balances tree according to array
// Assumes sorted array of no more than 100 elements
// Calls arrayToBSTreeHelp
template<typename t>
void BinTree<t>::arrayToBSTree(NodeData<t>* elements[]){

	if (!isEmpty()) return;
	int low = 0;
	int high = 0;
	while (elements[high] != NULL && high <= 100){
		high++;
	}
	root = arrayToBSTreeHelp(elements, root, low, high - 1);
}

// arrayToBSTreeHelp
// Recursively empties an array into a tree
// Sets pointers in array to NULL
template<typename t>
typename BinTree<t>::Node* BinTree<t>::arrayToBSTreeHelp(NodeData<t>* ele[], Node* subRoot, int low, int high){

	if (low > high) return NULL;
	int mid = (low + (high - low) / 2);
	subRoot = new Node;
	subRoot->data = ele[mid];
	ele[mid] = NULL;
	subRoot->left = arrayToBSTreeHelp(ele, subRoot->left, low, mid - 1);
	subRoot->right = arrayToBSTreeHelp(ele, subRoot->right, mid + 1, high);
	return subRoot;
}

//----------------------------- Insert --------------------------------------
// Inserts into root of tree if root is NULL
// Calls insertHelper if root is not NULL
// Does not balance tree
template<typename t>
bool BinTree<t>::insert(NodeData<t>* info){

	if (root == NULL){
		root = new Node;
		root->data = info;
		root->left = NULL;
		root->right = NULL;
		return true;
	}
	return insertHelper(info, root);

}

// insertHelper
// Recursively inserts into a tree
template<typename t>
bool BinTree<t>::insertHelper(NodeData<t>* info, Node* subRoot){

	if (subRoot == NULL){
		return false;
	}
	else if (*info->getData() == *subRoot->data->getData()){
		return false;
	}
	else if (*info->getData() > *subRoot->data->getData()){
		if (subRoot->right != NULL){
			return insertHelper(info, subRoot->right);
		}
		else{
			Node* temp = new Node;
			subRoot->right = temp;
			temp->data = info;
			temp->left = NULL;
			temp->right = NULL;
			return true;
		}
	}
	else if (*info->getData() < *subRoot->data->getData()){
		if (subRoot->left != NULL){
			return insertHelper(info, subRoot->left);
		}
		else{
			Node* temp = new Node;
			subRoot->left = temp;
			temp->data = info;
			temp->left = NULL;
			temp->right = NULL;
			return true;
		}
	}
	return 0;
}

//----------------------------- Retrieve ------------------------------------
// Retrieves a specific NodeData from tree
// Returns true if found, false if not
// Calls retrieveHelper
template<typename t>
bool BinTree<t>::retrieve(const NodeData<t> &target, NodeData<t>* &find) const{

	return retrieveHelper(target, find, root);
}

// retrieveHelper
// Recursively searches the tree for a specific NodeData
// Returns true if found, false if not
template<typename t>
bool BinTree<t>::retrieveHelper(const NodeData<t> &target, NodeData<t>* &find, Node* subRoot) const{

	if (subRoot == NULL) {
		find = NULL;
		return false;
	}
	if (*subRoot->data->getData() == *target.getData()){
		find = subRoot->data;
		return true;
	}
	else if (*subRoot->data->getData() < *target.getData()){
		return retrieveHelper(target, find, subRoot->right);
	}
	else if (*subRoot->data->getData() > *target.getData()){
		return retrieveHelper(target, find, subRoot->left);
	}
	return 0;
}

//---------------------------- operator= ------------------------------------
// Assigns values of one tree to another
// Calls copyHelper
// Deep Copy
template<typename t>
BinTree<t>& BinTree<t>::operator=(const BinTree<t>& rhs){

	if (this != &rhs){
		makeEmpty();
		root = copyHelper(rhs.root);
	}
	return *this;
}

//---------------------------- operator== -----------------------------------
// Returns whether or not two trees are the same
// Calls equalHelper
template<typename t>
bool BinTree<t>::operator==(const BinTree<t>& rhs) const{

	if (this == &rhs) return true;
	return equalHelper(root, rhs.root);

}

// equalHelper
// Recursively checks NodeDatas of two tree to see if they are the same
template<typename t>
bool BinTree<t>::equalHelper(Node* subRoot, const Node* rhs)const{

	if (subRoot != NULL && rhs != NULL){
		if (*subRoot->data != *rhs->data) return false;
		if (*subRoot->data == *rhs->data){
			equalHelper(subRoot->left, rhs->left);
			equalHelper(subRoot->left, rhs->right);
			return true;
		}
	} return false;
}

//---------------------------- operator!= -----------------------------------
// Returns whether or not two trees are different
// Calls equalHelper
// Returns opposite of equalHelper
template<typename t>
bool BinTree<t>::operator!=(const BinTree& rhs) const{

	if (this == &rhs) return false;
	bool same = equalHelper(root, rhs.root);
	return !same;
}

template <typename t>
void BinTree<t>::display() const{
	inorderHelper(root);
}

// inorderHelper
// Recursively traverses the tree and writes to output
template<typename t>
void BinTree<t>::inorderHelper(Node* subRoot) const{

	if (subRoot != NULL){
		inorderHelper(subRoot->left);
		cout << *subRoot->data << endl;
		inorderHelper(subRoot->right);
	}
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
template<typename t>
void BinTree<t>::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
template<typename t>
void BinTree<t>::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}

#endif