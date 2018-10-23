#include"Sales_data.h"

using namespace std;

int main()
{
	Sales_data total;
	ifstream in("data/add_item");
	if (read(in, total))
	{
		Sales_data trans;
		while (read(in, trans))
		{
			if (total.isbn()==trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;

	}
	else
	{
		cerr << "没有数据！" << endl;
	}

	system("pause");
	return 0;
}