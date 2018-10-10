#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	string s("Hello World!!!");
	// 记录s中有多少个标点符号
	decltype(s.size()) punct_cnt = 0;
	for (auto c : s)  // 对于s中的每个字符
	{
		if (ispunct(c))
		{
			++punct_cnt;
		}
	}
	cout << punct_cnt << " punctuation characters in " << s << endl;


	//  转化为大写
	for (auto &d : s)
	{
		d = toupper(d);
	}
	cout << s << endl;

	s[0] = tolower(s[0]); // 为s的一个字符赋予新的值
	cout << s << endl;


	system("pause");
	return 0;
}