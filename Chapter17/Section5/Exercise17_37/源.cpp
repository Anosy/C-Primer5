#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream ifs("data\\mydata.txt");
	char ch[20];
	if (!ifs)
	{
		cout << "�ļ�Ϊ��" << endl;
	}
	while (ifs.getline(ch, 20))
	{
		cout << ch << endl;
	}

	system("pause");
	return 0;
}