#ifndef BOOKPOINT_DATE_H
#define BOOKPOINT_DATE_H

#include "stdbool.h"

/// Structure definition of Date
typedef struct {
    int year;
    int month;
    int day;
} Date;

/// Functions associated with this data structure
Date* createDate(int year, int month, int day);
Date* readDatesFromFile(char* fileName);

bool equalDates(Date* date1, Date* date2);


void sortYearsByAscending();
void sortYearsByDescending();

void printDates();

void destroyDate(Date* date);

#endif //BOOKPOINT_DATE_H