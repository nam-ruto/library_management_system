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
void displayBooks(Book *bookStorage, int);
void displayMagazine(Magazine *magazineStorage, int);
void displayNewspaper(Newspaper *newspaperStorage, int);

//TASK 2: SEARCH MATERIALS
void search();

void layout(int n); //Layout: Display the lines around

fstream myFile; //Initialize fstream: Reading data from text file

int main()
{
    int numBooks = 10, numMaga = 10, numNews = 10;
    Book bookStorage[numBooks];
    Magazine magazineStorage[numMaga];
    Newspaper newspaperStorage[numNews];

    inputBookData(bookStorage);
    inputMagazineData(magazineStorage);
    inputNewspaperData(newspaperStorage);

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
            displayNewspaper(newspaperStorage, numNews);
        }

        else if(option == "2")
        {
            
        }

        else if(option == "6")
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

//DISPLAY DATABASES
void displayBooks(Book *bookStorage, int numBooks)
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
    for(int i = 0; i < numBooks; i++)
    {
        cout << "| " << left << setw(30) << bookStorage[i].getTitle() << " | " << setw(18)
        << bookStorage[i].getAuthor() << " | " << setw(15)
        << bookStorage[i].getAvailable() << " | " << setw(15)
        << bookStorage[i].getISBN() << " | " << setw(10)
        << bookStorage[i].getPageCount() << " | " << setw(8)
        << bookStorage[i].getPublicationYear() << "|" << endl;
    }
    layout(112);
}

void displayMagazine(Magazine *magazineStorage, int numMaga)
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
    for(int i = 0; i < numMaga; i++)
    {
        cout << "| " << left << setw(30) << magazineStorage[i].getTitle() << " | " << setw(18)
        << magazineStorage[i].getAuthor() << " | " << setw(15)
        << magazineStorage[i].getAvailable() << " | " << setw(15)
        << magazineStorage[i].getSubscriptionDuration() << " | " << setw(10)
        << magazineStorage[i].getFrequencyOfPublication() << " | " << setw(16)
        << magazineStorage[i].getContent() << "|" << endl;
    }
    layout(120);
}

void displayNewspaper(Newspaper *newspaperStorage, int numNews)
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
    for(int i = 0; i < numNews; i++)
    {
        cout << "| " << left << setw(30) << newspaperStorage[i].getTitle() << " | " << setw(18)
        << newspaperStorage[i].getAuthor() << " | " << setw(15)
        << newspaperStorage[i].getAvailable() << " | " << setw(15)
        << newspaperStorage[i].getPublicationFrequency() << " | " << setw(15)
        << newspaperStorage[i].isLocal() << " | " << setw(14)
        << newspaperStorage[i].getTopic() << "|" << endl;
    }
    layout(123);
}

void layout(int n)
{
    ios init(NULL);
    init.copyfmt(cout);
    cout << "+" << setw(n) << setfill('-') << "" << "+" << endl;
    cout.copyfmt(init); // Reset fill character to the defaultcout << "----------------------------------------------------\n";
}