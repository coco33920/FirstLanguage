#include <iostream>


enum Token {
    token_eof = -1,

    token_def = -2,
    token_extern = -3,

    token_identifier = -4,
    token_number = -5,

};

static std::string IdentifierStr;
static double numval;


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
