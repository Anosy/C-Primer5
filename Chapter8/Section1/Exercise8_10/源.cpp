#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	ifstream in("data/mydata.txt");
	if (!in)
	{
		cerr << "无法打开当前文件" << endl;
		return -1;
	}

	string line;
	vector<string> words;
	while (getline(in, line))
	{
		words.push_back(line);
	}
	in.close();

	auto it = words.begin();
	while (it != words.end())
	{
		istringstream iss(*it);
		string word;
		while (iss>>word)
		{
			cout << word << " ";
		}
		cout << endl;
		++it;
	}

	system("pause");
	return 0;
}
