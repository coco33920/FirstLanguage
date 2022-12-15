//
// Created by charlotte on 15/12/22.
//

#ifndef FIRSTLANGUAGE_LEXER_H
#define FIRSTLANGUAGE_LEXER_H

enum TokenType {
    token_eof = -1,

    token_def = -2,
    token_extern = -3,

    token_identifier = -4,
    token_number = -5,
    token_error = -6,
};


struct Token {
    int token_type;
    std::string IdentifierStr;
    double numval;
};
Token getToken();

#endif //FIRSTLANGUAGE_LEXER_H
