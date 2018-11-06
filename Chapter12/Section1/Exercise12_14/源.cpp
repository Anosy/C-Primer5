#include<iostream>
#include<memory>

using namespace std;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
	cout << "������" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "�ر�����" << endl;
}

void end_connection(connection *p) { disconnect(*p); }

// δʹ��shared_ptr�İ汾
void f(destination &d)
{
	cout << "ֱ�ӹ���connect" << endl;
	connection c = connect(&d);

	cout << endl;
}

// ʹ��shared_ptr�İ汾
void f2(destination &d)
{
	cout << "��shared_ptr����connect" << endl;
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
}

int main()
{
	destination d;
	f(d);
	f2(d);

	system("pause");
	return 0;
}