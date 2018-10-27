#include<string>
#include<fstream>
#include<iostream>

using namespace std;

int main()
{
	ifstream fin("data/mydata.txt");
	string ascender("bdfhklt"); //上出头部分单词
	string descender("gjpqy");  //下出头部分单词
	string outword = ascender + descender;
	unsigned max_length = 0;
	string most_long_str;
	string word;
	
	cout << "不包含上出头也不包含下出头的部分的单词为：" << endl;
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

	cout << "最长不包含上出头也不包含下出头的部分的单词为：" << most_long_str << endl;

	system("pause");
	return 0;
}