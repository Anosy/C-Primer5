#include<iostream>
#include<string>
#include "Sales_data.h"

using namespace std;

int main()
{
	cout << "请输入销售记录：" << endl;
	Sales_data total(cin);  // 使用第四种构造函数
	if (cin)
	{
		Sales_data trans(cin);
		do
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total);
				cout << endl;
				total = trans;
			}
		} while (read(cin, trans));
		print(cout, total);
		cout << endl;
	}
	else
	{
		cerr << "没有输入数据" << endl;
	}

	system("pause");
	return 0;
}