class Sales_data
{
public:
	// ����Ա��������������ڲ����Ӷ��ﵽ��ʽ��inline
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