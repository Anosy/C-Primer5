#include"Sales_data.h"

using namespace std;

int main()
{
	Sales_data total;
	ifstream in("data/add_item"); // ��ȡ�ļ��ĵ�ַ
	ofstream out("data/write_item", ofstream::app);  // �����ļ��ĵ�ַ
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
		cerr << "û�����ݣ�" << endl;
	}

	return 0;
}