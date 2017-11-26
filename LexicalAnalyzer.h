/**
 * @name Compiler C++ -> Assembly language
 *
 * @author Uliana Stefanishyna
 * @ingroup IO-52
 * @date 26.11.2017
 * @version 1.0
 *
 * @class LexicalAnalyzer contains functions for checking lexical errors
 * */

#ifndef COMPILER_LEXICALANALIZER_H
#define COMPILER_LEXICALANALIZER_H

#include "string"
#include "CheckStructure.h"

using namespace std;

enum Token{
    VARIABLE,
    NOTFIRSTSIGN
};

class LexicalAnalyzer : CheckStructure {
protected:
    pair<string,string> m_pairErrors;
    vector<pair<string,string>> m_vecErrors;
    vector<string> vStrSignsNotFirst = {"+=", "-=", "*=", "/=", ";", "[", "]", "+", "="}; //right; not first
public:
    const vector<pair<string, string>> &getM_vecErrors() const;

protected:
    string variable;
    Token m_token;
public:
    bool isCorrectVariable(string str, int index);
    void endVariable(char ch, int index, string str);
};


#endif //COMPILER_LEXICALANALIZER_H
