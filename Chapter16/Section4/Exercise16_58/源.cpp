#include"Vec.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	Vec<string> v = {"a", "b"};
	v.emplace_back(5, 'c');
	for (auto c : v)
		cout << c << " ";
	cout << endl;

	system("pause");
	return 0;
}