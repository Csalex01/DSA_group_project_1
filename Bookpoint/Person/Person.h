#ifndef BOOKPOINT_PERSON_H
#define BOOKPOINT_PERSON_H

#include "../enums.h"
#include "../Date/Date.h"

typedef struct {
    char* ID;
    char* firstName;
    char* middleName; // Not required
    char* lastName;

    Date birthDate;

    enum Nationality nationality;

} Person;

Person* createPerson(char* ID, char* firstName, char* middleName, char* lastName, enum Nationality nationality, Date birthDate);

void destroyPerson(Person* person);

#endif //BOOKPOINT_PERSON_H