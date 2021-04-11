#include <stdio.h>

#include "Utility/utils.h"
#include "Menu/menu.h"

int main() {

    /// Initializing global variables + error handling (DO NOT REMOVE)
    DATE_COUNT = 0;
    PUBLISHER_COUNT = 0;
    AUTHOR_COUNT = 0;

    DATES = readDatesFromFile("dates.txt");
    if(!DATES) {
        printf("An error occured while allocating memory for vector DATES!");
        return -1;
    }

    PUBLISHERS = readPublishersFromFile("publishers.txt");
    if(!PUBLISHERS) {
        printf("An error occured while allocating memory for vector PUBLISHERS!");
        return -2;
    }

    AUTHORS = readPeopleFromFile("people.txt");
    if(!AUTHORS) {
        printf("An error occured while allocating memory for vector AUTHORS!");
        return -3;
    }

    BOOKS = readBooksFromFile("books.txt");
    if(!BOOKS) {
        printf("An error occured while allocating memory for vector BOOKS!");
        return -4;
    }
    /// ----------

    /// Show the main menu, because it is safe to start the program
    activateMenu();

    return 0;
}