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
			throw runtime_error("IO������");
		}
		if (is.fail())
		{
			cerr << "���ݴ���" << endl;
			is.clear();
			is.ignore(100, '\n'); // ����ǰ100���ַ�������\n֮ǰ��
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