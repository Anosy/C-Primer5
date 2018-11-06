#include<iostream>
#include<memory>

using namespace std;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
	cout << "打开连接" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "关闭连接" << endl;
}

void end_connection(connection *p) { disconnect(*p); }

// 未使用shared_ptr的版本
void f(destination &d)
{
	cout << "直接管理connect" << endl;
	connection c = connect(&d);

	cout << endl;
}

// 使用shared_ptr的版本
void f2(destination &d)
{
	cout << "用shared_ptr管理connect" << endl;
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