#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;

int main()
{
	string line;
	// 每次读入一整行，直到达到文件的末尾
	while (std::getline(cin, line))
	{
		//if (!line.empty())
		//{
		//	cout << line << endl;
		//}
		if (line.size()>80) 
		{
			cout << line << endl;

		}
	}
	system("pause");
	return 0;
}