#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;
using namespace std;

int main()
{
	vector<int> vInt;
	int sought;

	cout << "��������Ҫ�ҵ����֣�" << endl;
	cin >> sought;

	for (unsigned i = 0; i <= 100; i++) // ����0~100��vector
	{
		vInt.push_back(i);
	}
	auto begin = vInt.cbegin();
	auto end = vInt.cend();
	auto mid = begin + (end - begin) / 2;

	while (mid!=end && *mid!=sought)
	{
		if (sought < *mid)
		{
			end = mid;
		}
		else
		{
			begin = mid + 1;
		}
		mid = begin + (end - begin) / 2;
	}
	cout << *mid << endl;  // ����ҵ���ֵ

	system("pause");
	return 0;
}