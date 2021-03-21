#ifndef BOOKPOINT_PUBLISHER_H
#define BOOKPOINT_PUBLISHER_H

#include "../Date/Date.h"

typedef struct {
    char* name;
    char* address;

    Date foundationDate;
} Publisher;

Publisher* createPublisher(Date foundationDate, char* name, char* address);

void destroyPublisher(Publisher* publisher);

#endif //BOOKPOINT_PUBLISHER_H
