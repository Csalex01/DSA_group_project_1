//
// Created by csill on 4/7/2021.
//

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "../Utility/utils.h"

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
            case 1:
                dateOperations();
                break;
            case 2: break;
            case 3: break;
            case 4: break;
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
            case 1:
                printf("\n> Printing %i dates... \n", DATE_COUNT);
                printDates();
                break;
            case 2:
                printf("\n> Sorting dates in ascending order...\n");
                sortYearsByAscending();
                printf("> Done!\n");
                break;
            case 3:
                printf("\n> Sorting dates in descending order...\n");
                sortYearsByDescending();
                printf("> Done!\n");
                break;
            case 4:
                return;
            default:
                printf("\nError: UNDEFINED USER INPUT\n");
                freeVariables();
                exit(-1);
        }
    }
}