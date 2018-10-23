#include<string>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main()
{
	ifstream inf("data/mydata.txt"); // 构建一个ifstream并且打开给的文件
	if (!inf)
	{
		cerr << "无法打开输入文件！" << endl;
		system("pause");
		return -1;
	}
	
	string line;
	vector<string> words;
	while (getline(inf, line))   // 从文件中读取一行
	{
		words.push_back(line);  // 添加到vector中
	}
	inf.close(); // 输入完毕，关闭文件

	for (const auto s : words)
	{
		cout << s << endl;
	}

	system("pause");
	return 0;
}