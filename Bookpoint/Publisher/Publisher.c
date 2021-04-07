#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Publisher.h"
#include "../Utility/utils.h"

/// This function creates a PUBLISHER and return it using the given parameters
Publisher *createPublisher(Date foundationDate, char *name, char *address) {

    /// Allocate a PUBLISHER in the memory
    Publisher *publisher = (Publisher *) malloc(sizeof(Publisher));

    /// If the memory allocation has failed
    if (!publisher) {
        printf("Failed to allocate memory for Publisher");
        return NULL;
    }

    /// If the memory allocation succeeded
    publisher->foundationDate = foundationDate;
    strcpy(publisher->name, name);
    strcpy(publisher->address, address);

    /// Increase the PUBLISHER counter
    PUBLISHER_COUNT++;

    return publisher;
}

/// This function reads multiple PUBLISHERS from a given file
Publisher *readPublishersFromFile(char *fileName) {

    /// Open the file with the given file name
    FILE *fin = fopen(fileName, "rt");

    /// If the memory allocation has failed
    if (!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    /// If the memory allocation succeeded

    /// Get how many PUBLISHERS are there
    int n;
    fscanf(fin, "%i", &n);

    /// Allocate n PUBLISHERS in memory
    Publisher *publishers = (Publisher *) calloc(n, sizeof(Publisher));

    /// If the memory allocation has failed
    if (!publishers) {
        printf("Failed to allocate temporary vector for publishers!");

        /// Close the file, because it was opened earlier
        fclose(fin);

        return NULL;
    }

    /// Temporary variables
    char name[25], address[75];
    Date date;

    /// The core of this loop will get the data from the given file
    /// and initialises the i-th PUBLISHER in the array.
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", name);
        fscanf(fin, "%s", address);
        date = DATES[rand() % DATE_COUNT];

        /// Create a new PUBLISHER using the temporary variables
        publishers[i] = *createPublisher(date, name, address);
    }

    /// Close the previously opened file
    fclose(fin);

    return publishers;
}

/// This function returns a PUBLISHER with a given name
Publisher *getPublisherByName(char *name) {
    if (PUBLISHERS == NULL)
        return NULL;

    for (int i = 0; i < PUBLISHER_COUNT; i++)
        if (!strcmp(name, PUBLISHERS[i].name))
            return &PUBLISHERS[i];

    return NULL;
}

/// This function returns a PUBLISHER with a given address
Publisher *getPublisherByAddress(char *address) {
    if (PUBLISHERS == NULL)
        return NULL;

    for (int i = 0; i < PUBLISHER_COUNT; i++)
        if (!strcmp(address, PUBLISHERS[i].address))
            return &PUBLISHERS[i];

    return NULL;
}

/// This function returns whether a PUBLISHER exists on a given address
bool checkExistenceByAddress(char *address) {
    for (int i = 0; i < PUBLISHER_COUNT; i++)
        if (!strcmp(address, PUBLISHERS[i].address))
            return true;

    return false;
}

/// This function returns how many PUBLISHERS were founded between two dates
int publisherCountBetweenDates(Date date1, Date date2) {
    int count = 0;

    for (int i = 0; i < PUBLISHER_COUNT; i++) {
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

    return count;
}

/// This function destroys a given PUBLISHER (frees it from the memory)
void destroyPublisher(Publisher *publisher) {
    free(publisher);
    publisher = NULL;
}