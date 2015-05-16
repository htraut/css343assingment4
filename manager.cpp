#include "manager.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default no arg constructor for class Manager
Manager::Manager(){
	products.front = NULL;
}

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Manager
Manager::~Manager(){
	ProdNode *curProd = NULL;
	ProdNode *preProd = NULL;
	curProd = products.front;
	while (curProd != NULL){
		preProd = curProd;
		curProd = curProd->next;
		delete preProd->classic;
		delete preProd->comedy;
		delete preProd->drama;
		delete preProd;
	}
	curProd = preProd = NULL;
}

// ---------------------------------------------------------------------------
// buildCustomers
// Read a datafile and create customer objects and sort them into a hashtable.
void Manager::buildCustomers(ifstream& infile){

	bool success = false;
	Customer* inClient = NULL;
	int id;
	string first;
	string last;
	while (!infile.eof()){

		infile >> id >> first >> last;
		inClient = new Customer(id, first, last);

		if (success = clients.insert(inClient)){
			inClient = NULL;
		}
		else{
			delete inClient;
			inClient = NULL;
		}
	}
}

// ---------------------------------------------------------------------------
// buildProducts
// Read a file and create Product objects and sort them appropriately by genre
void Manager::buildProducts(ifstream& infile){
	string movieInfo;
	NodeData<Drama> *D;
	NodeData<Comedy> *F;
	NodeData<Classic> *C;
	bool success = false;
	ProdNode *cur = products.front;

	while (!infile.eof()){
		getline(infile, movieInfo);
		Product *temp = movFact.create(movieInfo);
		if (temp != NULL){
			char tempGen = temp->getGenre();
			
			//create drama object
			if (tempGen == 'D') {
				Drama * d = static_cast<Drama*>(temp);
				D = new NodeData<Drama>(d);
				if (cur == NULL){
					addProduct('D');
					cur = products.front;
				}
				success = cur->drama->insert(D);
				if (!success) delete D;
			}
			//create comedy object
			if (tempGen == 'F'){
				Comedy * f = static_cast<Comedy*>(temp);
				F = new NodeData<Comedy>(f);
				if (cur == NULL){
					addProduct('D');
					cur = products.front;
				}
				success = cur->comedy->insert(F);
				if (!success) delete F;
			}
			//create classic object
			if (tempGen == 'C') {
				Classic * c = static_cast<Classic*>(temp);
				C = new NodeData<Classic>(c);
				if (cur == NULL) {
					addProduct('D');
					cur = products.front;
				}
				success = cur->classic->insert(C);
				if (!success) delete C;
			}
		}
	}
}

// ---------------------------------------------------------------------------
// addProduct
// With given perameters, create and add a new product
bool Manager::addProduct(char iden){
	if (iden >= 'A' && iden <= 'Z'){
		ProdNode* temp = NULL;
		if (products.front != NULL)  temp = products.front;
		if (products.front == NULL) temp = NULL;
		products.front = new ProdNode;
		products.front->identifier = iden;
		products.front->comedy = new BinTree<Comedy>;
		products.front->drama = new BinTree<Drama>;
		products.front->classic = new BinTree<Classic>;
		products.front->next = temp;
		return true;
	}
	return false;
}

