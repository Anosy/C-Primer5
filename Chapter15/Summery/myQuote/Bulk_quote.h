#ifndef  BULKQUOTE_H
#define BULKQUOTE_H
#include"Disc_quote.h"
#include"Quote.h"

class Bulk_quote :public Disc_quote
{
public:
	using Disc_quote::Disc_quote; // 继承Disc_quote的构造函数
	Bulk_quote & operator = (const Bulk_quote &bq)
	{
		Disc_quote::operator=(bq);
		return *this;
	}
	Bulk_quote &operator = (Bulk_quote &&bq) noexcept
	{
		Disc_quote::operator=(std::move(bq));
		return *this;

	}
	~Bulk_quote() override {}


	double net_price(std::size_t n) const override
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


};


#endif // ! BULKQUOTE_H
