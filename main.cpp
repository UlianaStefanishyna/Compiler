/**
 * @author Uliana Stefanishyna
 * @date 26.11.2017
 * @version 1.0
 * @mainpage
 *
 */
#include <iostream>
#include <fstream>
#include "CheckStructure.h"
using namespace std;

ifstream openFile(string filename);
void analyze();

int main() {

    analyze();

    return 0;
}

void analyze(){

    CheckStructure check;
    string x;
    ifstream inFile = openFile("file");
    while (!inFile.eof()){
        inFile >> x;
        check.check(x);
    }
    check.print();


    inFile.close();
}

ifstream openFile(string filename){
    ifstream inFile;
    inFile.open(filename);
    string x = "";

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    return inFile;
}