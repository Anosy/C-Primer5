#include<iostream>

using namespace std;

void fact(int v1)
{
	if (v1==1)
	{
		cout << "�¶��ˣ�" << endl;
	}
	else
	{
		cout << "û�в¶�Ŷ��" << endl;
	}
}

int main()
{
	cout << "���һ������" << endl;
	int num;
	while (cin >> num)
	{
		fact(num);
	}
	return 0;
}