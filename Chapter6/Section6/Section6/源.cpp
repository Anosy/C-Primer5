#include<iostream>
#include<string>

using namespace std;

bool lengthCompare(const string &, const string &);

// pfָ��һ���������ú����Ĳ���������const���ã�����ֵ��bool����
bool(*pf)(const string &, const string &);


int main()
{
	pf = lengthCompare;
}