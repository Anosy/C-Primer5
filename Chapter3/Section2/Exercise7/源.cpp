#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	string s, results;
	cout << "�������ַ��������԰����ո�" << endl;

	getline(cin, s);
	for (auto &c : s)
	{
		if (!ispunct(c))
		{
			results += c;
		}
	}
	cout << results << endl;

	system("pause");
	return 0;
}
