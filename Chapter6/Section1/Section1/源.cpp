#include<iostream>

using namespace std;


// ���庯��
int fact(int val)
{
	int ret = 1;
	while (val>1)
	{
		ret *= val--; // ��ret��val��ֵ��ˣ��κν��������ֵ��ret�����ҽ�val-1
	}
	return ret;
}

// ���ú���
int main()
{
	int j = fact(5);
	cout << "5! is" << j << endl;
	return 0;
}
