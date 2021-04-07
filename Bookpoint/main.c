#include <stdio.h>

#include "Utility/utils.h"

int main() {

    // TODO: Interactive menu

    // Initializing global variables
    DATE_COUNT = 0;
    PUBLISHER_COUNT = 0;
    AUTHOR_COUNT = 0;

    DATES = readDatesFromFile("dates.txt");
    PUBLISHERS = readPublishersFromFile("publishers.txt");
    AUTHORS = readPeopleFromFile("people.txt");
    BOOKS = readBooksFromFile("books.txt");
    // ----------

    for(int i = 0; i < BOOK_COUNT; i++)
        printBook(&BOOKS[i]);


    return 0;
}