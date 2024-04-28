#ifndef media_H
#define media_H
#include <string>

using namespace std;

// BASE CLASS: Media
class Media
{
	protected:
		string title;
		string author;
		string available;
	public:
		// Default Constructor
		Media() : title("Null"), author("Null"), available("Null") {}

		// Parameterized Constructor
		Media(string title, string author, string available)
			: title(title), author(author), available(available) {}

		// Mutator
		void setTitle(string title);
		void setAuthor(string author);
		void setAvailable(string available);

		//Accessor
		string getTitle();
		string getAuthor();

		//Return Item method: updating the item's status as 'available'
		bool returnItem();

		//Check-out method: updating the item's status as 'checked out'
		bool checkOut();

		//Polymorphism: This can be override by derived class
		void virtual information();
};

//Derived class: Book
class Book : public Media
{
	private:
		string ISBN;
		int pageCount;
		int publicationYear;
	public:
		//Default constructor
		Book() : ISBN("N/A"), pageCount(0), publicationYear(0000) {}

		//Parameterize constructor
		Book(string title, string author, string available, string ISBN, int pageCount, int year) 
			: ISBN(ISBN), pageCount(pageCount), publicationYear(year)
			{
				setTitle(title);
				setAuthor(author);
				setAvailable(available);
			}

		//Mutator
		void setISBN(string ISBN);
		void setPageCount(int page);
		void setPublicationYear(int year);

		//Accessor
		string getISBN();
		string getAvailable();
		int getPageCount();
		int getPublicationYear();

		//Override method
		void virtual information();
};

//Derived class: Magazine
class Magazine : public Media
{
	private:
		string subsciptionDuration; //Jan, Feb, March,...
		string frequencyOfPublication; //Daily, Weekly, Montly
		string content;
	public:
		//Default constructor
		Magazine() : subsciptionDuration("January"), frequencyOfPublication("Daily"), content("Education") {}

		//Parameterized constructor
		Magazine(string title, string author, string available, string subs, string freq, string content)
			: subsciptionDuration(subs), frequencyOfPublication(freq), content(content)
			{
				setTitle(title);
				setAuthor(author);
				setAvailable(available);
			}

		//Accessor
		string getSubscriptionDuration();
		string getFrequencyOfPublication();
		string getAvailable();
		string getContent();

		//Update - Edit content
		void updateContent(string content);

		//Override method
		void virtual information();
};

//Derived class: Newspaper
class Newspaper : public Media
{
	private:
		string publicFrequency;
		string local;
		string topic;
	public:
		//Default constructor
		Newspaper() : publicFrequency("Daily"), local("Local"){}
		//Constructor
		Newspaper(string title, string author, string available, string freq, string local, string topic)
			: publicFrequency(freq), local(local), topic(topic)
			{
				setTitle(title);
				setAuthor(author);
				setAvailable(available);
			}

		//Returns the frequency of publication for a newspaper (e.g., daily, weekly, monthly)
		string getPublicationFrequency();

		//Return topic of the newspaper
		string getTopic();

		//Determines whether a newspaper is focused on local news
		string isLocal();

		string getAvailable();

		//Allows an article to be published in a specific section or topic of a newspaper
		void publishArticle();

		//Override method
		void virtual information();
};

#endif