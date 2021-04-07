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
<<<<<<< Updated upstream
Publisher* readPublishersFromFile(char* fileName);
Publisher* getPublisherByName(char* name);
Publisher* getPublisherByAddress(char* address);
=======
Publisher* readPublisherFromFile(Publisher* publisher);
Publisher* getPublisherByName(Publisher* publishers, int n, char* name);
Publisher* getPublisherByAddress(Publisher* publishers, int n, char* address);
>>>>>>> Stashed changes

bool checkExistenceByAddress(char* address);

int publisherCountBetweenDates(Date date1, Date date2);

void sortPublishersByYear();
void destroyPublisher(Publisher* publisher);

#endif //BOOKPOINT_PUBLISHER_H
