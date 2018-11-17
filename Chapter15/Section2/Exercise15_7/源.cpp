#include"Limited.h"
#include"Quote.h"
#include<iostream>

using namespace std;

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;

	return ret;
}

int main()
{
	Quote q("C++Primer5", 55.5);
	Limited l("C++Primer5", 55.5, 10, 0.8);

	print_total(cout, q, 10);
	print_total(cout, l, 15);

	system("pause");
	return 0;
}