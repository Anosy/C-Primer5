#include"Basket.h"
#include"Bulk_quote.h"
#include"Disc_quote.h"
#include"Quote.h"

using namespace std;

int main()
{
	Basket basket;
	Bulk_quote matlab("Matlab", 15.6, 10, 0.2);
	for (unsigned i = 0; i != 10; ++i)
	{
		basket.add_item(matlab);
	}

	for (unsigned i = 0; i != 10; ++i)
	{
		basket.add_item(Bulk_quote("Pyhon", 20.6, 20, 0.3));
	}

	for (unsigned i = 0; i != 10; ++i)
	{
		basket.add_item(Bulk_quote("C++", 30.9, 5, 0.4));
	}

	for (unsigned i = 0; i != 10; ++i)
	{
		basket.add_item(Quote("Java", 40.1));
	}

	basket.total_receipt(cout);

	system("pause");
	return 0;
}
