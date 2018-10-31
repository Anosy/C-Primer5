#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"Sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data & item1, const Sales_data &item2)
{
	return item1.isbn() < item2.isbn();
}


int main()
{
	vector<Sales_data> vct;
	Sales_data item1("0-E", 15, 16);
	Sales_data item2("0-C", 15, 16);
	Sales_data item3("0-B", 15, 16);
	Sales_data item4("0-D", 15, 16);
	Sales_data item5("0-A", 15, 16);
	Sales_data item6("0-F", 15, 16);

	vct.push_back(item1);
	vct.push_back(item2);
	vct.push_back(item3);
	vct.push_back(item4);
	vct.push_back(item5);
	vct.push_back(item6);

	sort(vct.begin(), vct.end(), compareIsbn);

	for (const auto &v : vct)
	{
		print(cout, v);
		cout << endl;
	}

	system("pause");
	return 0;
}
