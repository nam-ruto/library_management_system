#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "media.h"
using namespace std;

//Prototype: Input data from text file
void inputBookData(Book *bookStorage);
void inputMagazineData(Magazine *magazineStorage);
void inputNewspaperData(Newspaper *newspaperStorage);

//TASK 1: Display databases
void displayBooks(Book *bookStorage);
void displayMagazine(Magazine *magazineStorage);
void displayNewspaper(Newspaper *newspaperStorage);

//TASK 2: SEARCH AVAILABLE ITEMS
void searchBook(string, Book *bookStorage);
void searchMagazine(string, Magazine *magazineStorage);
void searchNewspaper(string, Newspaper *newspaperStorage);

//Task 3+4:SEARCH FOR CHECK OUT / RETURN ITEMS
int searchItem(Book *, string);
int searchItem(Magazine *, string);
int searchItem(Newspaper *, string);

//TASK 5: Add Item to the Databases
void addItem(Book *);
void addItem(Magazine *);
void addItem(Newspaper *);

//Layout: Display the table
void layout(int n); 
void bookHeader();
void bookColumn(Book *, int );
void magazineHeader();
void magazineColumn(Magazine *, int );
void newspaperHeader();
void newspaperColumn(Newspaper *, int );

fstream myFile; //Initialize fstream: Reading data from text file

int main()
{
    Book bookStorage[100];
    Magazine magazineStorage[100];
    Newspaper newspaperStorage[100];

    inputBookData(bookStorage);
    inputMagazineData(magazineStorage);
    inputNewspaperData(newspaperStorage);

    string option;
    
    while(true)
    {
        cout << endl;
        cout << "LIBRARY MANAGEMENT SYSTEM\n";
        cout << "1: Display library databases\n";
        cout << "2: Search available items \n";
        cout << "3: Check out items\n";
        cout << "4: Return items\n";
        cout << "5: Add item to the databases\n";
        cout << "6: Exit program\n";

        cout << "Input your option (1-6): ";
        cin >> option;
        cout << endl;

        if(option == "1")
        {
            displayBooks(bookStorage);
            displayMagazine(magazineStorage);
            displayNewspaper(newspaperStorage);
        }

        else if(option == "2")
        {
            string category, subCategory;

            cout << "Which category do you want to search?" << endl;
            cout << "(1) BOOKS" << endl;
            cout << "(2) MAGAZINE" << endl;
            cout << "(3) NEWSPAPER" << endl;
            cout << "Search by: "; cin >> category;
            cout << "Search by (1) TITLE or (2) AUTHOR: "; cin >> subCategory;
            
            if(category == "1") searchBook(subCategory, bookStorage);
            else if(category == "2") searchMagazine(subCategory, magazineStorage);
            else if(category == "3") searchNewspaper(subCategory, newspaperStorage);

            else cout << "Invalid input. Please try again" << endl;
        }

        else if(option == "3")
        {
            string category, name;

            cout << "Which category do you want to check out?" << endl;
            cout << "(1) BOOKS" << endl;
            cout << "(2) MAGAZINE" << endl;
            cout << "(3) NEWSPAPER" << endl;
            cout << "Check out by: "; cin >> category;
            cout << "Input Item's Title you want to check-out: "; cin.ignore(); getline(cin, name);

            //Find in Book storage
            if(category == "1")
            {
                int i = searchItem(bookStorage, name);
                if(i != -1)
                    bookStorage[i].checkOut();
            }

            //Find in Magazine storage
            else if(category == "2")
            {
                int i = searchItem(magazineStorage, name);
                if(i != -1)
                    magazineStorage[i].checkOut();
            }

            //Find in Newspaper storage
            else
            {
                int i = searchItem(newspaperStorage, name);
                if(i != -1)
                    newspaperStorage[i].checkOut();
            }
        }

        else if(option == "4")
        {
            string category, name;

            cout << "Which category do you want to return?" << endl;
            cout << "(1) BOOKS" << endl;
            cout << "(2) MAGAZINE" << endl;
            cout << "(3) NEWSPAPER" << endl;
            cout << "Return by: "; cin >> category;
            cout << "Input Item's Title you want to return: "; cin.ignore(); getline(cin, name);

            //Find in Book storage
            if(category == "1")
            {
                int i = searchItem(bookStorage, name);
                if(i != -1)
                    bookStorage[i].returnItem();
            }

            //Find in Magazine storage
            else if(category == "2")
            {
                int i = searchItem(magazineStorage, name);
                if(i != -1)
                    magazineStorage[i].returnItem();
            }

            //Find in Newspaper storage
            else
            {
                int i = searchItem(newspaperStorage, name);
                if(i != -1)
                    newspaperStorage[i].returnItem();
            }
        }

        else if(option == "5")
        {
            string category, name;

            cout << "Which category do you want to ADD into the Databases?" << endl;
            cout << "(1) BOOKS" << endl;
            cout << "(2) MAGAZINE" << endl;
            cout << "(3) NEWSPAPER" << endl;
            cout << "Your option: "; cin >> category;

            if(category == "1")
                addItem(bookStorage);
            else if(category == "2")
                addItem(bookStorage);
            else
                addItem(newspaperStorage);
        }

        else if(option == "6")
        {
            cout << "Saving data..." << endl;
            cout << "Exit program..." << endl;
            cout << "Program Closed!" << endl;
            return 0;
        }

        else cout << "Invalid input. Please try again\n";
    }

    return 0;
}

