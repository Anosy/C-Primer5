#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	cout << "类型名称\t" << "所占的空间" << endl;
	cout << "bool\t\t" << sizeof(bool) << endl;
	cout << "char\t\t" << sizeof(char) << endl;
	cout << "short\t\t" << sizeof(short) << endl;
	cout << "int\t\t" << sizeof(int) << endl;
	cout << "long\t\t" << sizeof(long) << endl;
	cout << "long long\t" << sizeof(long long) << endl;
	cout << "float\t\t" << sizeof(float) << endl;
	cout << "double\t\t" << sizeof(double) << endl;

	system("pause");
	return 0;
}