#include<iostream>
#include<string>
#include "Sales_data.h"

using namespace std;

int main()
{
	cout << "请输入交易记录(ISBN, 销售量，售价)" << endl;
	Sales_data total;
	if (read(cin, total))
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				add(total, trans);
			}
			else
			{
				print(cout, total);
				cout << endl;
				total = trans;
			}
		}
		print(cout, total);
		cout << endl;
	}
	else
	{
		cerr << "没有数据!" << endl;
	}
	system("pause");
	return 0;
}