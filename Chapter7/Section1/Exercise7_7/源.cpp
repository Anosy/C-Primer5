#include<iostream>
#include<string>
#include "Sales_data.h"

using namespace std;

int main()
{
	cout << "�����뽻�׼�¼(ISBN, ���������ۼ�)" << endl;
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
		cerr << "û������!" << endl;
	}
	system("pause");
	return 0;
}