#include <stdlib.h>
#include <stdio.h>

#include "Publisher.h"

Publisher* createPublisher(Date foundationDate, char* name, char* address) {
    Publisher* publisher = (Publisher*)malloc(sizeof(Publisher));

    if(!publisher) {
        printf("Failed to allocate memory for Publisher");
        return NULL;
    }

    publisher->foundationDate = foundationDate;
    publisher->name = name;
    publisher->address = address;

    return publisher;
}

void destroyPublisher(Publisher* publisher) {
    free(publisher);
    publisher = NULL;
}