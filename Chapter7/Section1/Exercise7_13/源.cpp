#include<iostream>
#include<string>
#include "Sales_data.h"

using namespace std;

int main()
{
	cout << "���������ۼ�¼��" << endl;
	Sales_data total(cin);  // ʹ�õ����ֹ��캯��
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
		cerr << "û����������" << endl;
	}

	system("pause");
	return 0;
}