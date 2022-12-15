//
// Created by charlotte on 15/12/22.
//
#include <iostream>
#include "lexer.h"

Token getToken() {
    double numval;
    std::string IdentifierStr;
    int lastChar = ' ';
    while (isspace(lastChar))
        lastChar = getchar();

    if(isalpha(lastChar)){
        IdentifierStr = lastChar;
        while (std::isalnum(lastChar = getchar()))
            IdentifierStr += lastChar;
        if (IdentifierStr == "def")
            return {token_def,IdentifierStr,0};
        if(IdentifierStr == "extern")
            return {token_extern,IdentifierStr,0};
        return {token_identifier,IdentifierStr,0};
    }

    if(std::isdigit(lastChar) || lastChar == '.'){
        bool dot = (lastChar == '.');
        std::string numStr;
        numStr += lastChar;
        lastChar = getchar();
        while (std::isdigit(lastChar) || (lastChar == '.')){
            if(lastChar == '.'){
                if(dot){
                    IdentifierStr = "too much dottttsss";
                    return {token_error,IdentifierStr,0};
                }
                dot = true;
            }
            numStr += lastChar;
            lastChar = getchar();
        }
        numval = strtod(numStr.c_str(),0);
        return {token_number,"",numval};
    }

    if (lastChar == '#') {
        do
            lastChar = getchar();
        while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

        if (lastChar != EOF)
            return getToken();
    }
    if (lastChar == EOF)
        return {token_eof,"",0};

    int ThisChar = lastChar;
    return {ThisChar,"",0};
}