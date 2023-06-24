#include "Term.h"
#include <iostream>
#include <fstream>
using namespace std;

void TermLL::add(string name, int age) {
	TLLNode* newnode = new TLLNode(name, age, nullptr, nullptr);
	TLLNode* prev1;
	TLLNode* curr1;
	TLLNode* prev2;
	TLLNode* curr2;
	
	if (tailn == 0 && taila == 0) {
		headn = heada = tailn = taila = newnode;
		return;
	}
	curr1 = heada;

	if (age < heada->ageTLL) {
		newnode->nextage = heada;
		heada = newnode;
	}
	else {
		prev1 = curr1;
		while (curr1 && curr1->ageTLL <= age) {
			prev1 = curr1;
			curr1 = curr1->nextage;
		}
		newnode->nextage = curr1;
		prev1->nextage = newnode;
	}
	curr2 = headn;

	if (name < headn->nameTLL) {
		newnode->nextname = headn;
		headn = newnode;
	}
	else {
		prev2 = curr2;
		while (curr2 && curr2->nameTLL <= name) {
			prev2 = curr2;
			curr2 = curr2->nextname;
		}
		newnode->nextname = curr2;
		prev2->nextname = newnode;
	}

}


bool TermLL::remove(string name){
	TLLNode*curr1 = heada;
	TLLNode* prev1 = curr1;
	TLLNode* curr2 = headn;
	TLLNode* prev2 = curr2;	
	for (curr2=headn; curr2 != NULL; curr2 = curr2->nextname) {
		
		if (name == curr2->nameTLL) {
			if (curr2 == headn) {
				for (; curr1 != NULL; curr1 = curr1->nextage) {
					if (curr2->nameTLL == heada->nameTLL) {
						heada = curr1->nextage;
						curr1->nextage = NULL;
					}
					else if (curr2->nameTLL == curr1->nameTLL) {
						prev1->nextage = curr1->nextage;
						curr1->nextage = NULL;

					}
				}
				headn = curr2->nextname;
				curr2->nextname = NULL;
				delete curr2;
				return true;
			}
			else {
				for (; curr1 != NULL; curr1 = curr1->nextage) {
					if (curr2->nameTLL == heada->nameTLL) {
						heada = curr1->nextage;
						curr1->nextage = NULL;
					}
					else if (curr2->nameTLL == curr1->nameTLL) {
						prev1->nextage = curr1->nextage;
						curr1->nextage = NULL;

					}
					prev1 = curr1;
				}
				
				prev2->nextname = curr2->nextname;
				curr2->nextname = NULL;
				delete curr2;
				return true;
			}
		}
		prev2 = curr2;
	}
	return false;
}
TermLL::~TermLL() {
	for (TLLNode* n; !isEmpty(); ) {
		n = headn->nextname;
		delete headn;
		headn = n;
	}
}
void TermLL::update(string name, int age){
	remove(name);
	add(name, age);

}
void TermLL::loadFile(string filename) {
	cout << "!!Loading Data!!" << endl;
	ifstream theFile(filename);
	int age;
	string name;
	while (theFile >> name >> age) {
		cout << name <<" " << age << endl;
		add(name, age);
		}
	theFile.close();
	}

void TermLL::saveToFileByAge(string filename){
	cout << "!!Saving Data according to sorted age list!!" << endl;
	ofstream theFile(filename);
	for (TLLNode* tmp3 = heada; tmp3 != 0; tmp3 = tmp3->nextage)
		theFile << tmp3->nameTLL << " " << tmp3->ageTLL << "\n";
	theFile.close();


}
void TermLL::saveToFileByName(string filename){
	cout << "!!Saving Data according to sorted name list!!" << endl;
	ofstream theFile(filename);
	for (TLLNode* tmp3 = headn; tmp3 != 0; tmp3 = tmp3->nextname)
		theFile << tmp3->nameTLL << " " << tmp3->ageTLL << "\n";
	theFile.close();
}
void TermLL::printByAge() {
	for (TLLNode* tmp3 = heada; tmp3 != 0; tmp3 = tmp3->nextage)
		cout << tmp3->nameTLL << " " << tmp3->ageTLL << "\n";

}
void TermLL::printByName() {
	for (TLLNode* tmp3 = headn; tmp3 != 0; tmp3 = tmp3->nextname)
		cout << tmp3->nameTLL << " " << tmp3->ageTLL << "\n";

}

