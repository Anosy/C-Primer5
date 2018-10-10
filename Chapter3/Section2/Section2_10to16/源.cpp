#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	const string hexdigits = "0123456789ABCDEF"; // 保存十六进制的数

	cout << "请输入0-15之间的数字，然后让我们的程序将其转化为十六进制的情况输出: " << endl;
	string results;
	string::size_type n; // 用于保存输入流读取的数

	while (cin >> n)
	{
		if (hexdigits.size() > n)  // 确保下标小于hexdigits的长度
		{
			results += hexdigits[n];
		}
	}
	cout << "转化的结果为：" << results << endl;

	system("pause");
	return 0;
}