#include"Sales_data.h"
#include<iostream>

using namespace std;

int main()
{
	Sales_data cp5("C++ Primer 5th", 4, 106.5);
	cout << cp5 << endl;
	cout << static_cast<string>(cp5) << endl;
	cout << static_cast<double>(cp5) << endl;

	system("pause");
	return 0;
}