#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	unsigned sz = 6;
	vector<string> vStr = { "mike" ,"He", "He", "red", "red", "red", "h", "hi", "she", "apple" , "lambda1"};
	auto count = count_if(vStr.begin(), vStr.end(), [=](string &s) {return s.size() > sz; });
	cout << "��" << count << "�����ʳ��ȳ���" << sz << endl;
	
	system("pause");
	return 0;
}