#ifndef ADDRESS_H
#define ADDRESS_H
#include <stdbool.h>
#include "lexer.h"

typedef struct {
    char class;
    char* IPv4;
    int VALUES_N;
    int* values;
} address_T;

address_T* initAddress(char* IPv4);
char addressGetClass(address_T* address);
bool addressValueIsValid(int addressValue);
int addressFirstValue(address_T* address);
void addressSetValuesFromLexer(address_T* address, lexer_T* lexer);
void addressError();
void addressSetClass(address_T* address);

void addressShowInfo(address_T* address);

#endif //ADDRESS_H