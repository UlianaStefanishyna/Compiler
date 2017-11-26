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

public:


public:
    vector<char> vCharSigns = {'!', '*', '(', '{'};
    vector<char> vAllowedAfterVariable = {';', '[', '+', '='};
    vector<string> vStrSigns = {"--", "++"};
    vector<char> vCharSignsNotFirst = {';', '[', ']', '+', '-', '*', '/', '='};

    void lookingForEndOfStatement(string str);  //get one statement
    bool isFirstCorrect(string x);
    bool isSign(string x);

};

#endif //COMPILER_SYNTAXANALYZER_H
