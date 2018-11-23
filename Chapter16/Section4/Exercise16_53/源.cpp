#include<iostream>
#include<string>

using namespace std;

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

int main()
{
	int i = 0;
	string s = "hello";
	
	print(cout, i, s, "good", 42);
	
	system("pause");
	return 0;
}