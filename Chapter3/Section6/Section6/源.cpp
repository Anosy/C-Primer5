// ��ά�����飬 ��ȡ��ʽ���ڵ���
#include<iostream>
using namespace std;


int main()
{
	int ia1[3][4]; // ��СΪ3�����飬ÿ��Ԫ�غ���4������������

	int arr[10][20][30]; // ��СΪ10�����飬ÿ��Ԫ�ض��Ǵ�СΪ20�����飬��Щ�����Ԫ�غ���30������������

	int ia2[3][4] = { // ��СΪ3�����飬�����ÿ��Ԫ�ض��Ǵ�СΪ4������
		{0, 1, 2, 3},  // ��һ�еĳ�ʼ��
		{4, 5, 6, 7},  // �ڶ��еĳ�ʼ��
		{8, 9, 10, 11} // �����еĳ�ʼ��
	};

	int ia3[3][4] = { 0,1,2,3,5,6,7,8,9,10,11 }; // ������ĵȼ�

	int ia4[3][4] = { {0}, {4}, {8} }; // ��ʼ��ÿ�еĵ�һ��Ԫ��

	int ix[3][4] = { 0 ,1, 2, 3 }; // ��ʼ����һ�е�Ԫ��

	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia5[rowCnt][colCnt];
	for (size_t i = 0; i != rowCnt; i++)
	{
		for (size_t j = 0; j != colCnt; j++)
		{
			ia5[i][j] = i * colCnt + j;
		}
	}

	size_t cnt = 0;
	int ia6[3][4];
	for (auto &a : ia6)
		for (auto &b : a)
		{
			b = cnt;
			++cnt;
		}

	for (auto p = ia5; p != ia5 + 3; p++)
	{
		for (auto q = *p; q != *p + 4; q++)
		{
			cout << *q << " ";
		}
		cout << endl;
	}


	for (auto p = begin(ia6); p != end(ia6); p++)
	{
		for (auto q = begin(*p); q != end(*p); q++)
		{
			cout << *q << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}