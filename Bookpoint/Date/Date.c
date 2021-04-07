#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Date.h"
#include "../Utility/utils.h"

Date* createDate(int year, int month, int day) {
    Date* date = (Date*)malloc(sizeof(Date));

    if(!date) {
        printf("Failed to allocate memory for Date");
        return NULL;
    }

    date->year = year;
    date->month = month;
    date->day = day;

    DATE_COUNT++;
    return date;
}

Date* readDatesFromFile(char* fileName) {
    FILE* fin = fopen(fileName, "rt");

    if(!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    int n;
    fscanf(fin, "%i", &n);

    Date* dates = (Date*)calloc(n, sizeof(Date));

    if(!dates) {
        printf("Faile to allocate temporary vector for dates");
        fclose(fin);
        return NULL;
    }

    int year, month, day;
    for(int i = 0; i < n; i++) {
        
        fscanf(fin, "%i", &year);
        fscanf(fin, "%i", &month);
        fscanf(fin, "%i", &day);

        dates[i] = *createDate(year, month, day);
    }

    fclose(fin);

    return dates;
}

void destroyDate(Date* date) {
    free(date);
    date = NULL;
}

void sortYearsByAscending(int n){
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(DATES[j].year > DATES[j + 1].year) {
                Date tmp = DATES[j];
                DATES[j] = DATES[j + 1];
                DATES[j + 1]= tmp;
            }
        }
    }
}

void sortYearsByDescending(int n){
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(DATES[j].year < DATES[j + 1].year) {
                Date tmp = DATES[j];
                DATES[j] = DATES[j + 1];
                DATES[j + 1]= tmp;
            }
        }
    }
}

void printDates(int n) {
    for(int i = 0; i < n; i++)
        printf("%i %i %i\n", DATES[i].year, DATES[i].month, DATES[i].day);
    printf("\n");
}

bool isCoeval(Date* date){
    return date->year >= 2000 && date->month >= 1 && date->day >= 1;
}