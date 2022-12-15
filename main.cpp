#include <iostream>
#include "lexer.h"



int main() {
    std::cout << "Hello, World!" << std::endl;
    struct Token t = getToken();
    std::cout << t.token_type << std::endl;
    std::cout << t.numval << std::endl;
    std::cout << t.IdentifierStr << std::endl;
    return 0;
}
