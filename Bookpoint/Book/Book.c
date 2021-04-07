#include <stdlib.h>
#include <stdio.h>

#include "../Utility/utils.h"

/// This function creates a BOOK and return it using the given parameters
Book *createBook(char *ISBN,
                 char *title,
                 float price,
                 int numberOfPages,
                 Publisher publisher,
                 Date publishDate,
                 Person author,
                 enum Cover cover,
                 bool ebook) {

    /// Allocate a BOOK in the memory
    Book *book = (Book *) malloc(sizeof(Book));

    /// If the memory allocation has failed
    if (!book) {
        printf("Failed to allocate memory for Book");
        return NULL;
    }

    /// If the memory allocation succeeded
    strcpy(book->ISBN, ISBN);
    strcpy(book->title, title);
    book->price = price;
    book->numberOfPages = numberOfPages;
    book->publisher = publisher;
    book->publishDate = publishDate;
    book->author = author;
    book->cover = cover;
    book->ebook = ebook;

    /// Increase the BOOK counter
    BOOK_COUNT++;

    return book;
}

/// This function reads multiple BOOKS from a given file
Book *readBooksFromFile(char *fileName) {

    /// Open the file with the given file name
    FILE *fin = fopen(fileName, "rt");

    /// If the memory allocation has failed
    if (!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    /// If the memory allocation succeeded

    /// Get how many BOOKS are there
    int n;
    fscanf(fin, "%i", &n);

    /// Allocate n BOOKS in memory
    Book *books = (Book *) calloc(n, sizeof(Book));

    /// If the memory allocation has failed
    if (!books) {
        printf("Failed to allocate temporary vector for books.");

        /// Close the file, because it was opened earlier
        fclose(fin);

        return NULL;
    }

    /// Temporary variables
    char title[31], ISBN[14];

    int numberOfPages;

    float price;

    bool ebook;

    Person author;
    char authorID[7];

    Date publishDate;
    int year, month, day;

    enum Cover cover;

    Publisher publisher;
    char publisherName[25];

    /// The core of this loop will get the data from the given file
    /// and initialises the i-th BOOK in the array.
    for (int i = 0; i < n; i++) {
        fscanf(fin, "%s", authorID);
        author = *getPersonByID(authorID);

        fscanf(fin, "%s", ISBN);
        fscanf(fin, "%s", title);

        fscanf(fin, "%i", &year);
        fscanf(fin, "%i", &month);
        fscanf(fin, "%i", &day);
        publishDate = *createDate(year, month, day);

        fscanf(fin, "%s", publisherName);
        publisher = *getPublisherByName(publisherName);

        fscanf(fin, "%i", &cover);
        fscanf(fin, "%i", &ebook);
        fscanf(fin, "%f", &price);

        numberOfPages = rand() % 1001;

        /// Create a new BOOK using the temporary variables
        books[i] = *createBook(ISBN, title, price, numberOfPages, publisher, publishDate, author, cover, ebook);
    }

    /// Close the previously opened file
    fclose(fin);

    return books;
}

/// This function returns whether a BOOK is coeval or not
bool isCoeval(Book* book){
    return book->author.birthDate.year >= 2000 &&
           book->author.birthDate.month >= 1 &&
           book->author.birthDate.day >= 1;
}

/// This function prints a given BOOK to the standard output
void printBook(Book *book) {
    printf("ISBN: %s\n", book->ISBN);
    printf("\tTitle: %s\n", book->title);
    printf("\tAuthor: %s %s\n", book->author.firstName, book->author.lastName);
    printf("\tNumber of pages: %i\n", book->numberOfPages);
    printf("\tPublisher: %s\n", book->publisher.name);
    printf("\tPublish date: %i %i %i\n",
           book->publishDate.year,
           book->publishDate.month,
           book->publishDate.day);

    printf("\tCover: %i (", book->cover);
    switch (book->cover) {
        case SOFTCOVER: printf("SOFTCOVER"); break;
        case HARDCOVER_IMAGEWRAP: printf("HARDCOVER \\w IMAGEWRAP"); break;
        case HARDCOVER_DUSTJACKET: printf("HARDCOVER \\w DUSTJACKET"); break;
        default: printf("UNKNOWN");
    }
    printf(")\n");
    printf("\tElectrically available: %s\n", (book->ebook ? "Yes" : "No"));
    printf("\tPrice: %.2f\n\n", book->price);
}

/// This function destroys a given BOOK (frees it from the memory)
void destroyBook(Book *book) {
    free(book);
    book = NULL;
}