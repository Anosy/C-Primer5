#include"Sales_data.h"

using namespace std;

int main()
{
	Sales_data total;
	ifstream in("data/add_item"); // 读取文件的地址
	ofstream out("data/write_item");  // 保存文件的地址
	if (read(in, total))
	{
		Sales_data trans;
		while (read(in, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(out, total) << endl;
				total = trans;
			}
		}
		print(out, total) << endl;

	}
	else
	{
		cerr << "没有数据！" << endl;
	}

	return 0;
}