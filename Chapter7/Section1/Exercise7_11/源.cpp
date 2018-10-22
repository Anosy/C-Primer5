#include<iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
	Sales_data data1;
	Sales_data data2("0-A");
	Sales_data data3("O-A", 10, 15);
	Sales_data data4(cin);

	cout << "书籍的销售情况是：" << endl;
	print(cout, data1);
	cout<<endl;
	print(cout, data2);
	cout << endl;
	print(cout, data3);
	cout << endl;
	print(cout, data4);
	cout << endl;

	system("pause");
	return 0;
}