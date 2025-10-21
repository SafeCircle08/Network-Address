#include "include/lexer.h"
#include "include/address.h"
#include <stdlib.h>

lexer_T* initLexer(char* contents) {
    lexer_T* lexer = calloc(1, sizeof(lexer_T));
    lexer->octects = 4;
    lexer->contents = contents;
    lexer->i = 0;
    lexer->c = lexer->contents[lexer->i];
    lexer->collectedNums = calloc(lexer->octects, sizeof(int));
    return lexer;
}

int charToInt(char c) {
    return c - '0';
}

int stringToInt(const char* str) {
    int result = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

char lexerActualChar(lexer_T* lexer) {
    return (lexer->c);
}

bool lexerCharIs(lexer_T* lexer, const char checkC) {
    return (lexer->c == checkC);
}

bool lexerCanAdvance(lexer_T* lexer) {
    return (lexer->c != '\0');
}

void lexerAdvance(lexer_T* lexer) {
    lexer->i++;
    lexer->c = lexer->contents[lexer->i];
}

int lexerCollectNum(lexer_T* lexer) {
    char nums[5];
    int i = 0;
    while (!lexerCharIs(lexer, '.') && lexerCanAdvance(lexer)) {
        if (i >= 3) { addressError(); }
        nums[i++] = lexerActualChar(lexer);
        lexerAdvance(lexer);
    }
    nums[i] = '\0';
    int n = stringToInt(nums);
    return n;
}

void lexerCollectNums(lexer_T* lexer) {
    int i = 0;

    while (lexerCanAdvance(lexer)) {
        if (lexerCharIs(lexer, '.')) {
            lexerAdvance(lexer);
            continue;
        }
        int n = lexerCollectNum(lexer);
        lexer->collectedNums[i++] = n;
    }
}