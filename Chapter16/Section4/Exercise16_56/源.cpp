#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <typename T> string debug_rep(const T &t)
{
	ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T> string debug_rep(T *p)
{
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
	{
		ret << " " << debug_rep(*p);
	}
	else
	{
		ret << "null pointer";
	}
	return ret.str();
}

template <typename T>
ostream &print(ostream &os, const T& t)
{
	os << t;
	return os;
}

template <typename T, typename ... Args>
ostream &print(ostream &os, const T &t, const Args& ...reset)
{
	os << t << ",";
	return print(os, reset...);
}

template <typename ... Args>
ostream &errorMsg(ostream &os, const Args& ... rest)
{
	return print(os, debug_rep(rest)...);
}

int main()
{
	string s = "good", *ip = &s;
	errorMsg(cerr, s, "hello", ip, 42);

	system("pause");
	return 0;
}
