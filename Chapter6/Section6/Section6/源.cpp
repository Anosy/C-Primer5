#include<iostream>
#include<string>

using namespace std;

bool lengthCompare(const string &, const string &);

// pf指向一个函数，该函数的参数是两个const引用，返回值是bool类型
bool(*pf)(const string &, const string &);


int main()
{
	pf = lengthCompare;
}