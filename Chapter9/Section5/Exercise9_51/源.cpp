#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

class Date
{
public:
	Date() = default;
	Date(string &ds);

	unsigned y() const { return year; }
	unsigned m() const { return month; }
	unsigned d() const { return day; }

private:
	unsigned year;
	unsigned month;
	unsigned day;
};

const string month_name[] = { "January", "February", "March", "April", "May", "June", "July",
	"August", "September", "Octorber", "November", "December" };
const string month_abbr[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
	"Aug", "Sep", "Oct", "Nov", "Dec" };
const int days[] = { 31 ,28, 31, 30, 31,30,31,31,30,31,30,31 };

inline int get_month(string &ds, int &end_of_month)
{
	int i, j;
	for (i = 0; i != 12; ++i)
	{
		for (j = 0; j != month_abbr[i].size(); ++j)
		{
			if (ds[j] != month_abbr[i][j])
			{
				break;
			}
		}
		if (j == month_abbr[i].size())
		{
			break;
		}
	}
	if (i == 12)
	{
		throw invalid_argument("不是合法的月份名字！");
	}
	if (ds[j] = ' ') // 如果当前位置是空白符号，说明已经尾部，是缩写
	{
		end_of_month = j + 1;
		return i + 1;
	}
	

	for (; j != month_name[i].size(); ++j)
	{
		if (ds[j] != month_name[i][j])
		{
			break;
		}
	}
	if (j == month_name[i].size() && ds[j] == ' ')
	{
		end_of_month = j + 1;
		return i + 1;
	}

}

inline int get_day(string &ds, int month, int &p)
{
	size_t q;
	int day = stoi(ds.substr(p), &q);
	if (day < 1 || day > days[month])
	{
		throw invalid_argument("不是合法日期值");
	}
	p += q;
	return day;
}

inline int get_year(string &ds, int &p)
{
	size_t q;
	int year = stoi(ds.substr(p), &q);
	if (p + q < ds.size())
	{
		throw invalid_argument("非法结尾内容");
	}
	return year;
}

Date::Date(string &ds)
{
	int p;
	size_t q;

	if ((p = ds.find_first_of("0123456789")) == string::npos)
	{
		throw invalid_argument("没有数字，非法日期");
	}

	if (p > 0)
	{
		month = get_month(ds, p);
		day = get_day(ds, month, p);
		if (ds[p] != ' ' && ds[p] != ',')
		{
			throw invalid_argument("非法间隔符");
		}
		p++;
		year = get_year(ds, p);
	}
	else
	{
		month = stoi(ds, &q);
		p = q;
		if (month > 1 || month > 12)
		{
			throw invalid_argument("不是合法的月份");
		}
		if (ds[p++] != '/')
		{
			throw invalid_argument("非法间隔符");
		}
		day = get_day(ds, month, p);
		if (ds[p++] != '/')
		{
			throw invalid_argument("非法间隔符");
		}
		year = get_year(ds, p);
	}
}
ostream & operator << (ostream &out, const Date &d)
{
	out << d.y() << "年" << d.m() << "月" << d.d() << "日" << endl;
	return out;
}

int main()
{
	string dates[] = { "Jan 1, 1990" , "Jannnn 1, 1999"};
	try
	{
		for (auto ds : dates)
		{
			Date dl(ds);
			cout << dl;
		}
	}
	catch (invalid_argument e)
	{	
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}
