#include <stdio.h>

#include "Book/Book.h"
#include "Date/Date.h"
#include "Person/Person.h"
#include "Publisher/Publisher.h"
#include "Utility/utils.h"

#include "enums.h"

int main() {

    Date* dates = readFromFile("dates.txt");

    printf("Rendezve#1 (novekvo): \n");
    sortYearsByAscending(dates, 100);
    printDates(dates, 100);

    printf("Rendezve#1 (csokkeno): \n");
    sortYearsByDescending(dates, 100);
    printDates(dates, 100);

    for(int i = 0; i < 100; i++) {
        destroyDate(&dates[i]);
    }

    return 0;
}

