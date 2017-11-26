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

void LexicalAnalyzer::lookingForEndOfStatement(string str){
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
const string &LexicalAnalyzer::getM_Statement() const {
    return m_Statement;
}

bool LexicalAnalyzer::isSign(string x){
    //for()
    return true;
}
bool LexicalAnalyzer::isCorrectVariable(string str) {
    int ch = str[index];
    if (((ch >= 65) && (ch <= 90)) || ((ch >= 97) && (ch <= 122)) || ((ch >= 48) && (ch <= 57)) || (ch == '#') ||
        (ch == '_') || (ch == '$')) {
        if (((ch == '#') || (ch == '$')) || ((ch >= 48) && (ch <= 57))) {

            m_pairErrors.first = "Invalid syntax. It doesn't match to C++ variable";
            endVariable(str);
            m_pairErrors.second = variable;
            m_vecErrors.push_back(m_pairErrors);
            variable="";
            m_token = VARIABLE;
            return false;
        }
        else{
            endVariable(str);
            m_DefinedVariables.push_back(variable);
            variable ="";
            m_token = VARIABLE;
            return true;
        }
    }
    return false;
}
void LexicalAnalyzer::endVariable(string str){
    while(true){
        for(string temp : vStrSignsNotFirst){
            if((temp == str.substr(index,2) || (temp == str.substr(index,1))))
                return;
        }
        variable += str[index];
        index++;
    }
}

const vector<pair<string, string>> &LexicalAnalyzer::getM_vecErrors() const {
    return m_vecErrors;
}

bool LexicalAnalyzer::isFirstCorrect(string x){
    int index = 0;
    for(string str : vStrSignsNotFirst){
        if((x.substr(index,1) == str) || (x.substr(index,2) == str))
            return false;
    }
    return true;
}
