#include<iostream>
#include<string>

using namespace std;

class Employee
{
public:
	// 默认构造函数
	Employee() { mysn = id++; }
	// 构造函数
	Employee(const string &s) :name(s), mysn(id++) {}
	// 拷贝构造函数
	Employee(Employee &e) { name = e.name; mysn = id++; }
	// 拷贝赋值函数
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
	a初始化，得到a.name = 赵，a.mysn = 0
	b拷贝初始化，得到b.name = 赵，b.mysn = 1。因为这个时候id在a的初始化后变成了1
	c赋值，得到c.name=赵,c.mysn=2。因为这时候id在b的初始化后变成了2
	*/
	Employee a("赵"), b = a, c; 
	c = b;
	f(a);
	f(b);
	f(c);

	system("pause");
	return 0;
}