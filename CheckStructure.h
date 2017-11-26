/**
 * @name Compiler C++ -> Assembly language
 *
 * @author Uliana Stefanishyna
 * @ingroup IO-52
 * @date 26.11.2017
 * @version 1.0
 *
 * @class CheckStructure contains procedures for analyzing structure of given code on C++
 *
 * */
#ifndef COMPILER_ISRIGHTSTRUCTOFPROGRAM_H
#define COMPILER_ISRIGHTSTRUCTOFPROGRAM_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class CheckStructure {

    string m_sMainType;
    int m_coutTypes;        //for checkiing return value
    int m_countCalls;
    bool m_fWrongType = false;

protected:
    vector<string> m_errors;
public:
    CheckStructure() : m_coutTypes(0), m_countCalls(0){}

    vector<string> types = {"double", "int", "void", "string"};
    string nMain = "main";
    string nReturn = "return";
    vector<string> delimiters = {"(", ")", "{", ";","}","()"};

    bool isType(string begin);
    bool isMain(string nameMain);
    bool isOpenedPar(string ch);
    bool isClosedPar(string ch);
    bool isOpenedBody(string ch);
    bool isReturn(string nameReturn);
    bool isTypeOfReturnValue(string val);
    bool isClosedStatement(string ch);
    bool isClosedBody(string ch);


    void check(string x);
    void print();
};


#endif //COMPILER_ISRIGHTSTRUCTOFPROGRAM_H
