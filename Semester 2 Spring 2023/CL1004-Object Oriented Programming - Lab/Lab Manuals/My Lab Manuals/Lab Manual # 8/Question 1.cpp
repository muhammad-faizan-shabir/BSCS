#include<iostream>
#include<string>
using namespace std;

class Time
{
	int hr;
	int min;
public:
	Time();
	Time(int, int);
	void setTime(int, int);
	void getTime(int&, int&);
	void printTime();
	void incrementHours();
	void incrementMinutes();
};

Time::Time()
{
	hr = 0;
	min = 0;
}

Time::Time(int h, int m)
{
	hr = h;
	min = m;
}

void Time::setTime(int h, int m)
{
	hr = h;
	min = m;
}

void Time::getTime(int &h, int &m)
{
	h = hr;
	m = min;
}

void Time::printTime()
{
	cout << "(Hour: " << hr << ") (Min: " << min<<")" << endl;
}

void Time::incrementHours()
{
	hr = hr + 1;
}

void Time::incrementMinutes()
{
	min = min + 1;
}

class Date
{
	int month;
	int day;
	int year;
public:
	Date();
	Date(int, int, int);
	void setDate(int,int,int);
	void getDate(int&, int&, int&);
	void printDate();
};

Date::Date()
{
	month = 0;
	day = 0;
	year = 0;
}

Date::Date(int m,int d ,int y)
{
	month = m;
	day = d;
	year = y;
}

void Date::setDate(int m,int d,int y)
{
	month = m;
	day = d;
	year = y;
}

void Date::getDate(int&m, int&d, int&y)
{
	m = month;
	d = day;
	y = year;
}

void Date::printDate()
{
	cout << "(Month: " << month << ") (Day: " << day << ") (Year: " << year <<")"<< endl;
}

class Event
{
	string eventName;
	Time eventTime;
	Date eventDate;
public:
	Event(int, int, int, int , int , string);
	void setEventData(int, int, int , int , int , string);
	void printEventData();
};

Event::Event(int hours=0, int minutes = 0, int m = 1, int d = 1, int y = 1900, string name = "Christmas")
{
	eventTime.setTime(hours, minutes);
	eventDate.setDate(m, d, y);
	eventName = name;
}

void Event::setEventData(int hours, int minutes, int m, int d, int y, string name)
{
	eventTime.setTime(hours, minutes);
	eventDate.setDate(m, d, y);
	eventName = name;
}

void Event::printEventData()
{
	cout << "Event Name: " << eventName << endl;
	eventTime.printTime();
	eventDate.printDate();
}

int main()
{
	//instantiate an object and set data for Christmas
	Event object;
	object.setEventData(6, 0, 12, 25, 2010, "Christmas");
	//print out the data for object
	object.printEventData();
	cout << endl << endl;
	
	//instantiate the second object and set data for the fourth of July
	Event object2;
	object2.setEventData(1, 15, 7, 4, 2010, "Fourth of July");
	//print out the data for the second object
	object2.printEventData();
	cout << endl << endl;
	
	system("pause");
	return 0;
}


