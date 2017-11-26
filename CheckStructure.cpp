/**
 * @author Uliana Strfanishyna
 * @date 26.11.2017
 * @version 1.0
 *
 */

#include <iostream>
#include "CheckStructure.h"

bool CheckStructure::isType(string begin) {
    m_coutTypes++;
    for (string str : types) {
        if (begin == str) {
            if (m_coutTypes == 1)
                m_sMainType = str;
            return true;
        }
    }
    if (begin == "main") {
        m_errors.push_back("missed type of main()");
        m_countCalls++;
        return false;
    } else {
        m_errors.push_back("Wrong type of main()");
        m_fWrongType = true;
    }
    return false;
}

bool CheckStructure::isMain(string nameMain) {
    if (nameMain == nMain)
        return true;
    if ((nameMain.substr(4, 2) == delimiters[5]) && (nameMain.substr(0, 4) == nMain)) {
        m_countCalls += 2;
        if (nameMain.substr(6, 1) == delimiters[2]) {
            m_countCalls++;
            if (nameMain.substr(7, 6) == nReturn)
                m_countCalls++;
        }
        return true;
    }
    if (nameMain.substr(4, 1) == delimiters[0]) {
        m_countCalls++;
        return true;
    }
    m_errors.push_back("wrong name of main func");
    return false;
}

bool CheckStructure::isOpenedPar(string ch) {
    if (ch == delimiters[0])
        return true;
    if (ch == delimiters[5]) {
        m_countCalls++;
        return true;
    }
    m_errors.push_back("wrong char instead of open parentness");
    return false;
}

bool CheckStructure::isClosedPar(string ch) {
    if (ch == delimiters[1])
        return true;
    if (ch.substr(1, 1) == delimiters[2]) {
        m_countCalls++;
        return true;
    }
    m_errors.push_back("wrong char instead of close parentness");
    return false;
}

bool CheckStructure::isOpenedBody(string ch) {
    if (ch == delimiters[2])
        return true;
    if (ch.substr(0, 1) == "{") {
        isReturn(ch.erase(0,1));
        //m_countCalls++;
        if (ch.substr(6, 1) != delimiters[3]) {
            m_errors.push_back("wrong char after return statement");
            return false;
        }
        return true;
    }
    m_errors.push_back("wrong char instead of open body");
    return false;
}

bool CheckStructure::isReturn(string nameReturn) {
    if (nameReturn == nReturn)
        return true;
    if ((nameReturn.substr(0, 6) == nReturn) && (nameReturn.substr(6, 1) == delimiters[3]) && (m_sMainType == "void")) {
        m_countCalls += 2;
        if(nameReturn.substr(7,1) == delimiters[4])
            m_countCalls+=2;
        return true;
    }
    if((m_sMainType == "void") && (nameReturn == delimiters[4])){
        m_errors.push_back("missed body");
        m_countCalls+=3;
        return false;
    }

    m_errors.push_back("missed return statement");
    return false;
}

bool CheckStructure::isTypeOfReturnValue(string val) {
    if ((m_sMainType == "void") && (val.substr(0, val.size()) != delimiters[3])) {
        if(!m_fWrongType) {
            m_errors.push_back("wrong type of return statement");
        }
        if (val.substr(val.size()-1, 1) == delimiters[3]) {
            m_countCalls++;
            if (val.substr(2, 1) == delimiters[4])
                m_countCalls++;
        }

        return false;
    }
    if ((m_sMainType != "void") && (val.substr(0,1) == delimiters[3])) {
        if(!m_fWrongType)
            m_errors.push_back("no return value");
        isClosedStatement(val);
        m_countCalls++;
        return false;
    }

    if ((m_sMainType == "void") && (val == delimiters[3]))
        m_countCalls++;
    if((m_sMainType != "void") && (val.erase(0,val.size()-1) == delimiters[3]))
        m_countCalls++;
    if((m_sMainType != "void") && (val.erase(0,val.size()-1) == delimiters[4]))
        if(val.erase(0,val.size()-2) == delimiters[3])
            m_countCalls+=2;
    return true;
}

bool CheckStructure::isClosedStatement(string ch) {
    if (ch == delimiters[3])
        return true;

    if (ch.erase(0,ch.size()-1) == delimiters[4]) {
        m_countCalls++;
        return true;
    }
    if (ch.substr(2, 1) == delimiters[4]) {
        m_countCalls++;
        return true;
    }
    m_errors.push_back("wrong char instead of column to close statement");
    return false;
}

bool CheckStructure::isClosedBody(string ch) {
    if (ch == delimiters[4])
        return true;
    if (ch.substr(1, 1) == delimiters[4]) {
        return true;
    }

    m_errors.push_back("wrong char instead of close body");
    return false;
}

void CheckStructure::print() {
    for (unsigned i = 0; i < m_errors.size(); i++) {
        cout << i + 1 << ". " << m_errors[i] << endl;
    }
    if (m_errors.empty())
        cout << "All right" << endl;
}

void CheckStructure::check(string x) {
    m_countCalls++;
    switch (m_countCalls) {
        case 1:
            isType(x);
            break;
        case 2:
            isMain(x);
            break;
        case 3:
            isOpenedPar(x);
            break;
        case 4:
            isClosedPar(x);
            break;
        case 5:
            isOpenedBody(x);
            break;
        case 6:
            isReturn(x);
            break;
        case 7:
            isTypeOfReturnValue(x);
            break;
        case 8:
            isClosedStatement(x);
            break;
        case 9:
            isClosedBody(x);
            break;
        default:
            break;
    }
}