#include<iostream>
using namespace std;

istream& func(istream& is)
{
	int v;
	while (is>>v, !is.eof())  // ���������������ݵ�v�У�ֻ���ļ����ļ�������ֹͣ��ȡ���ж϶��ź���Ĳ��֣�
	{
		auto state = is.rdstate();
		cout << "��ǰ״̬��" << state << endl;
		if (is.bad())
		{
			throw runtime_error("IO������");
		}
		if (is.fail())
		{
			cerr << "���ݴ���������:" << endl;
			is.clear();
			is.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	auto state = is.rdstate();
	cout << "��ǰ״̬��" << state << endl;
	is.clear();
	return is;
}

int main()
{
	cout << "������һЩ��������CTRL+Z����" << endl;
	func(cin);
	
	system("pause");
	return 0;
}