//READ DATA FROM TEXT FILE
void inputBookData(Book *bookStorage)
{
    myFile.open("data/book_data.txt", ios::in);
    if(myFile.fail())
    {
        cout << "Cannot open the file. Please try again\n";
    }
    else
    {
        string title, author, available, ISBN, line;
        int pageCount, year, index = 0;

        while(getline(myFile, line))
        {
            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, available, ',');
            getline(ss, ISBN, ',');
            ss >> pageCount;
            ss.ignore(); // Ignore the comma
            ss >> year;

            Book tmp(title, author, available, ISBN, pageCount, year);
            bookStorage[index] = tmp;

            index ++;
        }
    }

    myFile.close();
}

void inputMagazineData(Magazine *magazineStorage)
{
    myFile.open("data/magazine_data.txt", ios::in);
    if(myFile.fail())
    {
        cout << "Cannot open the file. Please try again\n";
    }
    else
    {
        string title, author, available, subs, freq, content, line;
        int pageCount, year, index = 0;

        while(getline(myFile, line))
        {
            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, available, ',');
            getline(ss, subs, ',');
            getline(ss, freq, ',');
            getline(ss, content, ',');
        
            Magazine tmp(title, author, available, subs, freq, content);
            magazineStorage[index] = tmp;

            index ++;
        }
    }

    myFile.close();
}

void inputNewspaperData(Newspaper *newspaperStorage)
{
    myFile.open("data/newspaper_data.txt", ios::in);
    if(myFile.fail())
    {
        cout << "Cannot open the file. Please try again\n";
    }
    else
    {
        string title, author, available, publicFrequency, local, line, topic;
        int index = 0;

        while(getline(myFile, line))
        {
            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, available, ',');
            getline(ss, publicFrequency, ',');
            getline(ss, local, ',');
            getline(ss, topic, ',');
        
            Newspaper tmp(title, author, available, publicFrequency, local, topic);
            newspaperStorage[index] = tmp;

            index ++;
        }
    }

    myFile.close();
}

void layout(int n)
{
    ios init(NULL);
    init.copyfmt(cout);
    cout << "+" << setw(n) << setfill('-') << "" << "+" << endl;
    cout.copyfmt(init); // Reset fill character to the defaultcout << "----------------------------------------------------\n";
}

//TASK 1: DISPLAY DATABASES
void displayBooks(Book *bookStorage)
{
    //DISPLAY BOOK DATABASES
    layout(112);
    cout << left << setw(55) << "|" << "BOOK" << right << setw(55) << "|" << endl;
    layout(112);
    cout << left << setw(30) << "| TITLE" << "   | " << setw(18)
        << "AUTHOR" << " | " << setw(15)
        << "AVAILABLE" << " | " << setw(15)
        << "ISBN" << " | " << setw(10)
        << "PAGES" << " | " << setw(8)
        << "YEAR" << "|"<< endl;
    layout(112);
    int i = 0;
    while(bookStorage[i].getTitle() != "Null")
    {
        cout << "| " << left << setw(30) << bookStorage[i].getTitle() << " | " << setw(18)
        << bookStorage[i].getAuthor() << " | " << setw(15)
        << bookStorage[i].getAvailable() << " | " << setw(15)
        << bookStorage[i].getISBN() << " | " << setw(10)
        << bookStorage[i].getPageCount() << " | " << setw(8)
        << bookStorage[i].getPublicationYear() << "|" << endl;
        i++;
    }
    layout(112);
}

