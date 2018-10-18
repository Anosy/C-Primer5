#include<iostream>
#include<string>
using namespace std;

void reset(int &i)
{
	i = 15;
}

int main()
{
	int j = 0;
	cout << "交换前：" << j << endl;
	reset(j);
	cout << "交换后：" << j << endl;
	
	system("pause");
	return 0;
}