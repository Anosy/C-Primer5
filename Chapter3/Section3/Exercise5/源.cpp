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
		cout << "没有任何的元素" << endl;
		return -1;
	}

	// 前后两个相加的结果
	//for (unsigned i = 0; i < size - 1; i += 2)
	//{
	//	sum = v1[i] + v1[i+1];
	//	cout << sum << endl;
	//}
	//if (size % 2 != 0)  // 如果元素的个数是奇数，单独输出最后一个
	//{
	//	cout << v1[size - 1];
	//}


	// 头尾两个相加的结果
	for (unsigned i = 0; i < ( size / 2); i++)
	{
		sum = v1[i] + v1[size - i - 1];
		cout << sum << " ";

		if ((i + 1) % 5 == 0) // 每行输出5个数字
		{
			cout << endl;
		}
	}
	if (size % 2 != 0)
	{
		cout << "\n单独的数为：" << v1[size / 2] << endl;
	}

	system("pause");
	return 0;
}