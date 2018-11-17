#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include"Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() {   }
	Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
		Disc_quote(b, p, q, disc) {   }
	Bulk_quote(const Bulk_quote & bq):Disc_quote(bq)
	{
	}
	Bulk_quote(Bulk_quote && bq)  noexcept :Disc_quote(std::move(bq))
	{

	}
	Bulk_quote & operator=(const Bulk_quote& bq)
	{
		Disc_quote::operator=(bq);
		return *this;
	}
	Bulk_quote & operator=(Bulk_quote && bq) noexcept
	{
		Disc_quote::operator=(std::move(bq));
		return *this;
	}

	double net_price(std::size_t n) const override;
	~Bulk_quote() override
	{
	}
};

double Bulk_quote::net_price(std::size_t n) const
{
	if (n >= quantity)
	{
		return n * (1 - discount) * price;
	}
	else
	{
		return n * price;
	}
}



#endif // BULK_QUOTE_H