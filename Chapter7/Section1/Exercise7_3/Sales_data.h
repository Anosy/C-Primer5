#include<string>

struct Sales_data
{

	std::string bookNo; // 书籍编号
	unsigned units_sold = 0; // 销售量
	double revenue = 0.0; // 收益
	


	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this; // 返回合并后的结果
	}
};