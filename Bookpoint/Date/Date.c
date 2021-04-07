#include <stdio.h>
#include <stdlib.h>

#include "Date.h"
#include "../Utility/utils.h"

/// This function creates a DATE and return it using the given parameters
Date *createDate(int year, int month, int day) {

    /// Allocate the date in the memory
    Date *date = (Date *) malloc(sizeof(Date));

    ///  If the memory allocation has failed
    if (!date) {
        printf("Failed to allocate memory for Date");
        return NULL;
    }

    /// If the memory allocation was successful
    date->year = year;
    date->month = month;
    date->day = day;

    return date;
}

/// This function reads multiple DATES from a given file
Date *readDatesFromFile(char *fileName) {

    /// Open the file with the given file name
    FILE *fin = fopen(fileName, "rt");

    /// If the memory allocation has failed
    if (!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    /// If the memory allocation succeeded

    /// Get how many DATES are there
    int n;
    fscanf(fin, "%i", &n);

    /// Assign n to DATE_COUNT (it won't change!)
    DATE_COUNT = n;

    /// Allocate n DATES in memory
    Date *dates = (Date *) calloc(n, sizeof(Date));

    /// If the memory allocation has failed
    if (!dates) {
        printf("Failed to allocate temporary vector for dates");

        /// Close the file, because it was opened earlier
        fclose(fin);

        return NULL;
    }

    /// Temporary variables
    int year, month, day;

    /// The core of this loop will get the data from the given file
    /// and initialises the i-th DATE in the array.
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%i", &year);
        fscanf(fin, "%i", &month);
        fscanf(fin, "%i", &day);

        /// Create a new BOOK using the temporary variables
        dates[i] = *createDate(year, month, day);
    }

    /// Close the previously opened file
    fclose(fin);

    return dates;
}

/// This function returns whether two dates are equal or not
bool equalDates(Date *date1, Date *date2) {
    return date1->year == date2->year &&
           date1->month == date2->month &&
           date1->day == date2->day;
}

/// This function destroys a given DATE (frees it from memory)
void destroyDate(Date *date) {
    free(date);
    date = NULL;
}

/// This function sorts the BOOKS global array in ascending order
void sortYearsByAscending() {
    for (int i = 0; i < DATE_COUNT - 1; i++) {
        for (int j = 0; j < DATE_COUNT - i - 1; j++) {
            if (DATES[j].year > DATES[j + 1].year) {
                Date tmp = DATES[j];
                DATES[j] = DATES[j + 1];
                DATES[j + 1] = tmp;
            }
        }
    }
}

/// This function sorts the BOOKS global array in descending order
void sortYearsByDescending() {
    for (int i = 0; i < DATE_COUNT - 1; i++) {
        for (int j = 0; j < DATE_COUNT - i - 1; j++) {
            if (DATES[j].year < DATES[j + 1].year) {
                Date tmp = DATES[j];
                DATES[j] = DATES[j + 1];
                DATES[j + 1] = tmp;
            }
        }
    }
}

/// This function prints all DATES to the standard output
void printDates() {
    for (int i = 0; i < DATE_COUNT; i++)
        printf("%i %i %i\n", DATES[i].year, DATES[i].month, DATES[i].day);
    printf("\n");
}

