/**
 * @name Compiler C++ -> Assembly language
 *
 * @author Uliana Stefanishyna
 * @ingroup IO-52
 * @date 26.11.2017
 * @version 1.0
 *
 * @class SyntaxAnalyzer contains functions to checking syntax errors
 *
 * */

#ifndef COMPILER_SYNTAXANALYZER_H
#define COMPILER_SYNTAXANALYZER_H

#include "LexicalAnalyzer.h"

class SyntaxAnalyzer : LexicalAnalyzer {
    string m_Statement;
public:
    const string &getM_Statement() const;

public:
    vector<char> vCharSigns = {'!', '*', '(', '{'};
    vector<char> vAllowedAfterVariable = {';', '[', '+', '='};
    vector<string> vStrSigns = {"--", "++"};
    vector<char> vCharSignsNotFirst = {';', '[', ']', '+', '-', '*', '/', '='};



    void lookingForEndOfStatement(string str);
    bool isFirstCorrect(string x);
};

#endif //COMPILER_SYNTAXANALYZER_H
