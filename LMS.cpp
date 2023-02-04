/*
	Group Project by:
		Ammar Ahmad 2020071
		Bilal Malik 2020102
		Abdullah Farooq 2020023
*/

#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

//  Class CBook

class CBook {
	//Private Members
private:
	int ID;
	string Bookname;
	string author;
	string ISBN;
	int price;
	int pages;
	int IssuedBy;
	string IssuedOn;
	string ReturnDate;

	//Public Functions
public:
	// Constructor
	CBook(int id = 0, string bookname = "Book", string Author = "Unnamed", string isbn = "00000", int Price = 000, int Pages = 000, int issuedBy = 000, string issuedOn = "DD/MM/YY", string returnDate = "DD/MM/YY") {
		setBookname(bookname);
		setID(id);
		setauthor(Author);
		setISBN(isbn);
		setprice(Price);
		setpages(Pages);
		setIssuedBy(issuedBy);
		setIssuedOn(issuedOn);
		setReturnDate(returnDate);
	}

	// Copy Constructor
	CBook(const CBook& old) {
		Bookname = old.Bookname;
		ID = old.ID;
		author = old.author;
		ISBN = old.ISBN;
		price = old.price;
		pages = old.pages;
		IssuedBy = old.IssuedBy;
		IssuedOn = old.IssuedOn;
		ReturnDate = old.ReturnDate;
	}

	// Destructor
	~CBook() {}

	// setters 
	void setBookname(string bookname) {
		Bookname = bookname;
	}
	void setID(int id) {
		ID = id;
	}
	void setauthor(string Author) {
		author = Author;
	}
	void setISBN(string isbn) {
		ISBN = isbn;
	}
	void setprice(int Price) {
		price = Price;
	}
	void setpages(int Pages) {
		pages = Pages;
	}
	void setIssuedBy(int issuedBy) {
		IssuedBy = issuedBy;
	}
	void setIssuedOn(string issuedOn) {
		IssuedOn = issuedOn;
	}
	void setReturnDate(string returnDate) {
		ReturnDate = returnDate;
	}

	//  Getters 	
	int getID() {
		return ID;
	}
	string getBookname() {
		return Bookname;
	}
	string getauthor() {
		return author;
	}
	string getISBN() {
		return ISBN;
	}
	int getprice() {
		return price;
	}
	int getpages() {
		return pages;
	}
	int getIssuedBy() {
		return IssuedBy;
	}
	string getIssuedOn() {
		return IssuedOn;
	}
	string getReturnDate() {
		return ReturnDate;
	}

	// Member Functions
	void printAll();				//	To Print all details of books
	void printSome();				//		To print Specific book detail
	void del_book();				//		To delete a specific book from list
	void add_new();					//		To add new Book in list

	//  Above Member Functions are implemented Below from line 143

};

struct book_node {
	CBook bk;							//		structure to create nodes for CBookList 
	book_node* next;
};

// initializing node pointers to keep track of list
book_node* head1 = NULL;					
book_node* head2 = NULL;
book_node* head3 = NULL;
book_node* tail1 = NULL;					
book_node* tail2 = NULL;
book_node* tail3 = NULL;
book_node* start = NULL;					

void CBook::printAll() {
	start = head1;
	cout << "\nBook ID\tBook Name\tAuthor Name \tISBN \tPrice \tPages \tIssued By \tIssued On \tReturn Date" << endl; 		// Print Header Line
	while (start != NULL) {
		//iterate list and Print data
		cout << start->bk.getID() << "\t" << start->bk.getBookname() << "\t\t" << start->bk.getauthor() << "\t\t" << start->bk.getISBN() << " \t" << start->bk.getprice() << "\t" << start->bk.getpages() << "\t" << start->bk.getIssuedBy() << "\t" << start->bk.getIssuedOn() << "\t" << start->bk.getReturnDate() << endl;
		start = start->next;
	}
}

