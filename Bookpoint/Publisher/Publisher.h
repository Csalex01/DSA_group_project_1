#ifndef BOOKPOINT_PUBLISHER_H
#define BOOKPOINT_PUBLISHER_H

#include "../Date/Date.h"

/// Structure definition of Publisher
typedef struct {
    char name[25];
    char address[75];

    Date foundationDate;
} Publisher;

/// Functions associated with this data structure
Publisher* createPublisher(Date foundationDate, char* name, char* address);
Publisher* readPublishersFromFile(char* fileName);
Publisher* getPublisherByName(char* name);
Publisher* getPublisherByAddress(char* address);

bool checkExistenceByAddress(char* address);

int publisherCountBetweenDates(Date* date1, Date* date2);

void sortPublishersByYear();
void destroyPublisher(Publisher* publisher);
void printPublisher(Publisher* publisher);

#endif //BOOKPOINT_PUBLISHER_H