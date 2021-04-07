#ifndef BOOKPOINT_BOOK_H
#define BOOKPOINT_BOOK_H

#include <stdbool.h>

#include "../Person/Person.h"
#include "../Date/Date.h"
#include "../Publisher/Publisher.h"

/// Structure definition of Book
typedef struct {
    int numberOfPages;
    float price;
    char title[31];
    char ISBN[14];

    bool ebook;

    Person author;
    Date publishDate;
    enum Cover cover;
    Publisher publisher;
} Book;

/// Functions associated with this data structure
Book* createBook(char* ISBN, char*   title, float price, int numberOfPages, Publisher publisher, Date publishDate, Person author, enum Cover cover, bool ebook);
Book* readBooksFromFile(char* fileName);

Book* getBookBasedOnISBN(char* ISBN);
Book* getBookBasedOnTitle(char* title);

bool isCoeval(Book* book);
bool isEbook(Book* book);

void printBook(Book* book);
void printBooksBasedOnAuthorID(char* authorID);
void printBooksBasedOnPageNumbers(int pageNumber);
void printBooksBasedOnPriceRange(float minPrice, float maxPrice);
void printBooksBasedOnPublishDate(Date* date);
void printBooksBasedOnCoverType(enum Cover cover);

void sortBooksByPriceAscending();
void sortBooksByPriceDescending();

void sortBooksByPageNumberAscending();
void sortBooksByPageNumberDescending();

void sortBooksByPublishYearAscending();
void sortBooksByPublishYearDescending();

void destroyBook(Book* book);

#endif //BOOKPOINT_BOOK_H