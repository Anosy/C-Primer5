#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	string s("Hello World!!!");
	// ��¼s���ж��ٸ�������
	decltype(s.size()) punct_cnt = 0;
	for (auto c : s)  // ����s�е�ÿ���ַ�
	{
		if (ispunct(c))
		{
			++punct_cnt;
		}
	}
	cout << punct_cnt << " punctuation characters in " << s << endl;


	//  ת��Ϊ��д
	for (auto &d : s)
	{
		d = toupper(d);
	}
	cout << s << endl;

	s[0] = tolower(s[0]); // Ϊs��һ���ַ������µ�ֵ
	cout << s << endl;


	system("pause");
	return 0;
}