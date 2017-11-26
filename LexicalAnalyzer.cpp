/**
 * @name Compiler C++ -> Assembly language
 *
 * @author Uliana Stefanishyna
 * @ingroup IO-52
 * @date 26.11.2017
 * @version 1.0
 *
 * */


#include "LexicalAnalyzer.h"

bool LexicalAnalyzer::isCorrectVariable(string str, int index) {
    int ch = str[index];
    if (((ch >= 65) && (ch <= 90)) || ((ch >= 97) && (ch <= 122)) || ((ch >= 48) && (ch <= 57)) || (ch == '#') ||
        (ch == '_') || (ch == '$')) {
        if (((ch == '#') || (ch == '$')) || ((ch >= 48) && (ch <= 57))) {

            m_pairErrors.first = "Invalid syntax. It doesn't match to C++ variable";
            endVariable(ch,index, str);
            m_pairErrors.second = variable;
            m_vecErrors.push_back(m_pairErrors);
            variable="";
            m_token = VARIABLE;
            return false;
        }
        else{
            endVariable(ch,index, str);
            variable ="";
            m_token = VARIABLE;
            return true;
        }
    }
    return false;
}
void LexicalAnalyzer::endVariable(char ch, int index, string str){
    while(true){
        for(string temp : vStrSignsNotFirst){
            if((temp == str.substr(index,2) || (temp == str.substr(index,1))))
                return;
        }
        variable += ch;
        index++;
        ch = str[index];
    }
}

const vector<pair<string, string>> &LexicalAnalyzer::getM_vecErrors() const {
    return m_vecErrors;
}
