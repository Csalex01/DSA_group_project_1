#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "../Utility/utils.h"

/**
 *      MAIN MENU
 */

/// Activate Menu
void activateMenu() {
    int choice;

    while (true) {
        printf("\n");
        printf("========> BOOKPOINT <========\n");
        printf("         -> MENU <-        \n\n");
        printf("> 1. Date operations\n");
        printf("> 2. Person operations\n");
        printf("> 3. Publisher operations\n");
        printf("> 4. Book operations\n");
        printf("> 5. Exit\n");
        printf("<--------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {

            /// Date operations
            case 1:
                dateOperations();
                break;

            /// Person operations
            case 2:
                personOperations();
                break;

            /// Publisher operations
            case 3:
                publisherOperations();
                break;

            /// Book operations
            case 4:
                bookOperations();
                break;

            /// Exit
            case 5:
                printf("=========> Goodbye! <=========\n");
                freeVariables();
                exit(0);

            /// DEFAULT case
            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                freeVariables();
                exit(-1);
        }
    }
}

/**
 *      SUBMENUS
 */

/// Date operations
void dateOperations() {
    int choice;

    while (true) {
        printf("\n");
        printf("========> BOOKPOINT <========\n");
        printf("    -> DATE OPERATIONS <-  \n\n");
        printf("> 1. Print dates\n");
        printf("> 2. Sort dates in ascending order based on year\n");
        printf("> 3. Sort dates in descending order based on year\n");
        printf("> 4. Back to main menu\n");
        printf("<--------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {

            /// Print dates
            case 1:
                printDates();
                break;

                /// Sort dates in ascending order based on year
            case 2:
                printf("\n> Sorting dates in ascending order...\n");
                sortYearsByAscending();
                printf("> Done!\n");
                break;

                /// Sort dates in descending order based on year
            case 3:
                printf("\n> Sorting dates in descending order...\n");
                sortYearsByDescending();
                printf("> Done!\n");
                break;

                /// Back to main menu
            case 4:
                activateMenu();
                break;

                /// DEFAULT case
            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                freeVariables();
                exit(-1);
        }
    }
}

/// Person operations
void personOperations() {
    int choice;

    while (true) {
        printf("\n");
        printf("========> BOOKPOINT <========\n");
        printf("        -> AUTHORS <-        \n\n");
        printf("> 1. Get person by ID (Case sensitive)\n");
        printf("> 2. Print person by nationality\n");
        printf("> 3. Print person by birth date\n");
        printf("> 4. Print adults\n");
        printf("> 5. Back to main menu\n");
        printf("<--------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {

            /// Get person by ID
            case 1:
                personOperations_getPersonByID();
                break;

            /// Print person by nationality
            case 2:
                personOperations_printPeopleByNationality();
                break;

            /// Print person by birth date
            case 3:
                personOperations_printPeopleByBirthDate();
                break;

            /// Print adults
            case 4:
                printf("\nAdults: \n");
                printAdults();
                break;

            /// Back to main menu
            case 5:
                activateMenu();
                break;

            /// DEFAULT case
            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                freeVariables();
                exit(-1);
        }
    }
}

