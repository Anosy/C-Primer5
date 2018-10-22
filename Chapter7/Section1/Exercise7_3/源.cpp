#include<iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
	Sales_data total;
	total.bookNo = "0-A";
	total.units_sold = 10;
	total.revenue = 5;

	if (total.bookNo != "")
	{

		Sales_data trans;
		trans.bookNo = "0-B";
		trans.units_sold = 15;
		trans.revenue = 5;

		if (total.isbn() == trans.isbn())
		{
			total.combine(trans);
		}
		else
		{
			cout << total.bookNo << "的销售额为:";
			cout << total.units_sold * total.revenue << endl;
			total.bookNo = trans.bookNo;
			total.units_sold = trans.units_sold;
			total.revenue = trans.revenue;
		}
		cout << total.bookNo << "的销售额为:";
		cout << total.units_sold * total.revenue << endl;
	}
	else
	{
		cerr << "No data?" << endl;
		return -1;
	}
	system("pause");
	return 0;
}