// ---------------------------------------------------------------------------
// runDailyTransaction
// command to run the daily queue of transactions
void Manager::runDailyTransaction(ifstream& infile){

	while (!infile.eof()){
		//initialize pointers
		ProdNode *cur = NULL;
		Product* target = NULL;
		History* tempHist = NULL;
		Borrow* tempBor = NULL;
		Return* tempRet = NULL;
		Customer* tempCust = NULL;

		//initialize variables
		char type;
		int id;
		char media;
		char genre;
		string info;
		string temp;

		string data;
		getline(infile, data);
		istringstream iss(data);

		iss >> type;

		switch (type){
			//run an Inventory transaction
		case 'I':
			cout << endl << "Displaying Inventory:" << endl << endl;
			cur = products.front;
			while (cur != NULL){
				cur->classic->display();
				cur->drama->display();
				cur->comedy->display();
				cur = cur->next;
			}
			break;
			//run a History transaction
		case 'H':
			iss >> id;
			// no customer match
			if (!(tempCust = clients.retrieve(id))) {
				cout << "ERROR: Invalid ID " << id << endl;
			}
			else{
				tempHist = new History('H', id);
				tempCust->addToHistory(tempHist);
				tempCust->getHistory();
				tempHist = NULL;
			}
			break;
			//run a Borrow transaction
		case 'B':
			iss >> id;
			//no customer match
			if (!(tempCust = clients.retrieve(id))) {
				cout << "ERROR: Invalid ID " << id << endl;
			}
			else{
				iss >> media;
				cur = products.front;
				while (cur != NULL && cur->identifier != media){
					cur = cur->next;
				}
				//no media match
				if (cur == NULL || cur->identifier != media){
					cout << "ERROR: Invalid Media Type " << media << endl;
				}
				else{
					iss >> genre;
					getline(iss, info);
					tempBor = new Borrow('B', media, genre, id, info);
					target = retrieve(tempBor->getMediaType(), tempBor->getGenre(), tempBor->getTitle());
					//title not found
					if (target == NULL){
						cout << "ERROR: Media not Found" << endl;
						delete tempBor;
					}
					else{
						if (target->decrementStock()){
							tempCust->addToHistory(tempBor);
							tempBor = NULL;
						}
						else{
							delete tempBor;
							tempBor = NULL;
						}

					}
				}
			}
			break;
			//run a return transaction
		case 'R':
			iss >> id;
			// no customer match
			if (!(tempCust = clients.retrieve(id))) {
				cout << "ERROR: Invalid ID " << id << endl;
			}
			else{
				iss >> media;
				cur = products.front;
				while (cur != NULL && cur->identifier != media){
					cur = cur->next;
				}
				//no media match
				if (cur == NULL || cur->identifier != media){
					cout << "ERROR: Invalid Media Type " << media << endl;
				}
				else{
					iss >> genre;
					getline(iss, info);
					tempRet = new Return('R', media, genre, id, info);
					// Checks a return against Customer history
					if (!tempCust->checkReturn(tempRet)) {
						cout << "ERROR: Movie was not Borrowed" << endl;
						delete tempRet;
					}
					else{
						target = retrieve(tempRet->getMediaType(), tempRet->getGenre(), tempRet->getTitle());
						//title not found
						if (target == NULL){
							cout << "ERROR: Media not Found" << endl;
							delete tempRet;
						}
						else{
							target->incrementStock();
							tempCust->addToHistory(tempRet);
							//delete tempRet;
							tempRet = NULL;
						}
					}
				}
			}
			break;
		default:
			cout << "ERROR: Invalid Command: " << type << endl;
			break;
		}
		iss.clear();
	}
}

// ---------------------------------------------------------------------------
// retreieve
// function to retrieve
Product* Manager::retrieve(char prod, char gen, string title){
	istringstream iss(title);
	Product* retVal = NULL;
	ProdNode* Pcur = NULL;
	int s = 0;
	Pcur = products.front;
	while (prod != Pcur->identifier && Pcur->next != NULL){
		Pcur = Pcur->next;
	}
	//product not found
	if (Pcur == NULL) return NULL;  

	//retrieve a comedy
	if (gen == 'F'){
		string t;
		iss.get();
		getline(iss, t, ',');
		int y;
		iss >> y;
		Comedy *f = new Comedy(t, "", 'F', s, y);
		NodeData<Comedy> n(f);
		NodeData<Comedy> *find = NULL;
		Pcur->comedy->retrieve(n, find);
		if (find == NULL) return NULL;
		return retVal = find->getData();
	}
	//retrieve a drama
	if (gen == 'D'){
		string d;
		getline(iss, d, ',');
		iss.get();
		string t;
		getline(iss, t, ',');
		Drama *dr = new Drama(t, d, 'D', s, 0);
		NodeData<Drama> n(dr);
		NodeData<Drama> *find = NULL;
		Pcur->drama->retrieve(n, find);
		if (find == NULL) return NULL;
		return retVal = find->getData();
	}
	//retrieve a classic
	if (gen == 'C'){
		string a;
		int y, m;
		iss >> m;
		iss >> y;
		string f;
		string l;
		iss >> f;
		iss >> l;
		a = f + " " + l;
		Classic *cl = new Classic("", "", a, 'C', s, y, m);
		NodeData<Classic> n(cl);
		NodeData<Classic> *find = NULL;
		Pcur->classic->retrieve(n, find);
		if (find == NULL) return NULL;
		return retVal = find->getData();
	}
	return NULL;
}