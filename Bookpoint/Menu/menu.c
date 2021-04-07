#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "../Utility/utils.h"

/// Main Menu
void activateMenu() {
    int choice;

    while(true) {
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

        switch(choice) {
            case 1: dateOperations(); break;
            case 2: break;
            case 3: break;
            case 4: bookOperations(); break;
            case 5:
                printf("\n=========> Goodbye! <=========\n");
                freeVariables();
                exit(0);
            default:
                printf("\nError: UNDEFINED USER INPUT\n");
                freeVariables();
                exit(-1);
        }

        /// TODO: Clear the screen (Note: It will NOT work in the CLion simulated terminal)
    }
}

/// Date operations
void dateOperations() {
    int choice;

    while(true) {
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
        printf("\n<--------------------------->");

        switch(choice) {
            /// Print dates
            case 1:
                printf("\n> Printing %i dates... \n", DATE_COUNT);
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
                return;

            /// DEFAULT case
            default:
                printf("\nError: UNDEFINED USER INPUT\n");
                freeVariables();
                exit(-1);
        }
    }
}

/// Book operations
void bookOperations() {
    int choice;

    while(true) {
        printf("\n");
        printf("========> BOOKPOINT <========\n");
        printf("         -> BOOKS <-        \n\n");
        printf("> 1. Print all books\n");
        printf("> 2. Print books based on author ID\n");
        printf("> 3. Print books based on page numbers\n");
        printf("> 4. Print books based on price range\n");
        printf("> 5. Print books based on publish date\n");
        printf("> 6. Print books based on cover type\n");
        printf("> 10. Back to main menu\n");
        printf("<--------------------------->\n");
        printf("> Choice: ");

        scanf("%i", &choice);

        switch(choice) {
            ///  Print all books
            case 1:
                printf("\nAll the available books: \n");
                for(int i = 0; i < BOOK_COUNT; i++)
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

            /// Back to main menu
            case 10: return;

            /// DEFAULT case
            default:
                printf("\nError: UNDEFINED USER INPUT\n");
                freeVariables();
                exit(-1);
        }

        /// TODO: Clear the screen (Note: It will NOT work in the CLion simulated terminal)
    }
}

/// Helper functions for bookOperations()
void bookOperations_authorID() {
    char authorID[7];

    printf("\nAuthor ID: ");
    scanf("%s", authorID);

    printBooksBasedOnAuthorID(authorID);
}

void bookOperations_pageNumber() {
    int pageNumber;

    printf("\nPage numbers: ");
    scanf("%i", &pageNumber);

    printBooksBasedOnPageNumbers(pageNumber);
}

void bookOperations_priceRange() {
    float price1, price2;

    printf("\nMinimum price: ");
    scanf("%f", &price1);

    printf("\nMaximum price: ");
    scanf("%f", &price2);

    printBooksBasedOnPriceRange(price1, price2);
}

void bookOperations_publishDate() {
    int year, month, day;

    printf("\nYear: ");
    scanf("%i", &year);

    printf("\nMonth: ");
    scanf("%i", &month);

    printf("\nDay: ");
    scanf("%i", &day);

    Date* date = createDate(year, month, day);

    printBooksBasedOnPublishDate(date);
}

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

    switch(choice) {
        case 1:
            printBooksBasedOnCoverType(SOFTCOVER);
            break;
        case 2:
            printBooksBasedOnCoverType(HARDCOVER_IMAGEWRAP);
            break;
        case 3:
            printBooksBasedOnCoverType(HARDCOVER_DUSTJACKET);
            break;
        default:
            printf("\nError: UNDEFINED USER INPUT\n");
            freeVariables();
            exit(-1);
        }
}