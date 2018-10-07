#include<iostream>
#include<string>
#include "Sales_data.h"
using namespace std;
int main()
{
	Sales_data data1, data2;
	
	double price = 0;
	// 读入第一笔交易：ISBN、销售的数量、单价
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold  * price;

	cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold  * price;

	if (data1.bookNo==data2.bookNo)
	{
		unsigned totalCnt = data1.units_sold + data2.units_sold;  // 总销售的数量
		double totalRevenue = data1.revenue + data2.revenue;
		// 输出：ISBN、总销售量、总销售额、平均价格
		cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " " << endl;
		if (totalCnt !=0)
		{
			cout << totalRevenue / totalCnt << endl;
		}
		else
		{
			cout << "(no sales)"<<endl;
		}
		system("pause");

		return 0;
	}
	else
	{
		cerr << "Data must refer to the same ISBN" << endl;
		system("pause");
		return -1;
	}
}