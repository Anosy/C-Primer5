#include<string>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main()
{
	ifstream inf("data/mydata.txt"); // ����һ��ifstream���Ҵ򿪸����ļ�
	if (!inf)
	{
		cerr << "�޷��������ļ���" << endl;
		system("pause");
		return -1;
	}
	
	string line;
	vector<string> words;
	while (getline(inf, line))   // ���ļ��ж�ȡһ��
	{
		words.push_back(line);  // ��ӵ�vector��
	}
	inf.close(); // ������ϣ��ر��ļ�

	for (const auto s : words)
	{
		cout << s << endl;
	}

	system("pause");
	return 0;
}