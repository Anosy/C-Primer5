#include"Quote.h"

class Limited : public Quote
{
public: 
	Limited() = default;
	Limited(const std::string &s, double p, unsigned num, double d):
		Quote(s, p), maxNum(num), discounts(d){}
	double net_price(std::size_t n) const override;

private:
	unsigned maxNum = 0;
	double discounts = 0.0;
};

double Limited::net_price(std::size_t n) const
{
	if (n < maxNum)
	{
		return price * (1 - discounts) * n;
	}
	else
	{
		return price * maxNum * (1 - discounts) + price * (n - maxNum);
	}
}