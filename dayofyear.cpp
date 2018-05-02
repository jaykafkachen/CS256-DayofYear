#include "stdafx.h"
#include <stdlib.h> 
#include <string>
#include <iostream>
	using namespace std;

class dayofyear {
public:
	dayofyear(int day);	// constructor with initial values for day or passed values
	dayofyear(string month, int day);
	void setDay(int day);  // set values for dayofyear
	void getDay();  // get day from keyboard
	void print();
	
	//in/decrement
	dayofyear operator++();
	dayofyear operator++(int);
	dayofyear operator--();
	dayofyear operator--(int);

private:
	int myDay;
	string myMonth;
	int daysInMonth(int month);
	string months[12] = {"January","February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"};
};

dayofyear::dayofyear(int day)
{
	myDay = day;
}

dayofyear::dayofyear(string month, int day)
{
	myMonth = month;
	myDay = day;
}

dayofyear::dayofyear(const dayofyear &temp)
{
	myDay = temp.myDay;
}

dayofyear dayofyear::operator++()
{
	myDay++;
	return *this;
}

dayofyear dayofyear::operator++(int)
{
	dayofyear temp = *this;
	++(*this);
	return temp;
}

dayofyear dayofyear::operator--()
{
	myDay--;
	return *this;
}

dayofyear dayofyear::operator--(int)
{
	dayofyear temp = *this;
	--(*this);
	return temp;
}

void dayofyear::setDay(int day)
{
	myDay = day;
}

int dayofyear::daysInMonth(int month)
{
	if ((month % 2 != 0 && month <= 7) || (month % 2 == 0 && month > 7))
		return 31;
	else if (month != 2)
		return 30;
	else if (month == 2)
	{
		return 28;
	}
	return -1;
}

void dayofyear::getDay()
{
	int d=0;
	do
	{
		cout << "Enter day between 1-365: \n";
		cin >> d;
		if (d < 1 || d>365)
			cout << "";
	} while (d < 1 || d>365);
	myDay = d;
}

void dayofyear::print()
{
	int month = myDay / 30;
	string mo = months[month-1];
	int day = myDay;

	while (day > daysInMonth(month))
	{
		day -= daysInMonth(month);
		month = day / 30;
	}
	cout << mo << " " << day << endl;
}

int main()
{
	dayofyear day(0);
	day.getDay();
	day.print();
	return 0;
}
