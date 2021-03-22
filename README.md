# BOOKPOINT
## Team Members
- Csata László-Levente
- Csillag Alex
- Miklós Nándor

## Project Structure (might change)
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

## Operations by struct
### Date (4 functions + 2)
- Sort by year (ascending)
- Sort by year (descending)
- Matching date count
- Is coeval? (> 200.01.01)
- ...

## Person (6 functions + 2)
- Get people by nationality
- Get person by ID
- Sort by ID
- Get people by birth date
- Get people by birth date between two dates
- Get adults (age >= 18)
- ...

## Publisher (5 functions + 2)
- Sort by foundation year
- Get publisher by name
- Get publisher by address
- Does a publisher exist based on a given address
- Get publishers by foundation date between two dates

## Book (16 functions + 2)
- Get books based on page numbers
- Get books based on price
- Get books between two price values
- Get book based on title
- Get book based on author
- Get books based on publisher
- Get books based on publish date
- Get books by publish date between two dates
- Get books based on cover type
- Sort books by price (ascending)
- Sort books by price (descending)
- Sort books by page number (ascending)
- Sort books by page number (descending)
- Sort books by publish date (ascending)
- Sort books by publish date (descending)
- Is it an ebook?
