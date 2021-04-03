#ifndef BOOKPOINT_DATE_H
#define BOOKPOINT_DATE_H

#include "stdbool.h"

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date* createDate(int year, int month, int day);
Date* readFromFile(char* fileName);

void destroyDate(Date* date);
void sortYearsByAscending(Date* date, int n);
void sortYearsByDescending(Date* date, int n);
bool isCoeval(Date* date);

void printDates(Date* dates, int n);

#endif //BOOKPOINT_DATE_H
