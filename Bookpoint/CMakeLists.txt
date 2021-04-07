cmake_minimum_required(VERSION 3.17)
project(Bookpoint C)

set(CMAKE_C_STANDARD 99)

add_executable(Bookpoint
        main.c
        enums.h
        Date/Date.c
        Date/Date.h
        Person/Person.c
        Person/Person.h
        Publisher/Publisher.c
        Publisher/Publisher.h
        Book/Book.c
        Book/Book.h
        Utility/utils.c
        Utility/utils.h)