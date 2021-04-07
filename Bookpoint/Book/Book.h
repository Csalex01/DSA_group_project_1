#ifndef BOOKPOINT_BOOK_H
#define BOOKPOINT_BOOK_H

#include <stdbool.h>

#include "../Person/Person.h"
#include "../Date/Date.h"
#include "../Publisher/Publisher.h"

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

Book* createBook(char* ISBN, char* title, float price, int numberOfPages, Publisher publisher, Date publishDate, Person author, enum Cover cover, bool ebook);
Book* readBooksFromFile(char* fileName);

void printBook(Book* book);
void destroyBook(Book* book);

#endif //BOOKPOINT_BOOK_H