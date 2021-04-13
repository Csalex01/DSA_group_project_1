#ifndef BOOKPOINT_PERSON_H
#define BOOKPOINT_PERSON_H

#include "../enums.h"
#include "../Date/Date.h"

/// Structure definition of Person
typedef struct {
    char ID[7];
    char firstName[26];
    char lastName[26];

    Date birthDate;

    enum Nationality nationality;

} Person;

/// Functions associated with this data structure
Person* createPerson(char* ID,
                     char* firstName,
                     char* lastName,
                     enum Nationality nationality,
                     Date birthDate);
Person* readPeopleFromFile(char* fileName);
Person* getPersonByID(char* ID);

void printPersonByNationality(enum Nationality nationality);
void printPersonByBirthDate(Date* date);
void printAdults();
void printPerson(Person* person);

void killPerson(Person* person);

#endif //BOOKPOINT_PERSON_H