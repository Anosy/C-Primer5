#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	fstream inOut("data\\mydata.txt", fstream::ate | fstream::in | fstream::out);
	if (!inOut)
	{
		cout << "�ļ������ڣ�" << endl;
	}
	auto end_mark = inOut.tellg();  // ��ȡ��ǰ�ļ���ĩβ
	inOut.seekg(0, fstream::beg);  // �ƶ�����ǰ�ļ��Ŀ�ʼ
	size_t cnt = 0;
	string line;
	while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) // �����û���ļ�ĩβ���ȡһ��
	{
		cnt += line.size() + 1; //+1��ʾ���з�
		auto mark = inOut.tellg(); // ������ǰ��ȡλ��
		inOut.seekp(0, fstream::end);  // ��д��λ�ø��ƶ����ļ���ĩβ
		inOut << cnt;		// д��
		if (mark != end_mark) // �����û���ļ��Ľ�β������Ͽո�
		{
			inOut << " ";
		}
		inOut.seekg(mark); // �ٴ��ƶ���֮ǰ�Ķ�ȡλ��		
	}
	inOut.seekp(0, fstream::end); // �ƶ����ļ��Ľ�β
}