void displayMagazine(Magazine *magazineStorage)
{
    // DISPLAY Magazine DATABASES
    layout(120);
    cout << left << setw(57) << "|" << "MAGAZINE" << right << setw(57) << "|" << endl;
    layout(120);
    cout << left << setw(30) << "| TITLE" << "   | " << setw(18)
        << "AUTHOR" << " | " << setw(15)
        << "AVAILABLE" << " | " << setw(15)
        << "SUBSCRIPTION" << " | " << setw(10)
        << "FREQUENCY" << " | " << setw(16)
        << "CONTENT" << "|"<< endl;
    layout(120);
    int i = 0;
    while(magazineStorage[i].getTitle() != "Null")
    {
        cout << "| " << left << setw(30) << magazineStorage[i].getTitle() << " | " << setw(18)
        << magazineStorage[i].getAuthor() << " | " << setw(15)
        << magazineStorage[i].getAvailable() << " | " << setw(15)
        << magazineStorage[i].getSubscriptionDuration() << " | " << setw(10)
        << magazineStorage[i].getFrequencyOfPublication() << " | " << setw(16)
        << magazineStorage[i].getContent() << "|" << endl;
        i++;
    }
    layout(120);
}

void displayNewspaper(Newspaper *newspaperStorage)
{
    // DISPLAY Newspaper DATABASES
    layout(123);
    cout << left << setw(59) << "|" << "Newspaper" << right << setw(57) << "|" << endl;
    layout(123);
    cout << left << setw(30) << "| TITLE" << "   | " << setw(18)
        << "AUTHOR" << " | " << setw(15)
        << "AVAILABLE" << " | " << setw(15)
        << "FREQUENCY" << " | " << setw(15)
        << "LOCAL" << " | " << setw(14)
        << "TOPIC" << "|"<< endl;
    layout(123);
    int i = 0;
    while(newspaperStorage[i].getTitle() != "Null")
    {
        cout << "| " << left << setw(30) << newspaperStorage[i].getTitle() << " | " << setw(18)
        << newspaperStorage[i].getAuthor() << " | " << setw(15)
        << newspaperStorage[i].getAvailable() << " | " << setw(15)
        << newspaperStorage[i].getPublicationFrequency() << " | " << setw(15)
        << newspaperStorage[i].isLocal() << " | " << setw(14)
        << newspaperStorage[i].getTopic() << "|" << endl;
        i++;
    }
    layout(123);
}

//TASK 2: SEARCH AVAILABLE ITEM
void searchBook(string subCategory, Book *bookStorage)
{
    //subCategory == "1" --> Search by Title
    //subCategory == "2" --> Search by Author
    if(subCategory == "1")
    {
        string titleName;
        cout << "Input title book you want to find: "; 
        cin.ignore(); getline(cin, titleName);

        int i = searchItem(bookStorage, titleName);
        if(i != -1)
        {
            bookHeader();
            bookColumn(bookStorage, i);
            i++;
            while(bookStorage[i].getTitle() != "Null")
            {
                if(bookStorage[i].getTitle() == titleName)
                    bookColumn(bookStorage, i);
                i++;
            }
            layout(112);
        }

    }

    else if(subCategory == "2")
    {
        string authorName;
        cout << "Input Author's name you want to find: "; 
        cin.ignore(); getline(cin, authorName);

        int i = searchItem(bookStorage, authorName);
        if(i != -1)
        {
            bookHeader();
            bookColumn(bookStorage, i);
            i++;
            while(bookStorage[i].getTitle() != "Null")
            {
                if(bookStorage[i].getAuthor() == authorName)
                    bookColumn(bookStorage, i);
                i++;
            }
            layout(112);
        }
    }
}

