#include<iostream>	
#include<string>
using std::cin;
using std::cout;
using std::endl;

struct Sales_item
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_item data1, data2;

	double price = 0;
	unsigned totalCnt = 0;
	double totalRevenue = 0.0;
	if (std::cin >> data1.bookNo >> data1.units_sold >> price)
	{
		data1.revenue = data1.units_sold  * price;
		while (std::cin >> data2.bookNo >> data2.units_sold >> price)
		{
			data2.revenue = data2.units_sold  * price;
			if (data1.bookNo == data2.bookNo)
			{
				totalCnt = data1.units_sold + data2.units_sold;  // 总销售的数量
				totalRevenue = data1.revenue + data2.revenue;
			}
			else
			{
				std::cerr << "Data must refer to the same ISBN" << std::endl;
				system("pause");
				return -1;
			}
		}
		std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue
			<< " " << totalRevenue / totalCnt << " " << std::endl;
		system("pause");
		return 0;
	}
	else
	{
		std::cout << "no data" << std::endl;
		system("pause");
		return -1;
	}
}