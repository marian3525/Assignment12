#pragma once
#include <string>
using namespace std;

class Tutorial {
private:
	string title;
	string presenter;
	int duration; //in seconds
	int likes;
	std::string link;  //link to the resource
public:
	void setPresenter(string presenter);

	void setDuration(int duration);

	void setLikes(int likes);
	void incLikes();

	void setLink(string link);

	const string toString() const;

	string getFormattedDuration();
	//default constructor
	Tutorial(string title, string presenter, int duration, int likes, string link);

	//copy constructor
	Tutorial(const Tutorial& t);

	//destructor
	~Tutorial();

	bool operator==(const Tutorial& tutorial);
	Tutorial& operator=(const Tutorial& tutorial);
	string getTitle()const;
	string getPresenter()const;
	int getDuration()const;
	int getLikes()const;
	string getLink()const;

	friend istream& operator>>(istream& stream, Tutorial& tutorial);
	friend ostream& operator<<(ostream& stream, const Tutorial& tutorial);

};