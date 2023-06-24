#include "Term.h"
using namespace std;
int main() {
	TermLL S;
	S.loadFile("BurakEymenCevik.txt");
	cout << "----------------------------" << endl;
	S.saveToFileByAge("byage.txt");
	S.printByAge();
	cout << "----------------------------" << endl;
	cout << "!!Removing a node!!" << endl;
	S.remove("Burak");
	cout << "----------------------------" << endl;
	cout << "!! Sorting by age after removing a node!!" << endl;
	S.printByAge();
	cout << "----------------------------" << endl;
	cout << "!!Adding a node!!" << endl;
	S.add("Burak",21);
	cout << "----------------------------" << endl;
	S.saveToFileByName("byname.txt");
	S.printByName();
	cout << "----------------------------" << endl;
	cout << "!!Updating a node!!" << endl;
	S.update("Burak", 30);
	cout << "----------------------------" << endl;
	S.saveToFileByName("byname.txt");
	S.printByName();

}