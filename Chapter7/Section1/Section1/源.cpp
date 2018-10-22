#include<iostream>
#include "Sales_data.h"
#include<string>

using namespace std;

int main()
{
	Sales_data total;
	
	total.bookNo = "0-A";
	total.units_sold = 15;
	total.revenue = 8.8;
	
	if (total.bookNo != " ")
	{
		Sales_data trans;
		trans.bookNo = "0-A";
		trans.units_sold = 10;
		trans.revenue = 8.8;

		if (total.bookNo == trans.bookNo)
		{
			total.units_sold += trans.units_sold;
		}
		else
		{
			cout << total.units_sold * total.revenue << endl;
			total.units_sold = trans.units_sold;
			return -1;
		}
		cout << total.units_sold * total.revenue << endl;
	}
	else
	{
		cerr << "没有销售记录！" << endl;
		return -1;
	}

	system("pause");
	return 0;
}