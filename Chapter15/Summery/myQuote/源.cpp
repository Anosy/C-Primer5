#include"Bulk_quote.h"
#include"Quote.h"
#include"Disc_quote.h"

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
	Quote q("C++", 128.0);
	Bulk_quote bq("Pyhton", 89, 5, 0.19);
	print_total(cout, q, 10);
	print_total(cout, bq, 10);


	system("pause");
	return 0;
}