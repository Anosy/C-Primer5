#include"myQuery.h"

using namespace std;

int main()
{
	ifstream infile("data/mydata.txt");
	if (!infile)
	{
		cout << "�ļ������ڣ�" << endl;
		system("pause");
		return -1;
	}
	TextQuery tq(infile);
	string s;
	while (true)
	{
		cout << "��������Ҫ��ѯ�ĵ��ʣ�" << endl;
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