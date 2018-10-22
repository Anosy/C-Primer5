#include<string>
#include<iostream>

struct Person
{
	// ���캯��
	Person() = default; // Ĭ�Ϲ��캯��
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