#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;

int main()
{
	string s1 = "hello, ", s2 = "world\n";
	string s3 = s1 + s2;
	string s4 = s1 + ", ";
	string s5 = "hello" + s2; // string ����Ķ����ʱ�����ʹ��+���������ô������һ������string���͵�

	cout << s1 << s2 << s3 << s4 << s5 << endl;

	system("pause");
	return 0;
}