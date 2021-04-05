#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Publisher.h"
#include "../Utility/utils.h"

Publisher *createPublisher(Date foundationDate, char *name, char *address) {
    Publisher *publisher = (Publisher *) malloc(sizeof(Publisher));

    if (!publisher) {
        printf("Failed to allocate memory for Publisher");
        return NULL;
    }

    publisher->foundationDate = foundationDate;

    strcpy(publisher->name, name);
    strcpy(publisher->address, address);

    PUBLISHER_COUNT++;
    return publisher;
}

Publisher *readPublishersFromFile(char *fileName) {
    FILE *fin = fopen(fileName, "rt");

    if (!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    int n;
    fscanf(fin, "%i", &n);

    Publisher *publishers = (Publisher *) calloc(n, sizeof(Publisher));

    if (!publishers) {
        printf("Failed to allocate temporary vector for publishers!");
        fclose(fin);
        return NULL;
    }

    char name[25], address[75];
    Date date;

    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", name);
        fscanf(fin, "%s", address);
        date = DATES[rand() % DATE_COUNT];

        publishers[i] = *createPublisher(date, name, address);
    }

    return publishers;
}

Publisher *getPublisherByName(char *name) {
    if (PUBLISHERS == NULL)
        return NULL;

    for (int i = 0; i < PUBLISHER_COUNT; i++)
        if (!strcmp(name, PUBLISHERS[i].name))
            return &PUBLISHERS[i];

    return NULL;
}

Publisher *getPublisherByAddress(char *address) {
    if (PUBLISHERS == NULL)
        return NULL;

    for (int i = 0; i < PUBLISHER_COUNT; i++)
        if (!strcmp(address, PUBLISHERS[i].address))
            return &PUBLISHERS[i];

    return NULL;
}

bool checkExistenceByAddress(char *address) {
    for (int i = 0; i < PUBLISHER_COUNT; i++)
        if (!strcmp(address, PUBLISHERS[i].address))
            return true;

    return false;
}

int publisherCountBetweenDates(Date date1, Date date2) {
    int count = 0;

    for (int i = 0; i < PUBLISHER_COUNT; i++)
        if ((
                    (date1.year <= PUBLISHERS[i].foundationDate.year) &&
                    (date1.month <= PUBLISHERS[i].foundationDate.month) &&
                    (date1.day <= PUBLISHERS[i].foundationDate.day)
            ) && (
                    (PUBLISHERS[i].foundationDate.year <= date2.year) &&
                    (PUBLISHERS[i].foundationDate.month <= date2.month) &&
                    (PUBLISHERS[i].foundationDate.day <= date2.day)
            )) {
            count++;
        }
}

void destroyPublisher(Publisher *publisher) {
    free(publisher);
    publisher = NULL;
}