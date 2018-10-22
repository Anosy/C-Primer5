#include<string>

class Sales_data
{
	std::string bookNo; // 书籍编号
	unsigned units_sold = 0; // 销售量
	double sellingprice = 0.0; // 原始价格
	double saleprice = 0.0; // 实售价格
	double discount = 0.0; // 折扣

	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold); // 重新计算实际的销售价格
		if (sellingprice !=0)
		{
			discount = saleprice / sellingprice; // 重新计算折扣
		}
		return *this; // 返回合并后的结果
	}
};