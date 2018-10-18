#include<iostream>

using namespace std;

double myAdd(double val1, double val2)
{
	double result = val1 + val2;
	static unsigned iCnt = 0;
	++iCnt;
	cout << "该函数累计执行了" << iCnt << "次" << endl;

	return result;
}

int main()
{
	double num1, num2;
	cout << "请输入两个数字：" << endl;
	while (cin >> num1 >> num2)
	{
		cout << num1 << "和" << num2 << "的和为" << myAdd(num1, num2) << endl;
	}
	system("pause");
	return 0;
}