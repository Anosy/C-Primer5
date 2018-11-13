#include<string>
#include<iostream>

using namespace std;

class PrintString {
public:
	PrintString(ostream &o = cout, char c = ' ') :os(o), sep(c) {}
	void operator() (const string &s) const { os << s << sep; }

private:
	ostream &os;
	char sep;
};

class ReadString
{
public:
	ReadString(istream &i = cin) :is(i) {}
	std::string operator()() 
	{
		string line;
		if (!getline(is, line))
		{
			line = " ";
		}
		return line;
	}

private:
	istream &is;
};