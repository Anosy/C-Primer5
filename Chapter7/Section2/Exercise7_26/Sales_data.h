class Sales_data
{
public:
	// 将成员函数定义在类的内部，从而达到隐式的inline
	double avg_price() const
	{
		if (units_sold)
		{
			return revenue / units_sold;
		}
		else
		{
			return 0;
		}
	}
};


class Sales_data
{
public:
	double avg_price() const;
};
inline double avg_price() const
{
	if (units_sold)
	{
		return revenue / units_sold;
	}
	else
	{
		return 0;
	}
}