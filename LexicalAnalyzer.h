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

enum Token {
    VARIABLE,
    NOTFIRSTSIGN
};

class LexicalAnalyzer : CheckStructure {
protected:
    pair<string, string> m_pairErrors;
    vector<pair<string, string>> m_vecErrors;
    vector<string> m_DefinedVariables;
    int index;
    string m_Statement;                 //store one statement
    vector<string> vStrSignsNotFirst = {"+=", "-=", "*=", "/=", ";", "[", "]", "+", "=", "/", "-", "*", "(",
                                        ")"}; //right; not first
public:
    LexicalAnalyzer() : index(0) {}

    const vector<pair<string, string>> &getM_vecErrors() const;

    const string &getM_Statement() const;

protected:
    string variable;
    Token m_token;
public:
    bool isCorrectVariable(string str);

    bool isFirstCorrect(string x);              //correct if not a sign
    void lookingForEndOfStatement(string str);

    bool isSign(string x);

    void endVariable(string str);
};


#endif //COMPILER_LEXICALANALIZER_H
