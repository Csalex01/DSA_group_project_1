#include <stdio.h>
#include <stdlib.h>

#include "Person.h"
#include "../Utility/utils.h"


Person* createPerson(char* ID, char* firstName, char* lastName, enum Nationality nationality, Date birthDate) {
    Person* person = (Person*)malloc(sizeof(Person));

    if(!person) {
        printf("Failed to allocate memory for Person");
        return NULL;
    }

    strcpy(person->ID, ID);
    strcpy(person->firstName, firstName);
    strcpy(person->lastName, lastName);
    person->nationality = nationality;
    person->birthDate = birthDate;

    AUTHOR_COUNT++;

    return person;
}

Person* readPeopleFromFile(char* fileName) {
    FILE* fin = fopen(fileName, "rt");

    if(!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    int n;
    fscanf(fin, "%i", &n);

    Person* people = (Person*)calloc(n, sizeof(Person));

    if(!people) {
        printf("Failed to allocate temporary vector for authors!");
        fclose(fin);
        return NULL;
    }

    char ID[7];
    char firstName[26];
    char lastName[26];

    int year, month, day;
    Date birthDate;

    enum Nationality nationality;

    for(int i = 0; i < n; i++) {
        fscanf(fin, "%s", ID);
        fscanf(fin, "%s", firstName);
        fscanf(fin, "%s", lastName);

        fscanf(fin, "%i", &year);
        fscanf(fin, "%i", &month);
        fscanf(fin, "%i", &day);

        fscanf(fin, "%i", &nationality);

        birthDate = *createDate(year, month, day);

        people[i] = *createPerson(ID, firstName, lastName, nationality, birthDate);
    }

    fclose(fin);
    return people;
}

Person* getPersonByID(char* ID) {
    for(int i = 0; i < AUTHOR_COUNT; i++) {
        if(!strcmp(AUTHORS[i].ID, ID))
            return &AUTHORS[i];
    }
}

void printPerson(Person* person) {
    printf("%s: \n", person->ID);
    printf("\tName: %s %s\n", person->firstName, person->lastName);
    printf("\tBirth date: %i %i %i\n",
           person->birthDate.year,
           person->birthDate.month,
           person->birthDate.day);
    printf("\tNationality: %i (", person->nationality);

    switch (person->nationality) {
        case 0: printf("HUNGARIAN"); break;
        case 1: printf("ROMANIAN"); break;
        case 2: printf("GERMAN"); break;
        case 3: printf("FRENCH"); break;
        case 4: printf("AMERICAN"); break;
        case 5: printf("BRITISH"); break;
        case 6: printf("DANISH"); break;
        case 7: printf("ICELANDIC"); break;
        case 8: printf("IRISH"); break;
        case 9: printf("SWEDISH"); break;
    }

    printf(")\n");
    printf("\n");
}

void destroyPerson(Person* person) {
    free(person);
    person = NULL;
}