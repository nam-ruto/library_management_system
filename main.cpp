#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "media.h"
using namespace std;

//Prototype
void inputBookData(Book *bookStorage);
void inputMagazineData(Magazine *magazineStorage);
void inputNewspaperData(Newspaper *newspaperStorage);

void displayBooks(Book *bookStorage, int);
void displayMagazine(Magazine *magazineStorage, int);
void displayNewspaper(Newspaper *newspaperStorage, int);

void layout(int n); //Layout: Display line around

fstream myFile; //Initialize fstream: Reading data from text file

int main()
{
    int numBooks = 10, numMaga = 10, numNews = 10;
    Book bookStorage[numBooks];
    Magazine magazineStorage[numMaga];
    Newspaper newspaperStorage[numNews];

    inputBookData(bookStorage);
    inputMagazineData(magazineStorage);
    // inputNewspaperData(newspaperStorage);

    string option;
    
    while(true)
    {
        cout << "LIBRARY MANAGEMENT SYSTEM\n";
        cout << "1: Display library databases\n";
        cout << "2: Search materials or documents \n";
        cout << "3: Checking material available\n";
        cout << "4: Return material\n";
        cout << "5: Update or Add meterials\n";
        cout << "6: Exit program\n";

        cout << "Input your option (1-6): ";
        cin >> option;

        if(option == "1")
        {
            displayBooks(bookStorage, numBooks);
            displayMagazine(magazineStorage, numMaga);
            
        }

        else if(option == "2")
        {cout << "Search";}

        else if(option == "6")
        {
            cout << "Exit program...";
            return 0;
        }
        else cout << "Invalid input. Please try again\n";
    }

    
    return 0;
}

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

            bookStorage[index].setTitle(title);
            bookStorage[index].setAuthor(author);
            bookStorage[index].setAvailable(available);
            bookStorage[index].setISBN(ISBN);
            bookStorage[index].setPageCount(pageCount);
            bookStorage[index].setPublicationYear(year);

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

void displayBooks(Book *bookStorage, int numBooks)
{
    //DISPLAY BOOK DATABASES
    layout(120);
    cout << left << setw(60) << "|" << "BOOK" << right << setw(58) << "|" << endl;
    layout(120);
    cout << left << setw(30) << "| TITLE" << "   | " << setw(25)
        << "AUTHOR" << " | " << setw(15)
        << "AVAILABLE" << " | " << setw(15)
        << "ISBN" << " | " << setw(10)
        << "PAGES" << " | " << setw(9)
        << "YEAR" << "|"<< endl;
    layout(120);
    for(int i = 0; i < numBooks; i++)
    {
        cout << "| " << left << setw(30) << bookStorage[i].getTitle() << " | " << setw(25)
        << bookStorage[i].getAuthor() << " | " << setw(15)
        << bookStorage[i].getAvailable() << " | " << setw(15)
        << bookStorage[i].getISBN() << " | " << setw(10)
        << bookStorage[i].getPageCount() << " | " << setw(9)
        << bookStorage[i].getPublicationYear() << "|" << endl;
    }
    layout(120);
}

void displayMagazine(Magazine *magazineStorage, int numMaga)
{
    // DISPLAY Magazine DATABASES
    layout(125);
    cout << left << setw(60) << "|" << "MAGAZINE" << right << setw(59) << "|" << endl;
    layout(125);
    cout << left << setw(30) << "| TITLE" << "   | " << setw(25)
        << "AUTHOR" << " | " << setw(15)
        << "AVAILABLE" << " | " << setw(15)
        << "SUBSCRIPTION" << " | " << setw(10)
        << "FREQUENCY" << " | " << setw(14)
        << "CONTENT" << "|"<< endl;
    layout(125);
    for(int i = 0; i < numMaga; i++)
    {
        cout << "| " << left << setw(30) << magazineStorage[i].getTitle() << " | " << setw(25)
        << magazineStorage[i].getAuthor() << " | " << setw(15)
        << magazineStorage[i].getAvailable() << " | " << setw(15)
        << magazineStorage[i].getSubscriptionDuration() << " | " << setw(10)
        << magazineStorage[i].getFrequencyOfPublication() << " | " << setw(14)
        << magazineStorage[i].getContent() << "|" << endl;
    }
    layout(125);
}

void layout(int n)
{
    ios init(NULL);
    init.copyfmt(cout);
    cout << "+" << setw(n) << setfill('-') << "" << "+" << endl;
    cout.copyfmt(init); // Reset fill character to the defaultcout << "----------------------------------------------------\n";
}