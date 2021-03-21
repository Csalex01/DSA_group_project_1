# BOOKPOINT
## Team Members
- Csata László-Levente
- Csillag Alex
- Miklós Nándor

## Project Structure (might change)
### ENUMS
```c
enum Cover {
	// https://www.blurb.com/blog/3-types-of-book-covers/
	SOFTCOVER,
	HARDCOVER_IMAGEWRAP,
	HARDCOVER_DUSTJACKET
};

enum Nationality {
	HUNGARIAN,
	ROMANIAN,
	GERMAN,
	FRENCH,
	AMERICAN,
	BRITISH,
	DANISH,
	ICELANDIC,
	IRISH,
	SWEDISH
};
```
### STRUCTURES
```c
typedef struct {
	int year;
	int month;
	int day;
} Date;

typedef struct {
	char* ID;
	char* firstName;
	char* middleName; // not required
	char* lastName;
	Nationality nationality;
	Date birthDate;
} Person;

typedef struct {
	Date foundationDate;
	char* name;
	char* address;
} Publisher;

typedef struct {
	int pages;
	float price;
	char* title;
	char* ISBN;
	Person author;
	Date publishDate;
	Cover cover;
	Publisher publisher;
} Book;
```

### CREATE() FUNCTIONS
```c
Date* createDate(int year, int month, int day) {
	Date* date = (Date*)malloc(sizeof(Date));
	
	if(!date) {
		printf("Failed to allocate memory (Date)!");
		return NULL;
	}
	
	date->year = year;
	date->month = month;
	date->day = day;
	
	return date;
}

Person* createPerson(char* ID, char* firstName, char* middleName, char* lastName, Nationality nationality, Date birthDate) {
	Person* person = (Person*)malloc(sizeof(Person));
	
	if(!person) {
		printf("Failed to allocate memory (Person)!");
		return NULL;
	}
	
	person->ID = ID;
	person->firstName = firstName;
	person->middleName = middleName;
	person->lastName = lastName;
	person->nationality = nationality;
	person->birthDate = birthDate;
	
	return perosn;
}

Publisher* createPublisher(Date foundationDate, char* name, char* address) {
	Publisher* publisher = (Publisher*)malloc(sizeof(Publisher));
	
	if(!date) {
		printf("Failed to allocate memory (Publisher)!");
		return NULL;
	}
	
	publisher->foundationDate = foundationDate;
	publisher->name = name;
	publisher->address = address;
	
	return publisher;
}

Book* createBook(char* ISBN, char* title, float price, int pages, Publisher publisher, Date publishDate, Person author, Cover cover) {
	Book* book = (Book*)malloc(sizeof(Book));
	
	if(!date) {
		printf("Failed to allocate memory (Book)!");
		return NULL;
	}
	
	book->ISBN = ISBN;
	book->title = title;
	book->price = price;
	book->pages = pages;
	book->publisher = publisher;
	book->publishDate = publishDate;
	book->author = author;
	book->cover = cover;
	
	return book;
}
```
