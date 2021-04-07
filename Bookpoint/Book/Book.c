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

    /// Set the seed for pseudo-random number generation
    srand(time(NULL));

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

/// This function returns a BOOK with the given ISBN
Book *getBookBasedOnISBN(char *ISBN) {
    for (int i = 0; i < BOOK_COUNT; i++)
        if (!strcmp(BOOKS[i].ISBN, ISBN))
            return &BOOKS[i];

    return NULL;
}

/// This function returns a BOOK with the given title
Book *getBookBasedOnTitle(char *title) {
    for (int i = 0; i < BOOK_COUNT; i++)
        if (!strcmp(BOOKS[i].title, title))
            return &BOOKS[i];

    return NULL;
}

/// This function returns whether a BOOK is coeval or not
bool isCoeval(Book *book) {
    return book->publishDate.year >= 2000 &&
           book->publishDate.month >= 1 &&
           book->publishDate.day >= 1;
}


/// This function returns whether a BOOK is electrically available or not
// This function might be redundant because we have direct access to the attribute
bool isEbook(Book *book) {
    return book->ebook;
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
        case SOFTCOVER:
            printf("SOFTCOVER");
            break;
        case HARDCOVER_IMAGEWRAP:
            printf("HARDCOVER \\w IMAGEWRAP");
            break;
        case HARDCOVER_DUSTJACKET:
            printf("HARDCOVER \\w DUSTJACKET");
            break;
        default:
            printf("UNKNOWN");
    }
    printf(")\n");
    printf("\tElectrically available: %s\n", (book->ebook ? "Yes" : "No"));
    printf("\tPrice: EUR%.2f\n", book->price);

    printf("\tCoeval? ");
    if (isCoeval(book))
        printf("Yes");
    else
        printf("No");
    printf("\n\n");
}

/// This function prints out all the BOOKS by the given author
void printBooksBasedOnAuthorID(char *authorID) {
    printf("\nBooks with the author %s: \n", authorID);

    for (int i = 0; i < BOOK_COUNT; i++)
        if (!strcmp(BOOKS[i].author.ID, authorID))
            printBook(&BOOKS[i]);
}

void printBooksBasedOnPageNumbers(int pageNumber) {
    printf("\nBooks with the page number of %i: \n", pageNumber);

    for (int i = 0; i < BOOK_COUNT; i++)
        if (BOOKS[i].numberOfPages == pageNumber)
            printBook(&BOOKS[i]);
}

/// This function prints out all the BOOKS between two prices
void printBooksBasedOnPriceRange(float minPrice, float maxPrice) {
    printf("\nBooks in the price range [EUR%.2f, EUR%.2f]: \n", minPrice, maxPrice);

    for (int i = 0; i < BOOK_COUNT; i++)
        if (minPrice <= BOOKS[i].price && BOOKS[i].price <= maxPrice)
            printBook(&BOOKS[i]);
}

/// This function prints out all the BOOKS with a given publish date
void printBooksBasedOnPublishDate(Date *date) {
    printf("\nBooks with the publish date of %i %i %i: \n", date->year, date->month, date->day);

    for (int i = 0; i < BOOK_COUNT; i++)
        if (equalDates(&BOOKS[i].publishDate, date))
            printBook(&BOOKS[i]);
}

/// This function prints out all the BOOKS with a given cover type
void printBooksBasedOnCoverType(enum Cover cover) {
    printf("Books with the cover type of ");
    switch (cover) {
        case SOFTCOVER:
            printf("SOFTCOVER");
            break;
        case HARDCOVER_IMAGEWRAP:
            printf("HARDCOVER \\w IMAGEWRAP");
            break;
        case HARDCOVER_DUSTJACKET:
            printf("HARDCOVER \\w DUSTJACKET");
            break;
        default:
            printf("UNKNOWN");
    }

    printf(": \n");

    for (int i = 0; i < BOOK_COUNT; i++)
        if (BOOKS[i].cover == cover)
            printBook(&BOOKS[i]);
}

/// This function sorts the BOOKS vector by price in ascending order
void sortBooksByPriceAscending() {
    for (int i = 0; i < BOOK_COUNT; i++) {
        for (int j = 0; j < BOOK_COUNT - i - 1; j++) {
            if (BOOKS[j].price > BOOKS[j + 1].price) {
                Book tmp = BOOKS[j];
                BOOKS[j] = BOOKS[j + 1];
                BOOKS[j + 1] = tmp;
            }
        }
    }
}

/// This function sorts the BOOKS vector by price in descending order
void sortBooksByPriceDescending() {
    for (int i = 0; i < BOOK_COUNT; i++) {
        for (int j = 0; j < BOOK_COUNT - i - 1; j++) {
            if (BOOKS[j].price < BOOKS[j + 1].price) {
                Book tmp = BOOKS[j];
                BOOKS[j] = BOOKS[j + 1];
                BOOKS[j + 1] = tmp;
            }
        }
    }
}

/// This function sorts the BOOKS vector by page numbers in ascending order
void sortBooksByPageNumberAscending() {
    for (int i = 0; i < BOOK_COUNT; i++) {
        for (int j = 0; j < BOOK_COUNT - i - 1; j++) {
            if (BOOKS[j].numberOfPages > BOOKS[j + 1].numberOfPages) {
                Book tmp = BOOKS[j];
                BOOKS[j] = BOOKS[j + 1];
                BOOKS[j + 1] = tmp;
            }
        }
    }
}

/// This function sorts the BOOKS vector by page numbers in descending order
void sortBooksByPageNumberDescending() {
    for (int i = 0; i < BOOK_COUNT; i++) {
        for (int j = 0; j < BOOK_COUNT - i - 1; j++) {
            if (BOOKS[j].numberOfPages < BOOKS[j + 1].numberOfPages) {
                Book tmp = BOOKS[j];
                BOOKS[j] = BOOKS[j + 1];
                BOOKS[j + 1] = tmp;
            }
        }
    }
}

/// This function sorts the BOOKS vector by publish year in ascending order
void sortBooksByPublishYearAscending() {
    for(int i = 0; i < BOOK_COUNT; i++) {
        for(int j = 0; j < BOOK_COUNT - i - 1; j++) {
            if(BOOKS[j].publishDate.year > BOOKS[j + 1].publishDate.year) {
                Book tmp = BOOKS[j];
                BOOKS[j] = BOOKS[j + 1];
                BOOKS[j + 1] = tmp;
            }
        }
    }
}

/// This function sorts the BOOKS vector by publish year in descending order
void sortBooksByPublishYearDescending() {
    for(int i = 0; i < BOOK_COUNT; i++) {
        for(int j = 0; j < BOOK_COUNT - i - 1; j++) {
            if(BOOKS[j].publishDate.year < BOOKS[j + 1].publishDate.year) {
                Book tmp = BOOKS[j];
                BOOKS[j] = BOOKS[j + 1];
                BOOKS[j + 1] = tmp;
            }
        }
    }
}

/// This function destroys a given BOOK (frees it from the memory)
void destroyBook(Book *book) {
    free(book);
    book = NULL;
}