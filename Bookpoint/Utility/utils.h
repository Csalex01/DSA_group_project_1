#ifndef BOOKPOINT_UTILS_H
#define BOOKPOINT_UTILS_H

#include <string.h>
#include <stdbool.h>

#include "../Date/Date.h"
#include "../Person/Person.h"
#include "../Publisher/Publisher.h"
#include "../enums.h"

#include "../Book/Book.h"


// GLOBAL VARIABLES

int DATE_COUNT;
int PUBLISHER_COUNT;

Date* DATES;
Publisher* PUBLISHERS;

// ----------

void fixDate(char* fileName);

#endif //BOOKPOINT_UTILS_H
