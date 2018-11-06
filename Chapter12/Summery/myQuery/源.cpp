#include"myQuery.h"

using namespace std;

int main()
{
	ifstream infile("data/mydata.txt");
	if (!infile)
	{
		cout << "文件不存在！" << endl;
		system("pause");
		return -1;
	}
	TextQuery tq(infile);
	string s;
	while (true)
	{
		cout << "请输入需要查询的单词：" << endl;
		if (!(cin>>s) || s == "q")
		{
			break;
		}
		auto result = tq.query(s);
		print(cout, result) << endl;
	}

	system("pause");
	return 0;
}