#include<string>
#include<fstream>
#include<iostream>

using namespace std;

int main()
{
	ifstream fin("data/mydata.txt");
	string ascender("bdfhklt"); //�ϳ�ͷ���ֵ���
	string descender("gjpqy");  //�³�ͷ���ֵ���
	string outword = ascender + descender;
	unsigned max_length = 0;
	string most_long_str;
	string word;
	
	cout << "�������ϳ�ͷҲ�������³�ͷ�Ĳ��ֵĵ���Ϊ��" << endl;
	while (fin >> word)
	{
		if (word.find_first_of(outword) != string::npos)
		{
			continue;
		}
		cout << word << " ";
		if (word.size() > max_length)
		{
			max_length = word.size();
			most_long_str = word;
		}
	}
	cout << endl;

	cout << "��������ϳ�ͷҲ�������³�ͷ�Ĳ��ֵĵ���Ϊ��" << most_long_str << endl;

	system("pause");
	return 0;
}