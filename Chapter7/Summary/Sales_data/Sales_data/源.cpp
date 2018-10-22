#include"Sales_data.h"

using namespace std;

int main()
{
	cout << "请输入销售记录：" << endl;
	Sales_data item1;
	if (read(cin, item1))
	{
		Sales_data item2;
		while (read(cin, item2))
		{
			if (item1.isbn() == item2.isbn())
			{
				item1.combine(item2);
			}
			else
			{
				print(cout, item1);
				cout << endl;
				item1 = item2;
			}
		}
		print(cout, item1);
		cout << endl;
	}
	else
	{
		cerr << "没有输入数据！" << endl;
	}

	system("pause");
	return 0;
}