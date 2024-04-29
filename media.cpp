#include <iostream>
#include "media.h"
#include <string>
using namespace std;

//Define method of base class: Media
void Media::setTitle(string title)
{
    this->title = title;
}

void Media::setAuthor(string author)
{
    this->author = author;
}

void Media::setAvailable(string available)
{
    this->available = available;
}

string Media::getTitle()
{
    return title;
}

string Media::getAuthor()
{
    return author;
}

bool Media::returnItem()
{
    if(available == "Available")
        return true;
    else
        return false;
}

bool Media::checkOut()
{
    if(available == "Available")
    {
        
        return true;
    }
    else
    {
        
        return false;
    }
}

void Media::information()
{
    cout << title << "  " << author << "  " << available << endl;
}

//Define method of derived class: Book
string Book::getISBN()
{
    return ISBN;
}

int Book::getPageCount()
{
    return pageCount;
}

int Book::getPublicationYear()
{
    return publicationYear;
}

string Book::getAvailable()
{
    return available;
}

void Book::setPublicationYear(int year)
{
    this->publicationYear = year;
}

void Book::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

void Book::setPageCount(int page)
{
    this->pageCount = page;
}

void Book::information()
{
    cout << title << "  " << author << "  " << available << ISBN << "  " << pageCount << "  " << "  " << publicationYear << endl;
}

//Define method of derived class: Magazine
string Magazine::getSubscriptionDuration()
{
    return subsciptionDuration;
}

string Magazine::getFrequencyOfPublication()
{
    return frequencyOfPublication;
}

string Magazine::getAvailable()
{
    return available;
}

string Magazine::getContent()
{
    return content;
}

void Magazine::updateContent(string content)
{
    this->content = content;
}

void Magazine::information()
{
    cout << title << "  " << author << "  " << available << "  " << subsciptionDuration << "  " << frequencyOfPublication << "  " << content << endl;
}

//Define method of derived class: Newspaper
string Newspaper::getPublicationFrequency()
{
    return publicFrequency;
}

string Newspaper::getTopic()
{
    return topic;
}

string Newspaper::getAvailable()
{
    return available;
}

string Newspaper::isLocal()
{
    return local;
}

void Newspaper::information()
{
    cout << title << "  " << author << "  " << available << "  " << publicFrequency << "  " << local << endl;

}
