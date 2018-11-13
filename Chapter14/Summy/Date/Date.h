#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Date
{
	friend ostream& operator << (ostream &os, const Date & date);
	friend istream& operator >> (istream &is, Date &date);
	friend bool operator == (const Date &d1, const Date &d2);
	friend bool operator < (const Date &d1, const Date &d2);
	friend bool operator <= (const Date &d1, const Date &d2);
	friend bool operator > (const Date &d1, const Date &d2);
	friend bool operator >= (const Date &d1, const Date &d2);
public:
	Date() {};
	Date(int y, int m, int d) :year(y), month(m), day(d) {}
	Date & operator=(const string &);
private:
	int year, month, day;

};

ostream& operator << (ostream &os, const Date & date)
{
	const char sep = '\t';
	os << "year:" << date.year << sep << "month:" << date.month << sep << "day:" << date.day;
	return os;
}

istream& operator >> (istream &is, Date &date)
{
	is >> date.year >> date.month >> date.day;
	if (!is)
	{
		date = Date(0, 0, 0);
	}
	return is;
}

bool operator == (const Date &d1, const Date &d2)
{
	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

bool operator < (const Date &d1, const Date &d2)
{
	return (d1.year < d2.year) || (d1.year == d2.year && d1.month < d2.month) || (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day);
}

bool operator <= (const Date &d1, const Date &d2)
{
	return d1 < d2 || d1 == d2;
}

bool operator > (const Date &d1, const Date &d2)
{
	return !(d1 < d2);
}

bool operator >= (const Date &d1, const Date &d2)
{
	return (d1 > d2) || (d1 == d2);
}

Date & Date::operator=(const string &date)
{
	istringstream is(date);
	if (is)
	{
		is >> year >> month >> day;
	}
	return *this;
}

