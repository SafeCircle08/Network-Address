#include "include\lexer.h"
#include "include\address.h"

int main() {
    char* ipAddress = "143.8.1.0";

    lexer_T* lexer = initLexer(ipAddress);
    lexerCollectNums(lexer);

    address_T* address = initAddress(ipAddress);
    addressSetValuesFromLexer(address, lexer);
    addressSetClass(address);
    addressShowInfo(address);
}