#include<string>
#include<iostream>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &hp) :ps(new std::string(*hp.ps)) ,i(hp.i){ }
	HasPtr & operator=(const HasPtr &hp) 
	{ 
		auto newps = new std::string(*hp.ps);
		delete ps;
		ps = newps;
		i = hp.i;
		return *this;
	}
	~HasPtr() { delete ps; }

private:
	std::string *ps;
	int i;
};