void CBook::printSome() {
	int id;
	cout << "\nEnter ID of the Book: ";				// Take Book ID as input from user to find the Book

	while (!(cin >> id))
	{
		cout << "Error! please enter an integer: ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	

	start = head1;
	while (start != NULL) {
		// Iterate List and find the Book ID
		if (start->bk.getID() == id) {
			cout << "\nBook ID\tBook Name\tAuthor Name \tISBN \tPrice \tPages \tIssued By \tIssued On \tReturn Date" << endl; 			//Print Header
			//print Data
			cout << start->bk.getID() << "\t" << start->bk.getBookname() << "\t" << start->bk.getauthor() << "\t" << start->bk.getISBN() << " \t" << start->bk.getprice() << "\t" << start->bk.getpages() << "\t" << start->bk.getIssuedBy() << "\t" << start->bk.getIssuedOn() << "\t" << start->bk.getReturnDate() << endl;
			break;
		}
		else {
			start = start->next;
			if (start == NULL) {							// EXCEPTION: IF Book id is not found
				cout << "\n Book ID not FOUND!" << endl;
			}
		}
	}
}

void CBook::del_book() {
	int id;
	cout << "\nEnter ID of the Book: ";					// TAke book ID from user as input to delete from list

	while (!(cin >> id))
	{
		cout << "Error! please enter an integer: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	start = head1;
	while (start != NULL) {				//Iterate And find Book ID
		if (start->next->bk.getID() == id || start->bk.getID() == id) {			//IF ID is found
			if (start == head1) {
				head1 = head1->next;											//IF the node is head of 1st LIST move head to its next
			}
			else if (start->next->next == NULL) {								//If the node is tail move tail backward to 
				tail3 = start;
			}
			else if (start->next == head2) {
				head2 = head2->next;											//If node if head of 2n LISt
				start->next = head2;
			}
			else if (start->next == head3) {
				head3 = head3->next;											//If node if head of 2n List
				start->next = head3;
			}
			else {
				start->next = start->next->next;									// delocate the node and join its predecessor and successor
			}
			break;
		}
		else {
			start = start->next;
			if (start == NULL) {
				cout << "\n Book ID not FOUND!" << endl;							// If book Id is not Found
			}
		}
	}
}

//------------------------------------------//
////////////////////		Class CBookList		//////////
//------------------------------------------//

class CBookList {
private:
	CBook books;							// class Cbook obj to acccess constructor
	int ListID;								//ListID to differentiate between lists
public:
	CBookList(int ID = 1) {
		setListID(ID);
	}
	// Setter
	void setListID(int ID) {
		ListID = ID;
	}
	//Getter
	int getListID() {
		return ListID;
	}
	//Member functions
	void add_node(int l = 0) {						// To add new node for storing new book details
		int id, list;
		string bookname;							//---------------------------------------------//
		string Author;
		string isbn;
		int price;										//initializing Required Variables
		int pages;							//---------------------------------------------//

		if (l == 0) {									// Check whether to enter a list of books or single book
			cout << "\nChoose List to add Book [enter: 1/2/3]: ";
			cin >> list;
			setListID(list);
		}
		else {
			setListID(l);
		}
		cout << "\nEnter ID of Book: ";				//---------------------------------------------//
		while (!(cin >> id))
		{
			cout << "Error! please enter an integer: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		getchar();

		cout << "Enter Bookname: ";
		getline(cin, bookname);

		cout << "Enter Author name: ";
		getline(cin, Author);						// Ask user to input required details of book

		cout << "Enter ISBN: ";
		getline(cin, isbn);

		cout << "Enter Price: ";
		while (!(cin >> price))
		{
			cout << "Error! please enter an integer: ";
			cin.clear();
			cin.ignore(100, '\n');
		}

		cout << "Enter no. of Pages: ";
		while (!(cin >> pages))
		{
			cout << "Error! please enter an integer: ";
			cin.clear();
			cin.ignore(100, '\n');
		}    							//---------------------------------------------//

		CBook books(id, bookname, Author, isbn, price, pages); 		//Call CBook constructor to set values

		book_node* tmp = new book_node;					//create new node
		tmp->bk = books;								//Copy objects
		if (ListID == 1) {
			if (head1 == NULL) {
				head1 = tmp;							// If creating 1st Node in 1st List
				tail1 = tmp;
				tail1->next = head2;
			}
			else {
				tail1->next = tmp;
				tail1 = tmp;
				if (head2 != NULL) {						// appending node in 1st list
					tail1->next = head2;
				}
				else {
					tail1->next = head3;
				}
			}
		}
		else if (ListID == 2) {
			if (head2 == NULL) {
				head2 = tmp;
				tail2 = tmp;						//if creating 1st node in 2nd list
				tail1->next = head2;
				tail2->next = head3;
			}
			else {
				tail2->next = tmp;
				tail2 = tmp;						// appending node in 2nd list
				tail2->next = head3;
			}
		}
		else if (ListID == 3) {
			if (head3 == NULL) {
				head3 = tmp;
				tail3 = tmp;					//if creating 1st node in 3rd list
				tail3->next = NULL;
				if (tail2 != NULL) {
					tail2->next = head3;
				}
				else {
					tail1->next = head3;
				}
			}
			else {
				tail3->next = tmp;
				tail3 = tmp;				//appending node in 3rd list
				tail3->next = NULL;
			}
		}
	}

	void printall() {
		books.printAll();					// Function from CBook class to print all details of book
	}
	void printsome() {						//function to print details of Books in particular List 
		int list;
		cout << "\nEnter List ID [1/2/3]: ";
		while (!(cin >> list))
		{
			cout << "Error! please enter an integer [1/2/3]: ";
			cin.clear();
			cin.ignore(100, '\n');
		}							//Take ListID from user to display that list
		setListID(list);
		if (ListID == 1) {
			if (head1 == NULL) {
				cout << "\nNO Book available in List ID 1" << endl;			//If list 1 is NULL
			}
			else {
				start = head1;
				cout << "\nBook ID\tBook Name\tAuthor Name \tISBN \tPrice \tPages \tIssued By \tIssued On \tReturn Date" << endl;
				while (start != head2) {
					cout << start->bk.getID() << "\t" << start->bk.getBookname() << "\t\t" << start->bk.getauthor() << "\t\t" << start->bk.getISBN() << " \t" << start->bk.getprice() << "\t" << start->bk.getpages() << "\t" << start->bk.getIssuedBy() << "\t" << start->bk.getIssuedOn() << "\t" << start->bk.getReturnDate() << endl;
					start = start->next;
				}
			}
		}
		if (ListID == 2) {
			if (head2 == NULL) {
				cout << "\nNO Book available in List ID 2" << endl;		 //If list 2 is NULL
			}
			else {
				start = head2;
				cout << "\nBook ID\tBook Name\tAuthor Name \tISBN \tPrice \tPages \tIssued By \tIssued On \tReturn Date" << endl;
				while (start != head3) {
					cout << start->bk.getID() << "\t" << start->bk.getBookname() << "\t\t" << start->bk.getauthor() << "\t\t" << start->bk.getISBN() << " \t" << start->bk.getprice() << "\t" << start->bk.getpages() << "\t" << start->bk.getIssuedBy() << "\t" << start->bk.getIssuedOn() << "\t" << start->bk.getReturnDate() << endl;
					start = start->next;
				}
			}
		}
		if (ListID == 3) {
			if (head3 == NULL) {
				cout << "\nNO Book available in List ID 3" << endl;				//If list 3 is NULL
			}
			else {
				start = head3;
				cout << "\nBook ID\tBook Name\tAuthor Name \tISBN \tPrice \tPages \tIssued By \tIssued On \tReturn Date" << endl;
				while (start != NULL) {
					cout << start->bk.getID() << "\t" << start->bk.getBookname() << "\t\t" << start->bk.getauthor() << "\t\t" << start->bk.getISBN() << " \t" << start->bk.getprice() << "\t" << start->bk.getpages() << "\t" << start->bk.getIssuedBy() << "\t" << start->bk.getIssuedOn() << "\t" << start->bk.getReturnDate() << endl;
					start = start->next;
				}
			}
		}
	}

	void Del_list() {						// To delete whole list
		int num, list;
		cout << "\nChoose ListID to Delete [1/2/3]: ";
		while (!(cin >> list))
		{
			cout << "Error! please enter an integer [1/2/3]: ";
			cin.clear();
			cin.ignore(100, '\n');
		}										//Ask user to input ListID
		if (list == 1) {
			if (head2 != NULL) {
				head1 = head2;							//If list 1 is going to be deleted move head1 to head2 for proper functioning of other functions 
				tail1 = NULL;
			}
		}
		else if (list == 2) {
			tail1->next = head3;
			head2 = NULL;								//If list 2 is bieng removed interconnet list 1 and list 3
			tail2 = NULL;
		}
		else if (list == 3) {
			tail2->next = NULL;							//IF list 3 is bieng deleted disconnect list 2 and list3
			head3 = NULL;
		}
	}

	void asc_sort() {								// Sort List in Asscending Order by buuble sorting
		start = head1;
		int counter = 0;
		while (start != NULL) {
			start = start->next;
			counter++;
		}
		start = head1;
		int j;
		for (j = 0; j < counter; j++) {
			while (start != NULL) {
				if (start->next != NULL) {
					if (start->bk.getID() > start->next->bk.getID()) { 		// if present one is greater than next one then replace with the next one
						CBook temp = start->bk;
						start->bk = start->next->bk;
						start->next->bk = temp;
					}
				}
				start = start->next;									//Iterate thorough the list
			}
			start = head1;												//Iterste for each book
		}
		books.printAll();
	}

	void dec_sort() {										// Sorting List in Decending Order by bubble sort
		start = head1;
		int counter = 0;
		while (start != NULL) {
			start = start->next;
			counter++;
		}
		start = head1;
		int j;
		for (j = 0; j < counter; j++) {
			while (start != NULL) {
				if (start->next != NULL) {
					if (start->bk.getID() < start->next->bk.getID()) {		//If present on is smaller than next one then interchange them
						CBook temp = start->bk;
						start->bk = start->next->bk;
						start->next->bk = temp;
					}
				}
				start = start->next;
			}
			start = head1;
		}
		books.printAll();
	}

	void del_all() {
		head1 = NULL;					//----------------------------------------------------------------//
		head2 = NULL;
		head3 = NULL;								//delocate all pointers
		tail1 = NULL;
		tail2 = NULL;
		tail3 = NULL;					//----------------------------------------------------------------//
	}

	void del_and_place() {					// to delete book from 1 list and place to another
		int book_id, list_id;
		book_node* temp = NULL;
		cout << "\nEnter Book ID: ";
		while (!(cin >> book_id))
		{
			cout << "Error! please enter an integer for Book ID: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		cout << "Enter new list ID[1/2/3]: ";
		while (!(cin >> list_id))
		{
			cout << "Error! please enter an integer for List ID [1/2/3]: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		start = head1;
		cout << start->bk.getID();
		while (start != NULL) {
			cout << "  in  ";
			if (start->next->bk.getID() == book_id) {					//Find Book Id 
				temp = start->next;
				start->next = start->next->next;
				break;
			}
			else {
				start = start->next;								//Iterate Through List
			}

		}

		//Apennd book to new list

		if (list_id == 1) {
			if (head1 == NULL) {
				head1 = temp;
				tail1 = temp;
				tail1->next = head2;
			}
			else {
				tail1->next = temp;
				tail1 = temp;
				if (head2 != NULL) {
					tail1->next = head2;
				}
				else {
					tail1->next = head3;
				}
			}
		}

		else if (list_id == 2) {
			if (head2 == NULL) {
				head2 = temp;
				tail2 = temp;
				tail1->next = head2;
				tail2->next = head3;
			}
			else {
				tail2->next = temp;
				tail2 = temp;
				tail2->next = head3;
			}
		}
		else if (list_id == 3) {
			if (head3 == NULL) {
				head3 = temp;
				tail3 = temp;
				tail3->next = NULL;
				if (tail2 != NULL) {
					tail2->next = head3;
				}
				else {
					tail1->next = head3;
				}
			}
			else {
				tail3->next = temp;
				tail3 = temp;
				tail3->next = NULL;
			}
		}
		else {
			cout << "\nInvalid ID!!" << endl;
		}
	}
};

void CBook::add_new() {
	CBookList ad;
	ad.add_node();
}

//   Class CStudent

class CStudent {
private:
	int ID;
	string StdName;
	int RollNo;
	int BooksIssued;
public:
	//Constructor
	CStudent(int id = 0, string name = "Unnamed", int roll = 0, int booksissued = 0) {
		setstdID(id);
		setStdName(name);
		setRollNo(roll);
		setBooksIssued(booksissued);
	}
	//Destructor
	~CStudent() {	}
	// setter
	void setstdID(int id) {
		ID = id;
	}
	void setStdName(string name) {
		StdName = name;
	}
	void setRollNo(int roll) {
		RollNo = roll;
	}
	void setBooksIssued(int booksissued) {
		BooksIssued = booksissued;
	}
	//getters
	int getstdID() {
		return ID;
	}
	string getStdName() {
		return StdName;
	}
	int getRollNo() {
		return RollNo;
	}
	int getBookIssued() {
		return BooksIssued;
	}
	// Member Functions

	void printAllStd();				// To Print list of students details
	void printSomeStd();			//to print specific student details
	void del_std();					// to remove student from list
	void add_std();					//toadd new student in list
	// these functions are implemented below at line 594
};

struct student_node {
	CStudent s;				// structure node for creating studentlist 
	student_node* next;
};

student_node* head = NULL;
student_node* tail = NULL;			//Initializing required pointers for list handling
student_node* Start = NULL;

void CStudent::printAllStd() { 		//To print All students
	Start = head;
	cout << "\nID\tStudent Name\tRoll No.\tBook Issued" << endl;			//print header
	while (Start != NULL) {		//Iterate through List
		cout << Start->s.getstdID() << "\t" << Start->s.getStdName() << "\t\t" << Start->s.getRollNo() << "\t\t" << Start->s.getBookIssued() << endl;
		Start = Start->next;
	}
}

void CStudent::printSomeStd() {			//to print details of specific student
	int id;
	cout << "\nEnter Student ID: ";		//ask user to inout student ID
	while (!(cin >> id))
	{
		cout << "Error! please enter an integer for Student ID: ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	Start = head;
	while (Start != NULL) {
		if (Start->s.getstdID() == id) {			//Find student ID
			cout << "\nID\tStudent Name\tRoll No.\tBook Issued" << endl;		//print header
			//print data		
			cout << Start->s.getstdID() << "\t" << Start->s.getStdName() << "\t\t" << Start->s.getRollNo() << "\t\t" << Start->s.getBookIssued() << endl;
			break;
		}
		else {
			Start = Start->next;				//iterate List
			if (Start == NULL) {
				cout << "\nStudent ID not FOUND!" << endl;			//EXCEPTION for not finding the id in list
			}
		}
	}
}

void CStudent::del_std() {				//to delete student
	int id;
	cout << "Enter Student ID: ";			//Ask user to inout Student ID
	while (!(cin >> id))
	{
		cout << "Error! please enter an integer for Student ID: ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	Start = head;
	while (Start != NULL) {
		if (head->s.getstdID() == id) {
			head = head->next;					//If node is head
			break;
		}
		else if (Start->next->s.getstdID() == id) {
			Start->next = Start->next->next;		//interconet previous and next node and delocate the id
			break;
		}
		else {
			Start = Start->next;
			if (Start == NULL) {
				cout << "/nStudent ID not Found!" << endl;			//If Student Id not fount in list
			}
		}
	}
}

//------------------------------------------//
//		Class CStudentList
//------------------------------------------//

class CStudentList {
private:
	CStudent std;
public:
	CStudentList() { }		//Constructor
	~CStudentList() { }		//Destructor

	void add_student() {			//To add new student
		int id;
		string stdname;			//Required variables
		int roll;

		cout << "\nEnter Student ID: ";						//-----------------------------------//
		while (!(cin >> id))
		{
			cout << "Error! please enter an integer for Student ID: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		getchar();
		cout << "Enter Student Name: ";							   // Ask user to input data
		getline(cin, stdname);
		cout << "Enter Student Roll NO.: ";
		while (!(cin >> roll))
		{
			cout << "Error! please enter an integer for Student Roll No: ";
			cin.clear();
			cin.ignore(100, '\n');
		}											//-----------------------------------//

		CStudent std(id, stdname, roll);				//Constructor call of class CStudent

		student_node* tmp = new student_node;		//create new student node
		tmp->s = std;
		tmp->next = NULL;

		if (head == NULL) {
			head = tmp;
			tail = tmp;
			tail->next = NULL;
		}
		else {
			tail->next = tmp;
			tail = tmp;
			tail->next = NULL;
		}
	}

	void del_student() {			//To delete student
		std.del_std();
	}
};

void CStudent::add_std() {		//to add student 
	CStudentList l;
	l.add_student();
}

//------------------------------------------//
///////		Class CLibrary     		/////////
//------------------------------------------//

class CLibrary {
private:
	CBook book;
	CStudentList Std;
public:
	CLibrary() {	}	//Contructor
	~CLibrary() {	}			//Destructor

	void issue_book() {			//To issue Book
		int book_id, student_id;
		int avl_book = 1;

		string issue_date, return_date;					//-------------------------------------------------//
		cout << "\nEnter Book ID: ";
		while (!(cin >> book_id))
		{
			cout << "Error! please enter an integer for Book ID: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		cout << "Enter Student ID: ";
		while (!(cin >> student_id))
		{
			cout << "Error! please enter an integer for Student ID: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		getchar();												//Ask User to enter required data
		cout << "Enter Issue Date (DD/MM/YY): ";
		getline(cin, issue_date);
		cout << "Enter Return Date (DD/MM/YY): ";
		getline(cin, return_date);						//-------------------------------------------------//
		start = head1;
		while (start != NULL) {
			if (start->bk.getID() == book_id) {			//Find book Id and check availibilty of book
				if (start->bk.getIssuedBy() != 0) {
					cout << "\nBook Already Issued!" << endl;
					break;
				}
				else {
					start->bk.setIssuedBy(student_id);
					start->bk.setIssuedOn(issue_date);			//If not issued then issue to student id
					start->bk.setReturnDate(return_date);
					break;
				}
			}
			else {
				start = start->next;
				if (start == NULL) {			//Check availibility of book
					cout << "\nBook Not Found!" << endl;			//EXCEPTION : Book id not found
					avl_book = 0;
				}
			}
		}
		if (avl_book != 0) { 			// If book Availabale update student data
			Start = head;
			while (start != NULL) {
				if (Start->s.getstdID() == student_id) {
					Start->s.setBooksIssued(book_id);
					break;
				}
				else {
					Start = Start->next;
					if (start == NULL) {							//EXCEPTION: if student id not found
						cout << "\nStudent ID not Found!" << endl;
					}
				}
			}
		}
	}

	void return_book() { 				// To return Book
		int book_id, student_id;
		// Required Data
		cout << "\nEnter Book ID: ";
		while (!(cin >> book_id))
		{
			cout << "Error! please enter an integer for Book ID: ";
			cin.clear();
			cin.ignore(100, '\n');
		}					
		cout << "Enter Student ID: ";
		while (!(cin >> student_id))
		{
			cout << "Error! please enter an integer for Student ID: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		start = head1;
		while (start != NULL) {
			if (start->bk.getID() == book_id) {		//Find book in list
				start->bk.setIssuedBy(0);
				start->bk.setIssuedOn("DD/MM/YY");			//Update book info to default
				start->bk.setReturnDate("DD/MM/YY");
				break;
			}
			else {
				start = start->next;						//itterate in List
				if (start == NULL) {
					cout << "\nBook ID Not Found!" << endl;		//EXCEPTION: Book ID not found
				}
			}
		}
		Start = head;
		while (start != NULL) {
			if (Start->s.getstdID() == student_id) {		//Find Student id in list
				Start->s.setBooksIssued(0);				//Update Student info to default
				break;
			}
			else {
				Start = Start->next;					//Itterate in student list
				if (start == NULL) {
					cout << "\nStudent ID not Found!" << endl;		// EXCEPTION: Student ID not found
				}
			}
		}
	}

	void printIssuedBooks() {			// To print Issued Books
		start = head1;
		cout << "\nBook ID\tBook Name\tAuthor Name \tISBN \tPrice \tPages \tIssued By \tIssued On \tReturn Date" << endl;  //print header
		while (start != NULL) {
			if (start->bk.getIssuedBy() != 0) { 			// Find if anyone issued any book
			//print Data
				cout << start->bk.getID() << "\t" << start->bk.getBookname() << "\t\t" << start->bk.getauthor() << "\t\t" << start->bk.getISBN() << " \t" << start->bk.getprice() << "\t" << start->bk.getpages() << "\t" << start->bk.getIssuedBy() << "\t" << start->bk.getIssuedOn() << "\t" << start->bk.getReturnDate() << endl;
				start = start->next;
			}
			else {
				start = start->next;				// Itterate Book List
			}
		}
	}

	void printBookList() {			//To print Book List
		CBook a;
		a.printAll();
	}

	void printStudentList() {		//To print Student List
		CStudent b;
		b.printAllStd();
	}
};


int main() {

	int ch1;				//Choice variables for switches			
	int ch2;
	CBook obj1;					//--------------------------------------------------------//
	CBookList obj2;
	CStudent obj3;							// Object of Each class
	CStudentList obj4;
	CLibrary obj5;				//--------------------------------------------------------//

	// MAIN MENU

	while (1) {
		cout << "Main Menu\n\t1. Student.\n\t2. Book.\n\t3. List.\n\t4. Library.\n\t5. Exit" << endl;
		while (!(cin >> ch1))
		{
			cout << "Error! please enter an integer value: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		int loop = 1;
		int con = 1;
		switch (ch1) {
		case 1:
			// Student Sub-menu
			while (loop != 0) {
				cout << "\nStudent Sub-Menu\n\t1. Add New Student.\n\t2. Delete Existing Student.\n\t3. Show particular student.\n\t4. Show all Students.\n\t5. Back" << endl;
				while (!(cin >> ch2))
				{
					cout << "Error! please enter an integer value: ";
					cin.clear();
					cin.ignore(100, '\n');
				}
				switch (ch2) {
				case 1:
					obj4.add_student();
					break;
				case 2:
					obj4.del_student();
					break;
				case 3:
					obj3.printSomeStd();
					break;
				case 4:
					obj3.printAllStd();
					break;
				case 5:
					loop = 0;
					break;
				default:
					cout << "\nInvalid Choice!" << endl;
				}
			}
			break;
		case 2:
			//	 Book Sub-menu
			while (loop != 0) {
				cout << "\nBook Sub-Menu\n\t1. Add New Book.\n\t2. Delete Existing Book.\n\t3. Show particular Book.\n\t4. Show all Books.\n\t5. Sort Books in Ascending order.\n\t6. Sort Books in Descending order.\n\t7. Back" << endl;
				while (!(cin >> ch2))
				{
					cout << "Error! please enter an integer value: ";
					cin.clear();
					cin.ignore(100, '\n');
				}
				switch (ch2) {
				case 1:
					obj2.add_node();
					break;
				case 2:
					obj1.del_book();
					break;
				case 3:
					obj1.printSome();
					break;
				case 4:
					obj1.printAll();
					break;
				case 5:
					obj2.asc_sort();
					break;
				case 6:
					obj2.dec_sort();
					break;
				case 7:
					loop = 0;
					break;
				default:
					cout << "\nInvalid Choice!" << endl;
				}
			}
			break;
		case 3:
			// List Sub-Menu
			while (loop != 0) {
				cout << "\nList Sub-Menu\n\t1. Add New List.\n\t2. Delete Existing List.\n\t3. Show particular List.\n\t4. Show all Books.\n\t5. Delete book from list and assign book to another list.\n\t6. Back" << endl;
				while (!(cin >> ch2))
				{
					cout << "Error! please enter an integer value: ";
					cin.clear();
					cin.ignore(100, '\n');
				}
				switch (ch2) {
				case 1:
					int l;
					cout << "Choose ListID to add List [1/2/3]: ";
					cin >> l;
					while (con != 0) {
						obj2.add_node(l);
						cout << "\nDo you want to add more books? (enter 1 for yes and 0 for no): ";
						while (!(cin >> con))
						{
							cout << "Error! please enter an integer value (1 or 0): ";
							cin.clear();
							cin.ignore(100, '\n');
						}
					}
					break;
				case 2:
					obj2.Del_list();
					break;
				case 3:
					obj2.printsome();
					break;
				case 4:
					obj2.printall();
					break;
				case 5:
					obj2.del_and_place();
					break;
				case 6:
					loop = 0;
					break;
				default:
					cout << "\nInvalid Choice!";
				}
			}
			break;
		case 4:
			// Library Sub-Menu
			while (loop != 0) {
				cout << "\nLibrary Sub-Menu\n\t1. Issue a book.\n\t2. Return a book.\n\t3. Print which books have been issued.\n\t4. Back" << endl;
				while (!(cin >> ch2))
				{
					cout << "Error! please enter an integer value: ";
					cin.clear();
					cin.ignore(100, '\n');
				}
				switch (ch2) {
				case 1:
					obj5.issue_book();
					break;
				case 2:
					obj5.return_book();
					break;
				case 3:
					obj5.printIssuedBooks();
					break;
				case 4:
					loop = 0;
					break;
				default:
					cout << "\nInvalid Choice!";
				}

			}
			break;
		case 5:
			// Exit
			return 0;
			break;
		default:
			cout << "Invalid input!" << endl;
		}
	}
}
