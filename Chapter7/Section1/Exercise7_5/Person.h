#include<string>

struct Person
{
	std::string strName;
	std::string strAddress;

	std::string getName() const { return strName; }
	std::string getAddress() const { return strAddress; }
};