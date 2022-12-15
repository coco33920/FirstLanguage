#include <iostream>


enum Token {
    token_eof = -1,

    token_def = -2,
    token_extern = -3,

    token_identifier = -4,
    token_number = -5,
    token_error = -6,

};

static std::string IdentifierStr;
static double numval;

static int getTokken() {
    static int lastChar = ' ';
    while (isspace(lastChar))
        lastChar = getchar();

    if(isalpha(lastChar)){
        IdentifierStr = lastChar;
        while (std::isalnum(lastChar = getchar()))
            IdentifierStr += lastChar;
        if (IdentifierStr == "def")
            return token_def;
        if(IdentifierStr == "extern")
            return token_extern;
        return token_identifier;
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
                    return token_error;
                }
                dot = true;
            }
            numStr += lastChar;
            lastChar = getchar();
        }
        numval = strtod(numStr.c_str(),0);
        return token_number;
    }

    if (lastChar == '#') {
        do
            lastChar = getchar();
        while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

        if (lastChar != EOF)
            return getTokken();
    }
    if (lastChar == EOF)
        return token_eof;

    int ThisChar = lastChar;
    lastChar = getchar();
    return ThisChar;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int s = getTokken();
    std::cout << s << std::endl;
    std::cout << numval << std::endl;
    std::cout << IdentifierStr << std::endl;
    return 0;
}
