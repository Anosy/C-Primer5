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
	cout << "����ǰ��" << j << endl;
	reset(j);
	cout << "������" << j << endl;
	
	system("pause");
	return 0;
}