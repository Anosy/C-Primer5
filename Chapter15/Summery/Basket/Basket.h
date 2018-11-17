#include<memory>
#include<iostream>
#include<set>
#include"Bulk_quote.h"
#include"Disc_quote.h"
#include"Quote.h"

using namespace std;

double print_total(std::ostream &os, const Quote &item, size_t n);

class Basket
{
public:
	void add_item(const Quote & sale)
	{
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote && sale)
	{
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}
	double total_receipt(ostream &) const;
private:
	static bool campare(const shared_ptr<Quote> & lhs, const shared_ptr<Quote> & rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(campare)*> items{ campare };
};

double Basket::total_receipt(ostream &os) const
{
	double sum = 0.0;
	for (auto it = items.cbegin(); it != items.cend(); it = items.upper_bound(*it))
	{
		sum += print_total(os, **it, items.count(*it));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;

	return ret;
}