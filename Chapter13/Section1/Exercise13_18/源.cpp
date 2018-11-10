#include<iostream>
#include<string>

using namespace std;

class Employee
{
public:
	// Ĭ�Ϲ��캯��
	Employee() { mysn = id++; }
	// ���캯��
	Employee(const string &s) :name(s), mysn(id++) {}
	// �������캯��
	Employee(Employee &e) { name = e.name; mysn = id++; }
	// ������ֵ����
	Employee &operator=(Employee &rhs) { name = rhs.name; return *this; }

	const string & get_name() { return name; }
	int get_mysn() { return mysn; }

private:
	static unsigned id;
	string name;
	int mysn;
};

unsigned Employee::id = 0;

void f(Employee &s)
{
	cout << s.get_name() << " " << s.get_mysn() << endl;
}


int main()
{
	/*
	a��ʼ�����õ�a.name = �ԣ�a.mysn = 0
	b������ʼ�����õ�b.name = �ԣ�b.mysn = 1����Ϊ���ʱ��id��a�ĳ�ʼ��������1
	c��ֵ���õ�c.name=��,c.mysn=2����Ϊ��ʱ��id��b�ĳ�ʼ��������2
	*/
	Employee a("��"), b = a, c; 
	c = b;
	f(a);
	f(b);
	f(c);

	system("pause");
	return 0;
}