#include <stdlib.h>
#include <stdio.h>

#include "Book.h"

Book* createBook(char* ISBN, char* title, float price, int numberOfPages, Publisher publisher, Date publishDate, Person author, enum Cover cover, bool ebook){
    Book* book = (Book*)malloc(sizeof(Book));

    if(!book) {
        printf("Failed to allocate memory for Book");
        return NULL;
    }

    book->ISBN = ISBN;
    book->title = title;
    book->price = price;
    book->numberOfPages = numberOfPages;
    book->publisher = publisher;
    book->publishDate = publishDate;
    book->author = author;
    book->cover = cover;
    book->ebook = ebook;

    return book;
}

void destroyBook(Book* book) {
    free(book);
    book = NULL;
}