/// Publisher operations
void publisherOperations() {
    int choice;

    while(true) {
        printf("\n");
        printf("========> BOOKPOINT <========\n");
        printf("       -> PUBLISHERS <-        \n\n");
        printf("> 1. Print all publishers\n");
        printf("> 2. Get publisher by name (Case sensitive)\n");
        printf("> 3. Get publisher by address (Case sensitive)\n");
        printf("> 4. Check valid address for a publisher\n");
        printf("> 5. Publisher count between two foundation dates\n");
        printf("> 6. Sort publishers by year\n");
        printf("> 7. Back to main menu\n");
        printf("<--------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);

        switch (choice) {

            /// Print all publishers
            case 1:
                printf("\nAll the publishers: \n");

                for(int i = 0; i < PUBLISHER_COUNT; i++)
                    printPublisher(&PUBLISHERS[i]);

                printf("\n");
                break;

            /// Get publisher by name
            case 2:
                publisherOperations_getPublisherByName();
                break;

            /// Get publisher by address
            case 3:
                publisherOperations_getPublisherByAddress();
                break;

            /// Check valid address for a publisher
            case 4:
                publisherOperations_checkExistenceByAddress();
                break;

            /// Publisher count between two foundation dates
            case 5:
                publisherOperations_publisherCountBetweenDates();
                break;

            /// Sort publishers by year
            case 6:
                printf("\n> Sorting publishers by foundation date in ascending order...");
                sortPublishersByYear();
                printf("\n> Done!\n");
                break;

            /// Back to main menu
            case 7:
                activateMenu();
                break;

            /// DEFAULT case
            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                freeVariables();
                exit(-1);
        }
    }
}

/// Book operations
void bookOperations() {
    int choice;

    while (true) {
        printf("\n");
        printf("========> BOOKPOINT <========\n");
        printf("         -> BOOKS <-        \n\n");
        printf("> 1. Print all books\n");
        printf("> 2. Print books based on author ID (Case sensitive)\n");
        printf("> 3. Print books based on page numbers\n");
        printf("> 4. Print books based on price range\n");
        printf("> 5. Print books based on publish date\n");
        printf("> 6. Print books based on cover type\n");
        printf("> 7. Sort books by price in ascending order\n");
        printf("> 8. Sort books by price in descending order\n");
        printf("> 9. Sort books by page numbers in ascending order\n");
        printf("> 10. Sort books by page numbers in descending order\n");
        printf("> 11. Sort books by publish year in descending order\n");
        printf("> 12. Sort books by publish year in descending order\n");
        printf("> 13. Back to main menu\n");
        printf("<--------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);
        printf("\n");

        switch (choice) {

            ///  Print all books
            case 1:
                printf("\n> All the available books: \n");
                for (int i = 0; i < BOOK_COUNT; i++)
                    printBook(&BOOKS[i]);
                break;

            /// Print books based on author ID
            case 2:
                bookOperations_authorID();
                break;

            /// Print books based on page numbers
            case 3:
                bookOperations_pageNumber();
                break;

            /// Print books based on price range
            case 4:
                bookOperations_priceRange();
                break;

            /// Print books based on publish date
            case 5:
                bookOperations_publishDate();
                break;

            ///  Print books based on cover type
            case 6:
                bookOperations_cover();
                break;

            /// Sort books by price in ascending order
            case 7:
                printf("\n> Sorting books by price in ascending order...");
                sortBooksByPriceAscending();
                printf("\n> Done!\n");
                break;

            /// Sort books by price in descending order
            case 8:
                printf("\n> Sorting books by price in descending order...");
                sortBooksByPriceDescending();
                printf("\n> Done!\n");
                break;

            /// Sort books by page numbers in ascending order
            case 9:
                printf("\n> Sorting books by page numbers in ascending order...");
                sortBooksByPageNumberAscending();
                printf("\n> Done!\n");
                break;

            /// Sort books by page numbers in descending order
            case 10:
                printf("\n> Sorting books by page numbers in descending order...");
                sortBooksByPageNumberDescending();
                printf("\n> Done!\n");
                break;

            /// Sort books by publish year in ascending order
            case 11:
                printf("\n> Sorting books by publish year in ascending order...");
                sortBooksByPublishYearAscending();
                printf("\n> Done!\n");
                break;

            /// Sort books by publish year in descending order
            case 12:
                printf("\n> Sorting books by publish year in ascending order...");
                sortBooksByPublishYearDescending();
                printf("\n> Done!\n");
                break;

            /// Back to main menu
            case 13:
                activateMenu();
                break;

            /// DEFAULT case
            default:
                printf("==> Error: UNDEFINED INPUT <==\n");
                freeVariables();
                exit(-1);
        }
    }
}

/**
 *  HELPER FUNCTIONS
 */

/// Helper functions for bookOperations()

/// This function prints out all the BOOKS with a given author
void bookOperations_authorID() {
    char authorID[7];

    printf("\nAuthor ID: ");
    scanf("%s", authorID);

    printBooksBasedOnAuthorID(authorID);
}

/// This function prints out all the BOOKS with a given page number
void bookOperations_pageNumber() {
    int pageNumber;

    printf("\nPage numbers: ");
    scanf("%i", &pageNumber);

    printBooksBasedOnPageNumbers(pageNumber);
}

/// This function prints out all the BOOKS within a price range
void bookOperations_priceRange() {
    float price1, price2;

    printf("\nMinimum price: ");
    scanf("%f", &price1);

    printf("\nMaximum price: ");
    scanf("%f", &price2);

    printBooksBasedOnPriceRange(price1, price2);
}

/// This function prints out all the BOOKS with a given publish date
void bookOperations_publishDate() {
    int year, month, day;

    printf("Year: ");
    scanf("%i", &year);

    printf("Month: ");
    scanf("%i", &month);

    printf("Day: ");
    scanf("%i", &day);

    Date *date = createDate(year, month, day);

    printBooksBasedOnPublishDate(date);
}

/// This function prints out all the BOOKS with a given cover type
void bookOperations_cover() {
    int choice;

    printf("\n");
    printf("========> BOOKPOINT <========\n");
    printf("         -> COVER <-        \n\n");
    printf("> 1. Softcover\n");
    printf("> 2. Hardcover with Imagewrap\n");
    printf("> 3. Hardcover with Dustjacket\n");
    printf("<--------------------------->\n");
    printf("> Choice: ");

    scanf("%i", &choice);
    printf("\n");

    switch (choice) {

        /// Softcover
        case 1:
            printBooksBasedOnCoverType(SOFTCOVER);
            break;

        /// Hardcover with Imagewrap
        case 2:
            printBooksBasedOnCoverType(HARDCOVER_IMAGEWRAP);
            break;

        /// Hardcover with Dustjacket
        case 3:
            printBooksBasedOnCoverType(HARDCOVER_DUSTJACKET);
            break;

        /// DEFAULT case
        default:
            printf("==> Error: UNDEFINED INPUT <==\n");
            freeVariables();
            exit(-1);
    }
}

/// Helper functions for personOperations()

/// This function prints out the given author based on ID
void personOperations_getPersonByID() {
    char id[6];

    printf("\nID: ");
    scanf("%s", id);
    printf("\n");

    printPerson(getPersonByID(id));
}

/// This function prints out all the authors with a given nationality
void personOperations_printPeopleByNationality() {
    int choice;

    printf("\n");
    printf("========> BOOKPOINT <========\n");
    printf("      -> NATIONALITY <-      \n\n");
    printf("> 1. Hungarian\n");
    printf("> 2. Romanian\n");
    printf("> 3. German\n");
    printf("> 4. French\n");
    printf("> 5. American\n");
    printf("> 6. British\n");
    printf("> 7. Danish\n");
    printf("> 8. Icelandic\n");
    printf("> 9. Irish\n");
    printf("> 10. Swedish\n");
    printf("<--------------------------->\n");
    printf("> Choice: ");

    scanf("%i", &choice);
    printf("\n");

    switch (choice) {

        /// Hungarian
        case 1:
            printPersonByNationality(HUNGARIAN);
            break;

        /// Romanian
        case 2:
            printPersonByNationality(ROMANIAN);
            break;

        /// German
        case 3:
            printPersonByNationality(GERMAN);
            break;

        /// French
        case 4:
            printPersonByNationality(FRENCH);
            break;

        /// American
        case 5:
            printPersonByNationality(AMERICAN);
            break;

        /// British
        case 6:
            printPersonByNationality(BRITISH);
            break;

        /// Danish
        case 7:
            printPersonByNationality(DANISH);
            break;

        /// Icelandic
        case 8:
            printPersonByNationality(ICELANDIC);
            break;

        /// Irish
        case 9:
            printPersonByNationality(IRISH);
            break;

        /// Swedish
        case 10:
            printPersonByNationality(SWEDISH);
            break;

        /// DEFAULT case
        default:
            printf("==> Error: UNDEFINED INPUT <==\n");
            freeVariables();
            exit(-1);
    }
}

/// This function prints out all the authors with a given birth date
void personOperations_printPeopleByBirthDate() {
    int year, month, day;
    Date *date = NULL;

    printf("Year: ");
    scanf("%i", &year);

    printf("Month: ");
    scanf("%i", &month);

    printf("Day: ");
    scanf("%i", &day);

    printf("\n");

    date = createDate(year, month, day);

    printPersonByBirthDate(date);
}

/// Helper functions for publisherOperations()

/// This function prints out a publisher with a given name
void publisherOperations_getPublisherByName() {
    char name[25];

    printf("\nName: ");
    scanf("%s", name);
    printf("\n");

    printPublisher(getPublisherByName(name));
}

/// This function prints out a publisher with a given address
void publisherOperations_getPublisherByAddress() {
    char address[25];

    printf("\nAddress: ");
    scanf("%s", address);
    printf("\n");

    printPublisher(getPublisherByAddress(address));
}

/// This function prints out a publisher if it exists with a given address,
/// otherwise it prints an error message
void publisherOperations_checkExistenceByAddress() {
    char address[25];

    printf("\nAddress: ");
    scanf("%s", address);
    printf("\n");

    if(checkExistenceByAddress(address))
        printPublisher(getPublisherByAddress(address));
    else
        printf("There is no publishers with the given address!\n");
}

/// This function prints out how many publishers were founded between two dates
void publisherOperations_publisherCountBetweenDates() {
    int minYear, minMonth, minDay;
    int maxYear, maxMonth, maxDay;

    Date* minDate;
    Date* maxDate;

    printf("Minimum year: ");
    scanf("%i", &minYear);

    printf("Minimum month: ");
    scanf("%i", &minMonth);

    printf("Minimum day: ");
    scanf("%i", &minDay);

    printf("Maximum year: ");
    scanf("%i", &maxYear);

    printf("Maximum month: ");
    scanf("%i", &maxMonth);

    printf("Maximum day: ");
    scanf("%i", &maxDay);

    minDate = createDate(minYear, minMonth, minDay);
    maxDate = createDate(maxYear, maxMonth, maxDay);

    printf("\nPublisher count between %i-%i-%i and %i-%i-%i: %i\n",
           minYear, minMonth, minDay, maxYear, maxMonth, maxDay,
           publisherCountBetweenDates(minDate, maxDate));
}