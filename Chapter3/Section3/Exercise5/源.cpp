#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;
using namespace std;

int main()
{
	vector<int> v1;
	int c, sum;
	while (cin >> c)
	{
		v1.push_back(c);
	}

	vector<int>::size_type size = v1.size();

	if (size == 0)
	{
		cout << "û���κε�Ԫ��" << endl;
		return -1;
	}

	// ǰ��������ӵĽ��
	//for (unsigned i = 0; i < size - 1; i += 2)
	//{
	//	sum = v1[i] + v1[i+1];
	//	cout << sum << endl;
	//}
	//if (size % 2 != 0)  // ���Ԫ�صĸ���������������������һ��
	//{
	//	cout << v1[size - 1];
	//}


	// ͷβ������ӵĽ��
	for (unsigned i = 0; i < ( size / 2); i++)
	{
		sum = v1[i] + v1[size - i - 1];
		cout << sum << " ";

		if ((i + 1) % 5 == 0) // ÿ�����5������
		{
			cout << endl;
		}
	}
	if (size % 2 != 0)
	{
		cout << "\n��������Ϊ��" << v1[size / 2] << endl;
	}

	system("pause");
	return 0;
}