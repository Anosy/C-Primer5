#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include"Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
	using Disc_quote::Disc_quote;
	Bulk_quote & operator=(const Bulk_quote& bq)
	{
		Disc_quote::operator=(bq);
		std::cout << "Bulk_quote¿½±´¸³ÖµÔËËã·û" << std::endl;
		return *this;
	}
	Bulk_quote & operator=(Bulk_quote && bq) noexcept
	{
		Disc_quote::operator=(std::move(bq));
		std::cout << "Bulk_quoteÒÆ¶¯¸³ÖµÔËËã·û" << std::endl;
		return *this;
	}

	double net_price(std::size_t n) const override;
	~Bulk_quote() override
	{
		std::cout << "Bulk_quoteÎö¹¹º¯Êý" << std::endl;
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