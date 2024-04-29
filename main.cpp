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

//TASK 2: SEARCH MATERIALS
void searchBook(string, Book *bookStorage);
void searchMagazine(string, Magazine *magazineStorage);
void searchNewspaper(string, Newspaper *newspaperStorage);

void layout(int n); //Layout: Display the lines around

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
        cout << "LIBRARY MANAGEMENT SYSTEM\n";
        cout << "1: Display library databases\n";
        cout << "2: Search available items \n";
        cout << "3: Check out items\n";
        cout << "4: Return items\n";
        cout << "5: Exit program\n";

        cout << "Input your option (1-5): ";
        cin >> option;

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
            cout << "Search by:"; cin >> category;
            cout << "Search by (1) TITLE or (2) AUTHOR: "; cin >> subCategory;

            if(category == "1") searchBook(subCategory, bookStorage);
            else if(category == "2") searchMagazine(subCategory, magazineStorage);
            else if(category == "3") searchNewspaper(subCategory, newspaperStorage);
            else cout << "Invalid input. Please try again" << endl;
        }

        else if(option == "3")
        {
            string name;
            bool found = false;
            int i = 0, j = 0, k = 0;
            cout << "Input Item's Title you want to check-out: "; cin.ignore(); getline(cin, name);

            // GO OVER THIS ONEEEEEE!
            while(bookStorage[i].getTitle() != "Null" && found == false)
            {
                if(bookStorage[i].getTitle() == name)
                {
                    found = true;
                    if(bookStorage[i].checkOut())
                    {
                        cout << "Item currently is AVAILABLE" << endl;
                        cout << "You've checked out SUCCESSFULLY!" << endl;
                    }
                    else
                    {
                        cout << "Item currently is UNAVAILABLE" << endl;
                        cout << "See you next time" << endl;
                    }
                }
                i++;
            }

            while(magazineStorage[i].getTitle() != "Null" && found == false)
            {
                if(magazineStorage[i].getTitle() == name)
                {
                    found = true;
                    if(magazineStorage[i].checkOut())
                    {
                        cout << "Item currently is AVAILABLE" << endl;
                        cout << "You've checked out SUCCESSFULLY!" << endl;
                    }
                    else
                    {
                        cout << "Item currently is UNAVAILABLE" << endl;
                        cout << "See you next time" << endl;
                    }
                }
            }

            while(newspaperStorage[i].getTitle() != "Null" && found == false)
            {
                if(newspaperStorage[i].getTitle() == name)
                {
                    found = true;
                    if(newspaperStorage[i].checkOut())
                    {
                        cout << "Item currently is AVAILABLE" << endl;
                        cout << "You've checked out SUCCESSFULLY!" << endl;
                    }
                    else
                    {
                        cout << "Item currently is UNAVAILABLE" << endl;
                        cout << "See you next time" << endl;
                    }
                }
            }

            if(found == false)
            {
                cout << "DATA NOT FOUND" << endl;
            }
        }

        else if(option == "4")
        {

        }

        else if(option == "5")
        {
            cout << "Exit program...";
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

//TASK 2: SEARCH DATABASES
void searchBook(string subCategory, Book *bookStorage)
{
    //subCategory == "1" --> Search by Title
    //subCategory == "2" --> Search by Author
    bool found = false;
    if(subCategory == "1")
    {
        string titleName;
        cout << "Input title book you want to find: "; 
        cin.ignore(); getline(cin, titleName);
        int i = 0;
        while(bookStorage[i].getTitle() != "Null")
        {
            if(bookStorage[i].getTitle() == titleName)
            {
                cout << "| " << left << setw(30) << bookStorage[i].getTitle() << " | " << setw(18)
                << bookStorage[i].getAuthor() << " | " << setw(15)
                << bookStorage[i].getAvailable() << " | " << setw(15)
                << bookStorage[i].getISBN() << " | " << setw(10)
                << bookStorage[i].getPageCount() << " | " << setw(8)
                << bookStorage[i].getPublicationYear() << "|" << endl;
                found = true;
            }
            i++;
        }
    }

    else if(subCategory == "2")
    {
        string authorName;
        cout << "Input Author's name you want to find: "; 
        cin.ignore(); getline(cin, authorName);
        int i = 0;
        while(bookStorage[i].getTitle() != "Null")
        {
            if(bookStorage[i].getAuthor() == authorName)
            {
                cout << "| " << left << setw(30) << bookStorage[i].getTitle() << " | " << setw(18)
                << bookStorage[i].getAuthor() << " | " << setw(15)
                << bookStorage[i].getAvailable() << " | " << setw(15)
                << bookStorage[i].getISBN() << " | " << setw(10)
                << bookStorage[i].getPageCount() << " | " << setw(8)
                << bookStorage[i].getPublicationYear() << "|" << endl;
                found = true;
            }
            i++;
        }
    }

    if(found == false)
        cout << "DATA NOT FOUND" << endl;
}

void searchMagazine(string subCategory, Magazine *magazineStorage)
{
    //subCategory == "1" --> Search by Title
    //subCategory == "2" --> Search by Author
    bool found = false;
    if(subCategory == "1")
    {
        string titleName;
        cout << "Input Magazine's Title you want to find: "; 
        cin.ignore(); getline(cin, titleName);
        int i = 0;
        while(magazineStorage[i].getTitle() != "Null")
        {
            if(magazineStorage[i].getTitle() == titleName)
            {
                cout << "| " << left << setw(30) << magazineStorage[i].getTitle() << " | " << setw(18)
                << magazineStorage[i].getAuthor() << " | " << setw(15)
                << magazineStorage[i].getAvailable() << " | " << setw(15)
                << magazineStorage[i].getSubscriptionDuration() << " | " << setw(10)
                << magazineStorage[i].getFrequencyOfPublication() << " | " << setw(8)
                << magazineStorage[i].getContent() << "|" << endl;
                found = true;
            }
            i++;
        }
    }

    else if(subCategory == "2")
    {
        string authorName;
        cout << "Input Author's Name you want to find: "; 
        cin.ignore(); getline(cin, authorName);
        int i = 0;
        while(magazineStorage[i].getTitle() != "Null")
        {
            if(magazineStorage[i].getAuthor() == authorName)
            {
                cout << "| " << left << setw(30) << magazineStorage[i].getTitle() << " | " << setw(18)
                << magazineStorage[i].getAuthor() << " | " << setw(15)
                << magazineStorage[i].getAvailable() << " | " << setw(15)
                << magazineStorage[i].getSubscriptionDuration() << " | " << setw(10)
                << magazineStorage[i].getFrequencyOfPublication() << " | " << setw(8)
                << magazineStorage[i].getContent() << "|" << endl;
                found = true;
            }
            i++;
        }
    }

    if(found == false)
        cout << "DATA NOT FOUND" << endl;
}

void searchNewspaper(string subCategory, Newspaper *newspaperStorage)
{
    //subCategory == "1" --> Search by Title
    //subCategory == "2" --> Search by Author
    bool found = false;
    if(subCategory == "1")
    {
        string titleName;
        cout << "Input Magazine's Title you want to find: "; 
        cin.ignore(); getline(cin, titleName);
        int i = 0;
        while(newspaperStorage[i].getTitle() != "Null")
        {
            if(newspaperStorage[i].getTitle() == titleName)
            {
                cout << "| " << left << setw(30) << newspaperStorage[i].getTitle() << " | " << setw(18)
                << newspaperStorage[i].getAuthor() << " | " << setw(15)
                << newspaperStorage[i].getAvailable() << " | " << setw(15)
                << newspaperStorage[i].getPublicationFrequency() << " | " << setw(15)
                << newspaperStorage[i].isLocal() << " | " << setw(14)
                << newspaperStorage[i].getTopic() << "|" << endl;
                found = true;
            }
            i++;
        }
    }

    else if(subCategory == "2")
    {
        string authorName;
        cout << "Input Author's Name you want to find: "; 
        cin.ignore(); getline(cin, authorName);
        int i = 0;
        while(newspaperStorage[i].getTitle() != "Null")
        {
            if(newspaperStorage[i].getAuthor() == authorName)
            {
                cout << "| " << left << setw(30) << newspaperStorage[i].getTitle() << " | " << setw(18)
                << newspaperStorage[i].getAuthor() << " | " << setw(15)
                << newspaperStorage[i].getAvailable() << " | " << setw(15)
                << newspaperStorage[i].getPublicationFrequency() << " | " << setw(15)
                << newspaperStorage[i].isLocal() << " | " << setw(14)
                << newspaperStorage[i].getTopic() << "|" << endl;
                found = true;
            }
            i++;
        }
    }

    if(found == false)
        cout << "DATA NOT FOUND" << endl;
}