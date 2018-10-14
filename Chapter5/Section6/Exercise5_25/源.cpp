#include<iostream>
#include<stdexcept>
using namespace std;

int main()
{
	int num1, num2;
	cout << "请输入两个数字" << endl;
	while (cin >> num1 >> num2)
	{
		try
		{
			if (num2 == 0)
			{
				throw runtime_error("除数不能为0！");
			}
			cout << "两个数相除的结果：" << num1 / num2 << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << "\n是否重新输入(y or n)？" << endl;
			char c;
			cin >> c;
			if (c != 'y')
			{
				break;
			}
		}
	}

	system("pause");
	return 0;
}