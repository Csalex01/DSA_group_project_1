#include <stdio.h>

#include "Utility/utils.h"

int main() {

    // Initializing global variables
    DATE_COUNT = 0;
    PUBLISHER_COUNT = 0;

    DATES = readDatesFromFile("dates.txt");
    PUBLISHERS = readPublishersFromFile("publishers.txt");
    // ----------

    for(int i = 0; i < PUBLISHER_COUNT; i++) {
        printf("%s %s ", PUBLISHERS[i].name, PUBLISHERS[i].address);
        printf("%i-%i-%i\n",
               PUBLISHERS[i].foundationDate.year,
               PUBLISHERS[i].foundationDate.month,
               PUBLISHERS[i].foundationDate.day);
    }

    Publisher* p1 = getPublisherByAddress("6402_Nepezzano_TE_Via_Scuderlando_62");

    printf("----------\n%s", p1->name);

    printf("\n%s", checkExistenceByAddress("4173_Nagyrabe_Tompa_7") ? "TRUE" : "FALSE");

    Date date1 = DATES[24];
    Date date2 = DATES[70];

    printf("\n%i", publisherCountBetweenDates(date1, date2));


    return 0;
}