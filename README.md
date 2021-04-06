# Group Project: BOOKPOINT
## Description
EMPTY

## Team Members
- Csata Levente
- Csillag Alex
- Miklós Nándor

## TODO
- Generate 100 random dates [(link)](https://www.random.org/calendar-dates/?mode=advanced) (DONE)
	- YEAR(int) MONTH(int) DAY(int)

- Generate 30 random people [(link)](https://www.fakenamegenerator.com/advanced.php)
	- ID (random number between 0 and 10000, could be randomly generated)
	- First Name
	- Last Name
	- Birth Date
	- Nationality (based on enum)
	- Only NON-SPECIAL characters (A..Z, a..z)
	- ID(string) FIRST_NAME(string) LAST_NAME(string) YEAR(int) MONTH(int) DAY(int) NATIONALITY(int/enum)
	
- Generate 10 publishers (30, DONE)
	- Name (name of organization, only one word)
	- Address [(link)](https://www.fakenamegenerator.com/advanced.php)
	- Date (from generated dates)
	- NAME(string) ZIP_CODE(int) CITY_NAME(string) STREET_NAME(string) HOUSE_NUMBER(int)
	
- Generate 30 books
	- 1 person could have multiple books
	- Author (from generated people)
	- ISBN code (13 digits, string)
	- Title (max 20 characters)
	- Price (between 10 euro and 300 euro)
	- Number of page (between 10 and 1000)
	- E-book (boolean)
	- Cover (from enum)
	- Publish date
	- Publisher (from generated publishers)
	- AUTHOR_ID(int) ISBN(int) TITLE(string) YEAR(int) MONTH(int) DAY(int) PUBLISHER_NAME(string) COVER(int/enum) EBOOK(bool) PRICE(float)

## Roles
- Csata Levente
	- Publisher generation (DONE)
	- Publisher functions (DONE)
	- Date functions
- Csillag Alex
	- Date generation (DONE)
	- Book generation
	- Menu functions
	- Book functions
- Miklós Nándor
	- People generation
	- Person functions

## Operations by struct
### Date (4 functions + 2)
- Sort by year (ascending)
- Sort by year (descending)
- Matching date count (Will be done later)
- Is coeval? (>= 200.01.01)
- ...

### Person (6 functions + 2)
- Get people by nationality
- Get person by ID
- Sort by ID
- Get people by birth date
- Get people by birth date between two dates
- Get adults (age >= 18)
- ...

### Publisher (5 functions + 2)
- Sort by foundation year
- Get publisher by name
- Get publisher by address
- Does a publisher exist based on a given address
- Get publisher count by foundation date between two dates

### Book (18 functions + 2)
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
- E-Book?
- Add book from user input
- Delete book
