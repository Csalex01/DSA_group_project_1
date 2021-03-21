#ifndef BOOKPOINT_DATE_H
#define BOOKPOINT_DATE_H

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date* createDate(int year, int month, int day);

void destroyDate(Date* date);

#endif //BOOKPOINT_DATE_H
