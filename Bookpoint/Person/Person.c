#include <stdio.h>
#include <stdlib.h>

#include "Person.h"
#include "../Utility/utils.h"

/// This function creates a PERSON and return it using the given parameters
Person *createPerson(char *ID,
                     char *firstName,
                     char *lastName,
                     enum Nationality nationality,
                     Date birthDate) {

    /// Allocate a PERSON in the memory
    Person *person = (Person *) malloc(sizeof(Person));

    /// If the memory allocation has failed
    if (!person) {
        printf("Failed to allocate memory for Person");
        return NULL;
    }

    /// If the memory allocation succeeded
    strcpy(person->ID, ID);
    strcpy(person->firstName, firstName);
    strcpy(person->lastName, lastName);
    person->nationality = nationality;
    person->birthDate = birthDate;

    return person;
}

/// This function reads multiple PERSON from a given file
Person *readPeopleFromFile(char *fileName) {

    /// Open the file with the given file name
    FILE *fin = fopen(fileName, "rt");

    /// If the memory allocation has failed
    if (!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    /// If the memory allocation succeeded

    /// Get how many PERSONS are there
    int n;
    fscanf(fin, "%i", &n);

    /// Assign n to AUTHOR_COUNT (it won't change!)
    AUTHOR_COUNT = n;

    /// Allocate n PERSON in memory
    Person *people = (Person *) calloc(n, sizeof(Person));

    /// If the memory allocation has failed
    if (!people) {
        printf("Failed to allocate temporary vector for authors!");

        /// Close the file, because it was opened earlier
        fclose(fin);

        return NULL;
    }

    /// Temporary variables
    char ID[7];
    char firstName[26];
    char lastName[26];

    int year, month, day;
    Date birthDate;

    enum Nationality nationality;

    /// The core of this loop will get the data from the given file
    /// and initialises the i-th PERSON in the array.
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", ID);
        fscanf(fin, "%s", firstName);
        fscanf(fin, "%s", lastName);

        fscanf(fin, "%i", &year);
        fscanf(fin, "%i", &month);
        fscanf(fin, "%i", &day);

        fscanf(fin, "%i", &nationality);

        birthDate = *createDate(year, month, day);

        /// Create a new PERSON using the temporary variables
        people[i] = *createPerson(ID, firstName, lastName, nationality, birthDate);
    }

    /// Close the previously opened file
    fclose(fin);

    return people;
}

/// This method returns a PERSON with a given id
Person *getPersonByID(char *ID) {
    for (int i = 0; i < AUTHOR_COUNT; i++) {
        if (!strcmp(AUTHORS[i].ID, ID))
            return &AUTHORS[i];
    }

    return NULL;
}

/// This function prints out all PERSON with a given nationality
void printPersonByNationality(enum Nationality nationality) {
    for (int i = 0; i < AUTHOR_COUNT; i++)
        if (nationality == AUTHORS[i].nationality)
            printPerson(&AUTHORS[i]);
}

/// This function prints out all PERSON with a given birth date
void printPersonByBirthDate(Date *date) {
    for (int i = 0; i < AUTHOR_COUNT; i++) {
        if ((AUTHORS[i].birthDate.year == date->year) &&
            (AUTHORS[i].birthDate.month == date->month) &&
            (AUTHORS[i].birthDate.day == date->day))

            printPerson(&AUTHORS[i]);
    }
}

/// This function prints out all PERSON whose age is bigger, or equal to 18
void printAdults() {

    /// Gets the current time
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    for (int i = 0; i < AUTHOR_COUNT; i++) {
        /// If the current year minus the birth year is bigger or equal to 18
        if(local->tm_year - AUTHORS[i].birthDate.year + 1900 >= 18)
            /// Then they are an adult
            printPerson(&AUTHORS[i]);
    }
}

/// This function prints a given PERSON to the standard output
void printPerson(Person *person) {
    printf("ID: \t%s\n", person->ID);
    printf("\tName: \t\t%s %s\n", person->firstName, person->lastName);
    printf("\tBirth date: \t%i-%i-%i\n",
           person->birthDate.year,
           person->birthDate.month,
           person->birthDate.day);
    printf("\tNationality: \t%i (", person->nationality);

    switch (person->nationality) {
        case HUNGARIAN:
            printf("HUNGARIAN");
            break;
        case ROMANIAN:
            printf("ROMANIAN");
            break;
        case GERMAN:
            printf("GERMAN");
            break;
        case FRENCH:
            printf("FRENCH");
            break;
        case AMERICAN:
            printf("AMERICAN");
            break;
        case BRITISH:
            printf("BRITISH");
            break;
        case DANISH:
            printf("DANISH");
            break;
        case ICELANDIC:
            printf("ICELANDIC");
            break;
        case IRISH:
            printf("IRISH");
            break;
        case SWEDISH:
            printf("SWEDISH");
            break;
        default:
            printf("UNKNOWN");
    }

    printf(")\n\n");
}

/// This function destroys a given PERSON (frees it from the memory)
void killPerson(Person *person) {
    free(person);
    person = NULL;
}