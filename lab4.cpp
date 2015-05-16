
#include "manager.h"

int main(){
	
	Manager m;

	ifstream infile1("data4commands.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	ifstream infile2("data4customers.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	ifstream infile3("data4movies.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}


	m.buildCustomers(infile2);
	m.buildProducts(infile3);

	m.runDailyTransaction(infile1);
	
	return 0;
}