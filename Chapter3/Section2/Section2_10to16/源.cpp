#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	const string hexdigits = "0123456789ABCDEF"; // ����ʮ�����Ƶ���

	cout << "������0-15֮������֣�Ȼ�������ǵĳ�����ת��Ϊʮ�����Ƶ�������: " << endl;
	string results;
	string::size_type n; // ���ڱ�����������ȡ����

	while (cin >> n)
	{
		if (hexdigits.size() > n)  // ȷ���±�С��hexdigits�ĳ���
		{
			results += hexdigits[n];
		}
	}
	cout << "ת���Ľ��Ϊ��" << results << endl;

	system("pause");
	return 0;
}