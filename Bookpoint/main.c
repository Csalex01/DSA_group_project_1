#include <stdio.h>

#include "Utility/utils.h"
#include "Menu/menu.h"

int main() {

    /// Initializing global variables (DO NOT REMOVE)
    DATE_COUNT = 0;
    PUBLISHER_COUNT = 0;
    AUTHOR_COUNT = 0;

    DATES = readDatesFromFile("dates.txt");
    PUBLISHERS = readPublishersFromFile("publishers.txt");
    AUTHORS = readPeopleFromFile("people.txt");
    BOOKS = readBooksFromFile("books.txt");
    /// ----------

    /// TODO: Interactive menu (WORK IN PROGRESS)

    activateMenu();

    return 0;
}