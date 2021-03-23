#include <stdio.h>
#include <stdlib.h>

#include "Person.h"

Person* createPerson(char* ID, char* firstName, char* middleName, char* lastName, enum Nationality nationality, Date birthDate) {
    Person* person = (Person*)malloc(sizeof(Person));

    if(!person) {
        printf("Failed to allocate memory for Person");
        return NULL;
    }

    person->ID = ID;
    person->firstName = firstName;
    person->middleName = middleName;
    person->lastName = lastName;
    person->nationality = nationality;
    person->birthDate = birthDate;

    return person;
}

void destroyPerson(Person* person) {
    free(person);
    person = NULL;
}