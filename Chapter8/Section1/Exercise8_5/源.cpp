#include<string>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main()
{
	string data("data/mydata.txt");
	ifstream in(data);
	if (!in)
	{
		cerr << "找不到输入文件！" << endl;
		system("pause");
		return -1;
	}
	string word;
	vector<string> vStr;
	while (in>>word)
	{
		vStr.push_back(word);
	}
	
	in.close(); 

	for (const auto c : vStr)
	{
		cout << c << endl;
	}

	system("pause");
	return 0;
}