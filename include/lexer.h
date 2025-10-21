#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>

typedef struct {
    int octects;
    char* contents;
    int i;
    char c;
    int* collectedNums;
} lexer_T ;

lexer_T* initLexer(char* contents);
bool lexerCharIs(lexer_T* lexer, const char checkC);
bool lexerCanAdvance(lexer_T* lexer);
void lexerAdvance(lexer_T* lexer);
int lexerCollectNum(lexer_T* lexer);
int charToInt(char c);
void lexerCollectNums(lexer_T* lexer);
char lexerActualChar(lexer_T* lexer);
int stringToInt(const char* str);

#endif //LEXER_H