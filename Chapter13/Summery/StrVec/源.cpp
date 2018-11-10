#include<iostream>
#include"StrVec.h"

int main()
{
	StrVec strvec1;
	StrVec strvec2 = { "haha", "lala" };
	StrVec strvec3 = strvec1;
	StrVec strvec4(std::move(strvec1));

	StrVec strvec5, strvec6;
	strvec5 = strvec4;
	strvec6 = move(strvec1);

	cout << "strvec2 size:" << strvec2.size() << endl;
	strvec2.resize(10);
	cout << "strvec2 size:" << strvec2.size() << endl;

	cout << "strvec2 capacity:" << strvec2.capacity() << endl;
	strvec2.reserve(20);
	cout << "strvec2 capacity:" << strvec2.capacity() << endl;




	system("pause");
	return 0;
}