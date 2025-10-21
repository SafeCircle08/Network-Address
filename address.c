#include "include\address.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

address_T* initAddress(char* IPv4) {
    address_T* address = calloc(1, sizeof(address_T));
    address->IPv4 = IPv4;
    address->VALUES_N = 4;
    address->values = calloc(
        address->VALUES_N,
        address->VALUES_N * sizeof(int)
    );
    return address;
}

void addressError() {
    printf("Inserted IPv4 address Invalid.");
    exit(-1);
}

bool addressValueIsValid(int addressValue) {
    return (addressValue >= 0 && addressValue <= 255);
}

void addressSetValuesFromLexer(address_T* address, lexer_T* lexer) {
    for (int i = 0; i < address->VALUES_N; i++) {
        if (addressValueIsValid(lexer->collectedNums[i])) {
            address->values[i] = lexer->collectedNums[i];
        } else { addressError(); }
    }
}

void addressSetClass(address_T* address) {
    char addressClass = addressGetClass(address);
    address->class = addressClass;
}

int addressFirstValue(address_T* address) {
    return address->values[0];
}

char addressGetClass(address_T* address) {
    if (addressFirstValue(address) >= 0 && addressFirstValue(address) <= 127) {
        return 'A';
    } else if (addressFirstValue(address) > 127 && addressFirstValue(address) <= 191) {
        return 'B';
    } else if (addressFirstValue(address) > 191 && addressFirstValue(address) <= 223) {
        return 'C';
    }
    addressError();
}

void addressShowInfo(address_T* address) {
    printf("IPv4 value: %s\n", address->IPv4);
    printf("IPv4 class: %c\n", address->class);
    for (int i = 0; i < address->VALUES_N; i++) {
        printf("First Octect decimal value: %d\n", address->values[i]);
    }
}