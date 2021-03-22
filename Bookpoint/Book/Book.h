#ifndef BOOKPOINT_BOOK_H
#define BOOKPOINT_BOOK_H

#include <stdbool.h>
#include "../Person/Person.h"
#include "../Date/Date.h"
#include "../Publisher/Publisher.h"
#include "../enums.h"

typedef struct {
    int numberOfPages;
    float price;
    char* title;
    char* ISBN;

    bool ebook;

    Person author;
    Date publishDate;
    enum Cover cover;
    Publisher publisher;
} Book;

Book* createBook(char* ISBN, char* title, float price, int numberOfPages, Publisher publisher, Date publishDate, Person author, enum Cover cover, bool ebook);

void destroyBook(Book* book);

#endif //BOOKPOINT_BOOK_H