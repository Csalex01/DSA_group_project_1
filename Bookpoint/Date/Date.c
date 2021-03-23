#include <stdio.h>
#include <stdlib.h>

#include "Date.h"

Date* createDate(int year, int month, int day) {
    Date* date = (Date*)malloc(sizeof(Date));

    if(!date) {
        printf("Failed to allocate memory for Date");
        return NULL;
    }

    date->year = year;
    date->month = month;
    date->day = day;

    return date;
}

void destroyDate(Date* date) {
    free(date);
    date = NULL;
}