#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	string word1, word2;
	cin >> word1 >> word2;
	if (word1.size() == word2.size())
	{
		cout << "�����ַ����ĳ�����ͬ" << endl;
	}
	else
	{
		if (word1.size() > word2.size())
		{
			cout << word1 << endl;
		}
		else
		{
			cout << word2 << endl;
		}
	}

	system("pause");
	return 0;
}