#include "Employee.h"													// Defines class Employee
#include "Map.h"														// Defines template Map<Key, Value>
#include "BookInfo.h"												// Defines class BookInfo

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database;							// Database of employees

typedef string Title;													// Title of book
typedef Map<Title, BookInfo> Library;							// Library of books

using namespace std;

void testEmployeesDatabase();
void addEmployees(Database& database);
void modifyEmployees(Database& database);

void testBooksLibrary();
void addBooks(Library& library);
void modifyBooks(Library& library);

int main() {
	testEmployeesDatabase();
	testBooksLibrary();
}

void testEmployeesDatabase() {
	Database database;
	addEmployees(database);

	Database newDatabase = database;									// Make a copy of database
	newDatabase.add(830505432, Employee("Ewa Nowak", "chairwoman", 43));	// Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database

	cout << "Database after the assignment:" << endl << database << endl;
}

void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
}

void modifyEmployees(Database& database) {
	Employee* employeePtr;

	employeePtr = database.find(510212881);								// Find employee using its ID
	employeePtr->position = "salesman";									// Modify the position of employee
	
	employeePtr = database.find(761028073);								// Find employee using its ID
	employeePtr->age = 29;												// Modify the age of employee
}

void testBooksLibrary() {
	Library library;
	addBooks(library);

	Library newLibrary = library;										// Make a copy of library
	newLibrary.add("C++ Primer", BookInfo("Barbara E. Moo", "educational", 725, false));	// Add first book: title: The C++ Programming Language, author: Bjarne Stroustrup, category: educational, pages: 1324, available: false
	modifyBooks(newLibrary);

	cout << "Original library:" << endl << library << endl;
	cout << "Modified library:" << endl << newLibrary << endl;

	library = newLibrary;												// Update original library

	cout << "Library after the assignment:" << endl << library << endl;
}

void addBooks(Library& library) {
	library.add("The C++ Programming Language", BookInfo("Bjarne Stroustrup", "educational", 1324, true));	// Add first book: title: The C++ Programming Language, author: Bjarne Stroustrup, category: educational, pages: 1324, available: true
	library.add("The C++ Standard Library", BookInfo("Nicolai Josuttis", "educational", 1152, false));		// Add second book
	library.add("Effective C++", BookInfo("Scott Meyers", "educational", 352, true));						// Add third book
}

void modifyBooks(Library& library) {
	BookInfo* bookInfoPtr;

	bookInfoPtr = library.find("The C++ Programming Language");			// Find book using its title
	bookInfoPtr->isAvailable = false;									// Modify the availability of book
	
	bookInfoPtr = library.find("The C++ Standard Library");				// Find book using its title
	bookInfoPtr->numberOfPages = 1153;									// Modify the number of pages of book
}
