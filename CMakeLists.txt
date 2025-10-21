cmake_minimum_required(VERSION 3.31)
project(NetworkAddress)

set(CMAKE_C_STANDARD 17)

add_executable(NetworkAddress main.c
        include/lexer.h
        lexer.c
        include/address.h
        address.c
        include/addressClassesConstants.h)
