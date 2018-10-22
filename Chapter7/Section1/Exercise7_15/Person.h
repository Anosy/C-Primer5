#include<string>
#include<iostream>

struct Person
{
	// 构造函数
	Person() = default; // 默认构造函数
	Person(const std::string &name, const std::string &add):strName(name), strAddress(add){}

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