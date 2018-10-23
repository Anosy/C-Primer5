#include<iostream>
#include<sstream>
#include<string>

using namespace std;

istream & func(istream & is)
{
	string v;
	while (is >> v, !is.eof())
	{
		if (is.bad())
		{
			throw runtime_error("IO流错误");
		}
		if (is.fail())
		{
			cerr << "数据错误" << endl;
			is.clear();
			is.ignore(100, '\n'); // 或略前100个字符，或者\n之前的
			continue;
		}
		cout << v << endl;
	}
	is.clear();
	return is;
}


int main()
{
	ostringstream msg;
	msg << "C++ Primer 5" << endl;
	istringstream is(msg.str());
	func(is);

	system("pause");
	return 0;
}