#include<iostream>
#include<fstream>
#include<sstream>
#include"my_StrBlob.h"

using namespace std;

int main()
{
	ifstream in("data/mydata.txt");
	if (!in)
	{
		cout << "无法打开输入文件!" << endl;
		return -1;
	}
	string line;
	StrBlob b;
	while (getline(in, line))
	{
		istringstream is(line);
		string word;
		while (is >> word)
		{
			b.push_back(word);
		}
	}
	for (auto it = b.begin(); neq(it, b.end()); it.incr())
	{
		cout << it.deref() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}