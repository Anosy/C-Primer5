#include<iostream>
#include<memory>

using namespace std;

struct connection
{
};
struct destination
{
};

connection connect(destination *pd)
{
	cout << "������" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "�ر�����" << endl;
}



void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *p) {disconnect(*p); });
}

int main()
{
	destination d;
	f(d);
	system("pause");
	return 0;
}