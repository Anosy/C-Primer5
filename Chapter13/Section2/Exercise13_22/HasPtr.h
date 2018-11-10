#include<string>
#include<iostream>

using namespace std;

class HasPtr
{
public:
	// ���캯��
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) { cout << "ֱ�ӳ�ʼ��" << endl; }
	// �������캯��
	HasPtr(const HasPtr &hp) :ps(new string(*hp.ps)), i(hp.i) { cout << "������ʼ��" << endl; }
	// ������ֵ����
	HasPtr &operator=(const HasPtr &hp)
	{
		cout << "������ֵ����" << endl;
		auto newps = new string(*hp.ps);
		delete ps; // �ͷ�֮ǰstring����
		ps = newps;
		i = hp.i;
		return *this;
	}
	// ��ֵstring
	HasPtr &operator=(const string &s)
	{
		cout << "��ֵstring����" << endl;
		*ps = s;
		return *this;
	}
	// ��������
	~HasPtr() { cout << "����" << endl; delete ps; }
	// ������
	string &operator*()
	{
		return *ps;
	}


private:
	string *ps;
	int i;
};

