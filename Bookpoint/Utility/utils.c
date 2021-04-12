#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/// This function is redundant, but it was used to convert dates to the right format.
/// (it was only called once)
void fixDate(char *fileName) {
    /// Open required files
    FILE *fin = fopen(fileName, "rt");
    FILE *fout = fopen("dates.txt", "wt");

    /// If could not open file
    if (!fin && !fout) {
        printf("Failed to open file \"%s\"", fileName);
        return;
    }

    /// Temporary string
    char line[11];

    /// There are 100 dates, loop through all of them
    for (int i = 0; i < 100; i++) {
        /// Read the line
        fscanf(fin, "%s", line);

        /// Remove whitespaces and fix numbers beginning with 0
        for (int j = 0; j < 10; j++) {
            if (line[j] == '-')
                line[j] = ' ';

            if (line[j] == ' ' && line[j + 1] == '0')
                strcpy(line + j + 1, line + j + 2);
        }

        /// Write to output file
        fprintf(fout, "%s\n", line);
    }

    /// Close files
    fclose(fin);
    fclose(fout);
}

void freeVariables() {
    free(DATES);
    free(PUBLISHERS);
    free(AUTHORS);
    free(BOOKS);

    DATES = NULL;
    PUBLISHERS = NULL;
    AUTHORS = NULL;
    BOOKS = NULL;
}