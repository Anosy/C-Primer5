#include<iostream>
using namespace std;

istream& func(istream& is)
{
	int v;
	while (is>>v, !is.eof())  // 从输入流读入数据到v中，只到文件到文件结束符停止读取（判断逗号后面的部分）
	{
		auto state = is.rdstate();
		cout << "当前状态：" << state << endl;
		if (is.bad())
		{
			throw runtime_error("IO流错误");
		}
		if (is.fail())
		{
			cerr << "数据错误，请重试:" << endl;
			is.clear();
			is.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	auto state = is.rdstate();
	cout << "当前状态：" << state << endl;
	is.clear();
	return is;
}

int main()
{
	cout << "请输入一些整数，按CTRL+Z结束" << endl;
	func(cin);
	
	system("pause");
	return 0;
}