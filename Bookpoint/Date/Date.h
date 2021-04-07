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

void destroyDate(Date* date);
void sortYearsByAscending(int n);
void sortYearsByDescending(int n);;

void printDates(int n);

#endif //BOOKPOINT_DATE_H
