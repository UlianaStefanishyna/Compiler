/**
 * @name Compiler C++ -> Assembly language
 *
 * @author Uliana Stefanishyna
 * @ingroup IO-52
 * @date 26.11.2017
 * @version 1.0
 *
 * */

#include "SyntaxAnalyzer.h"


void SyntaxAnalyzer::lookingForEndOfStatement(string str){
    unsigned index = 0;
    bool fOpened = false;
    for(index; ;index++){
        if(str[index] == ' ')
            continue;
        if(str[index] == ';'){
            m_Statement.push_back(str[index]);
            break;
        }

        if(fOpened)
            m_Statement.push_back(str[index]);
        if(str[index] == '{')
            fOpened = true;
    }
    cout << m_Statement << endl;
    return;
}

bool SyntaxAnalyzer::isFirstCorrect(string x){
    int index = 0;
    for(string str : vStrSignsNotFirst){
        if((x.substr(index,1) == str) || (x.substr(index,2) == str))
            return false;
    }
    return true;
}

const string &SyntaxAnalyzer::getM_Statement() const {
    return m_Statement;
}
