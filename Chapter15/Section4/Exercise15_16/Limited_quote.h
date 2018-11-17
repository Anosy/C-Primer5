#include"Disc_quote.h"

class Limited_quote : public Disc_quote
{
public:
	Limited_quote() = default;
	Limited_quote(const std::string &s, double p, unsigned num, double d) :
		Disc_quote(s, p, num, d){}
	double net_price(std::size_t n) const override;
};

double Limited_quote::net_price(std::size_t n) const
{
	if (n < quantity)
	{
		return price * (1 - discount) * n;
	}
	else
	{
		return price * quantity * (1 - discount) + price * (n - discount);
	}
}