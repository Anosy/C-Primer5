#include"Sales_data.h"
#include<string>
#include<iostream>
#include<unordered_set>
#include<functional>

using std::size_t;
using std::string;
using std::cin; using std::cout; using	std::endl;
using std::unordered_multiset;

using std::hash;

namespace std
{
	template<>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator() (const Sales_data &s) const
		{
			return hash<string>() (s.bookNo) ^ hash<unsigned>() (s.units_sold) ^ hash<double>() (s.revenue);
		}
		
	};
}

int main()
{
	unordered_multiset<Sales_data> SDset;
	Sales_data item;
	while (cin >> item)
	{
		SDset.insert(item);
	}
	cout << SDset.size() << endl;
	for (auto sd : SDset)
		cout << sd << endl;

	system("pause");
	return 0;
}