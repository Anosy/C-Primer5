#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;

int main()
{
	string line;
	// ÿ�ζ���һ���У�ֱ���ﵽ�ļ���ĩβ
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