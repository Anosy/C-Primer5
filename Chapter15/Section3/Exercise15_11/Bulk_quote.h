#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include"Quote.h"

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
		Quote(b, p), min_qty(q), discount(disc) {   }

	double net_price(std::size_t n) const override;

	void debug() override
	{
		Quote::debug();
		std::cout << "min_qty:" << min_qty << " discount:" << discount << std::endl;
	}

private:
	std::size_t min_qty = 0;
	double      discount = 0.0;
};

double Bulk_quote::net_price(std::size_t n) const
{
	if (n >= min_qty)
	{
		return n * (1 - discount) * price;
	}
	else
	{
		return n * price;
	}
}



#endif // BULK_QUOTE_H