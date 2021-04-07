#include <stdlib.h>
#include <stdio.h>

#include "../Utility/utils.h"
#include "Book.h"

Book* createBook(char* ISBN, char* title, float price, int numberOfPages, Publisher publisher, Date publishDate, Person author, enum Cover cover, bool ebook){
    Book* book = (Book*)malloc(sizeof(Book));

    if(!book) {
        printf("Failed to allocate memory for Book");
        return NULL;
    }

    strcpy(book->ISBN, ISBN);
    strcpy(book->title, title);
    book->price = price;
    book->numberOfPages = numberOfPages;
    book->publisher = publisher;
    book->publishDate = publishDate;
    book->author = author;
    book->cover = cover;
    book->ebook = ebook;

    BOOK_COUNT++;

    return book;
}

Book* readBooksFromFile(char* fileName) {
    FILE* fin = fopen(fileName, "rt");

    if(!fin) {
        printf("Could not open file %s", fileName);
        return NULL;
    }

    int n;
    fscanf(fin, "%i", &n);

    Book* books = (Book*)calloc(n, sizeof(Book));

    if(!books) {
        printf("Failed to allocate temporary vector for books.");
        fclose(fin);
        return NULL;
    }

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

    for(int i = 0; i < n; i++) {
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

        books[i] = *createBook(ISBN, title, price, numberOfPages, publisher, publishDate, author, cover, ebook);
    }

    return books;
}

void printBook(Book* book) {
    printf("%s\n", book->ISBN);
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
        case 0: printf("SOFTCOVER"); break;
        case 1: printf("HARDCOVER \\w IMAGEWRAP");
        case 2: printf("HARDCOVER \\w DUSTJACKET");
        default: printf("UNKNOWN");
    }
    printf(")\n");
    printf("\tElectrically available: %s\n", (book->ebook ? "Yes" : "No"));
    printf("\tPrice: %.2f\n\n", book->price);
}

void destroyBook(Book* book) {
    free(book);
    book = NULL;
}