#include<string>
#include<iostream>

struct Person
{
	std::string strName;
	std::string strAddress;

	std::string getName() const { return strName; }
	std::string getAddress() const { return strAddress; }
};

std::istream &read(std::istream &is, Person &ps)
{
	is >> ps.strName >> ps.strAddress;
	return is;
}

std::ostream &print(std::ostream &os, const Person &ps)
{
	os << ps.getName << " " << ps.getAddress;
	return os;
}