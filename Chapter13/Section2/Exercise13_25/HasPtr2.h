#include<string>
#include<iostream>

using namespace std;

class HasPtr2
{
	friend bool comp2(HasPtr2 &rhs, HasPtr2 &lhs);
public:
	HasPtr2(const string &s = "") :ps(new string(s)), i(0) { cout << "ֱ�ӳ�ʼ��" << endl; }
	//HasPtr2(const HasPtr2& hp) :ps(new string(*hp.ps)), i(hp.i) { cout << "������ʼ��" << endl; }
	HasPtr2 &operator=(const HasPtr2&hp)
	{
		cout << "��ֵ��������" << endl;
		auto newps = new string(*hp.ps);
		delete ps;
		ps = newps;
		i = hp.i;
		return *this;
	}
	string &operator*()
	{
		return *ps;
	}
	HasPtr2 &operator=(const string &s)
	{
		cout << "����string����" << endl;
		*ps = s;
		return *this;
	}
	//~HasPtr2() { cout << "��������" << endl; delete ps; } // ���������������������ʹ������һ��ָ���Ϊ����ָ��


private:
	string *ps;
	int i;
};

bool comp2(HasPtr2 &rhs, HasPtr2 &lhs)
{
	return rhs.ps == lhs.ps;
}