void searchMagazine(string subCategory, Magazine *magazineStorage)
{
    //subCategory == "1" --> Search by Title
    //subCategory == "2" --> Search by Author
    if(subCategory == "1")
    {
        string titleName;
        cout << "Input title book you want to find: "; 
        cin.ignore(); getline(cin, titleName);

        int i = searchItem(magazineStorage, titleName);
        if(i != -1)
        {
            magazineHeader();
            magazineColumn(magazineStorage, i);
            i++;
            while(magazineStorage[i].getTitle() != "Null")
            {
                if(magazineStorage[i].getTitle() == titleName)
                    magazineColumn(magazineStorage, i);
                i++;
            }
            layout(120);
        }

    }

    else if(subCategory == "2")
    {
        string authorName;
        cout << "Input Author's name you want to find: "; 
        cin.ignore(); getline(cin, authorName);

        int i = searchItem(magazineStorage, authorName);
        if(i != -1)
        {
            magazineHeader();
            magazineColumn(magazineStorage, i);
            i++;
            while(magazineStorage[i].getTitle() != "Null")
            {
                if(magazineStorage[i].getAuthor() == authorName)
                    magazineColumn(magazineStorage, i);
                i++;
            }
            layout(120);
        }
    }
}

void searchNewspaper(string subCategory, Newspaper *newspaperStorage)
{
    //subCategory == "1" --> Search by Title
    //subCategory == "2" --> Search by Author
    if(subCategory == "1")
    {
        string titleName;
        cout << "Input title book you want to find: "; 
        cin.ignore(); getline(cin, titleName);

        int i = searchItem(newspaperStorage, titleName);
        if(i != -1)
        {
            newspaperHeader();
            newspaperColumn(newspaperStorage, i);
            i++;
            while(newspaperStorage[i].getTitle() != "Null")
            {
                if(newspaperStorage[i].getTitle() == titleName)
                    newspaperColumn(newspaperStorage, i);
                i++;
            }
            layout(112);
        }

    }

    else if(subCategory == "2")
    {
        string authorName;
        cout << "Input Author's name you want to find: "; 
        cin.ignore(); getline(cin, authorName);

        int i = searchItem(newspaperStorage, authorName);
        if(i != -1)
        {
            newspaperHeader();
            newspaperColumn(newspaperStorage, i);
            i++;
            while(newspaperStorage[i].getTitle() != "Null")
            {
                if(newspaperStorage[i].getAuthor() == authorName)
                    newspaperColumn(newspaperStorage, i);
                i++;
            }
            layout(123);
        }
    }
}

//TASK 3+4: SEARCH ITEM
int searchItem(Book * storage, string name)
{
    int i = 0;
    while(storage[i].getTitle() != "Null")
    {
        if(storage[i].getTitle() == name || storage[i].getAuthor() == name)
            return i;
        i++;
    }
    cout << "DATA NOT FOUND" << endl;
    return -1;
}

int searchItem(Magazine * storage, string name)
{
    int i = 0;
    while(storage[i].getTitle() != "Null")
    {
        if(storage[i].getTitle() == name || storage[i].getAuthor() == name)
            return i;
        i++;
    }
    cout << "DATA NOT FOUND" << endl;
    return -1;
}

int searchItem(Newspaper *storage, string name)
{
    int i = 0;
    while(storage[i].getTitle() != "Null")
    {
        if(storage[i].getTitle() == name || storage[i].getAuthor() == name)
            return i;
        i++;
    }
    cout << "DATA NOT FOUND" << endl;
    return -1;
}

//TASK 5: ADD ITEM TO DATABASES
void addItem(Book *storage)
{
    string title, author, available = "Available", ISBN; int i = 0, pageCount, year;
    cout << "Adding a new Book to Library Databases:" << endl;
    cout << "Book Title: "; cin.ignore(); getline(cin, title);
    cout << "Author's Name: "; getline(cin, author);
    cout << "ISBN number: "; getline(cin, ISBN);
    cout << "Page number: "; cin >> pageCount;
    cout << "Publication year: "; cin >> year;
    Book temp(title, author, available, ISBN, pageCount, year);

    while(storage[i].getTitle() != "Null")
    {
        i++;
    }
    storage[i] = temp;
    cout << "NEW BOOK HAS BEEN ADDED SUCCESSFULLY!" << endl;
}

void addItem(Magazine *storage)
{
    string title, author, available = "Available", subs, freq, content; int i = 0;
    cout << "Adding a new Magazine to Library Databases:" << endl;
    cout << "Magazine Title: "; cin.ignore(); getline(cin, title);
    cout << "Author's Name: "; getline(cin, author);
    cout << "Subscription Duration: "; getline(cin, subs);
    cout << "Frequency of Pubication: "; getline(cin, freq);
    cout << "Content/Theme: "; getline(cin, content);

    Magazine temp(title, author, available, subs, freq, content);

    while(storage[i].getTitle() != "Null")
    {
        i++;
    }
    storage[i] = temp;
    cout << "NEW MAGAZINE HAS BEEN ADDED SUCCESSFULLY!" << endl;
}

