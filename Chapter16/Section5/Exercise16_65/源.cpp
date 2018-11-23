#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <typename T> string debug_rep(const T &t);
template <typename T> string debug_rep(T *p);


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

template <>
string debug_rep(const char * const &t)
{
	return debug_rep(string(t));
}

template <>
string debug_rep(char * const &t)
{
	return debug_rep(string(t));
}

int main()
{
	const char * w = "hello";
	cout << debug_rep(w) << endl;
	cout << endl;

	system("pause");
	return 0;
}