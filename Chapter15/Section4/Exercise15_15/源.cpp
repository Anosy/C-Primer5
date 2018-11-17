#include"Bulk_quote.h"
#include"Quote.h" // 两次include同一个头文件，因此需要使用#ifndef 
#include<iostream>

using namespace std;


double print_total(std::ostream& os, const Quote& item, size_t n);

int main()
{
	Quote q("textbook", 10.60);
	Bulk_quote bq("textbook", 10.60, 10, 0.3);

	print_total(std::cout, q, 12);
	print_total(std::cout, bq, 12);

	system("pause");
	return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;

	return ret;
}