void addItem(Newspaper *storage)
{
    string title, author, available = "Available", publicFrequency, local, topic; int i = 0;
    cout << "Adding a new Newspaper to Library Databases:" << endl;
    cout << "Newspaper Title: "; cin.ignore(); getline(cin, title);
    cout << "Author's Name: "; getline(cin, author);
    cout << "Frequency of Pubication: "; getline(cin, publicFrequency);
    cout << "Local/Internaional: "; getline(cin, local);
    cout << "Topic/Theme: "; getline(cin, topic);

    Newspaper temp(title, author, available, publicFrequency, local, topic);

    while(storage[i].getTitle() != "Null")
    {
        i++;
    }
    storage[i] = temp;
    cout << "NEW NEWSPAPER HAS BEEN ADDED SUCCESSFULLY!" << endl;
}

//TABLE
void bookHeader()
{
    layout(112);
    cout << left << setw(55) << "|" << "BOOK" << right << setw(55) << "|" << endl;
    layout(112);
    cout << left << setw(30) << "| TITLE" << "   | " << setw(18)
    << "AUTHOR" << " | " << setw(15)
    << "AVAILABLE" << " | " << setw(15)
    << "ISBN" << " | " << setw(10)
    << "PAGES" << " | " << setw(8)
    << "YEAR" << "|"<< endl;
    layout(112);
}

void bookColumn(Book *bookStorage, int i)
{
    cout << "| " << left << setw(30) << bookStorage[i].getTitle() << " | " << setw(18)
    << bookStorage[i].getAuthor() << " | " << setw(15)
    << bookStorage[i].getAvailable() << " | " << setw(15)
    << bookStorage[i].getISBN() << " | " << setw(10)
    << bookStorage[i].getPageCount() << " | " << setw(8)
    << bookStorage[i].getPublicationYear() << "|" << endl;
}

void magazineHeader()
{
    layout(120);
    cout << left << setw(57) << "|" << "MAGAZINE" << right << setw(57) << "|" << endl;
    layout(120);
    cout << left << setw(30) << "| TITLE" << "   | " << setw(18)
        << "AUTHOR" << " | " << setw(15)
        << "AVAILABLE" << " | " << setw(15)
        << "SUBSCRIPTION" << " | " << setw(10)
        << "FREQUENCY" << " | " << setw(16)
        << "CONTENT" << "|"<< endl;
    layout(120);
}

void magazineColumn(Magazine *magazineStorage, int i)
{
    cout << "| " << left << setw(30) << magazineStorage[i].getTitle() << " | " << setw(18)
    << magazineStorage[i].getAuthor() << " | " << setw(15)
    << magazineStorage[i].getAvailable() << " | " << setw(15)
    << magazineStorage[i].getSubscriptionDuration() << " | " << setw(10)
    << magazineStorage[i].getFrequencyOfPublication() << " | " << setw(16)
    << magazineStorage[i].getContent() << "|" << endl;
    i++;
}

void newspaperHeader()
{
    layout(123);
    cout << left << setw(59) << "|" << "Newspaper" << right << setw(57) << "|" << endl;
    layout(123);
    cout << left << setw(30) << "| TITLE" << "   | " << setw(18)
        << "AUTHOR" << " | " << setw(15)
        << "AVAILABLE" << " | " << setw(15)
        << "FREQUENCY" << " | " << setw(15)
        << "LOCAL" << " | " << setw(14)
        << "TOPIC" << "|"<< endl;
    layout(123);
}

void newspaperColumn(Newspaper *newspaperStorage, int i)
{
    cout << "| " << left << setw(30) << newspaperStorage[i].getTitle() << " | " << setw(18)
    << newspaperStorage[i].getAuthor() << " | " << setw(15)
    << newspaperStorage[i].getAvailable() << " | " << setw(15)
    << newspaperStorage[i].getPublicationFrequency() << " | " << setw(15)
    << newspaperStorage[i].isLocal() << " | " << setw(14)
    << newspaperStorage[i].getTopic() << "|" << endl;
}
