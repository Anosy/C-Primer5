#include<string>
#include<iostream>

class Book
{
public:
	Book() = default;
	Book(const std::string &n, const std::string &i, const std::string &a):
		Name(n), ISBN(i), Author(a){}

private:
	std::string Name, ISBN, Author;
};