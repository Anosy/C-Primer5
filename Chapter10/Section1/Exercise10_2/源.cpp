#include<algorithm>
#include<list>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	list<string> lStr = {"one", "one", "two", "three"};
	auto beg = lStr.begin();
	auto result = count(lStr.begin(), lStr.end(), "one");
	cout << "���ֵĴ���Ϊ��" << result << endl;

	system("pause");
	return 0;
}