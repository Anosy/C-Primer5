#include"Limited_quote.h"
#include"Quote.h"
#include"Disc_quote.h"
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
	Limited_quote l("C++Primer5", 55.5, 10, 0.8);
	// Disc_quote("C++Primer5", 55.5, 10, 0.8);// 错误：不能实例化抽象类

	print_total(cout, q, 10);
	print_total(cout, l, 15);

	system("pause");
	return 0;
}