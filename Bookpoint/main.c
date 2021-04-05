#include <stdio.h>

#include "Book/Book.h"
#include "Date/Date.h"
#include "Person/Person.h"
#include "Publisher/Publisher.h"
#include "Utility/utils.h"
#include "enums.h"

int main() {

    Date* dates = readFromFile("dates.txt");

    printf("%i", DATE_COUNT);

    return 0;
}