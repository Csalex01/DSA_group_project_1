#ifndef BOOKPOINT_DATE_H
#define BOOKPOINT_DATE_H

#include "stdbool.h"

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date* createDate(int year, int month, int day);
Date* readDatesFromFile(char* fileName);

void destroyDate(Date* date);
void sortYearsByAscending(int n);
void sortYearsByDescending(int n);
bool isCoeval(Date* date);

void printDates(int n);

#endif //BOOKPOINT_DATE_H
