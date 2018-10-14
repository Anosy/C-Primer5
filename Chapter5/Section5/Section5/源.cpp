#include<string>
#include<iostream>

using namespace std;

int main()
{
	string buf;
	while (cin >> buf && !buf.empty())
	{
		switch (buf[0])
		{
		case '-':
			for (auto it = buf.begin()+1; it != buf.end(); it++)
			{
				if (*it == ' ')
				{
					break; // 如果出现空白，退出for循环
				}
			}
			break; // 退出switch
		default:
			break;
		}
	}
}