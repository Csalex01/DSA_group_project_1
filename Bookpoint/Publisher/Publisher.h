#ifndef BOOKPOINT_PUBLISHER_H
#define BOOKPOINT_PUBLISHER_H

#include "../Date/Date.h"

typedef struct {
    char name[25];
    char address[75];

    Date foundationDate;
} Publisher;

Publisher* createPublisher(Date foundationDate, char* name, char* address);
Publisher* getPublisherByName(Publisher* publishers, int n, char* name);
Publisher* getPublisherByAddress(Publisher* publishers, int n, char* address);

bool checkExistenceByAddress(Publisher* publishers, int n, char* address);

int publisherCountBetweenDates(Publisher* publishers, int n);

void destroyPublisher(Publisher* publisher);
void sortByYear(Publisher* publishers);

#endif //BOOKPOINT_PUBLISHER_H
