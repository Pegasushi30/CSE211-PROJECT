
#include <iostream>
#include <fstream>
using namespace std;

class TLLNode {
public:
    TLLNode() {
        nextname = 0;
        nextage = 0;
        ageTLL = 0;
    }
    TLLNode(const string & n,const int& a, TLLNode* nextn = 0, TLLNode* nexta = 0 ) {
        nameTLL = n; ageTLL = a; nextname = nextn; nextage = nexta;
    }
    string nameTLL;
    int ageTLL;
    TLLNode* nextname;
    TLLNode* nextage;
};

class TermLL {
public:
    TermLL() {
        headn= heada = taila =tailn = 0;
    }
    ~TermLL();
    int isEmpty() {
        return headn==0;
    }
    void add(string name, int age);
    bool remove(string name);
    void update(string name, int age);
    void printByAge();
    void printByName();
    void loadFile(string filename);
    void saveToFileByAge(string filename);
    void saveToFileByName(string filename);
private:
    TLLNode* headn,*heada,*tailn,*taila;

};
