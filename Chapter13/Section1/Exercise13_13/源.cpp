#include<iostream>
#include<vector>

using namespace std;

struct X
{
	X() { cout << "构造函数 X()" << endl; }

	X(const X&) { cout << "拷贝构造函数 X(const X&)" << endl; }

	X& operator=(const X& rhs) { cout << "拷贝赋值运算符" << endl; return *this; }

	~X() { cout << "析构函数 ~X()" << endl; }

};


void f(X x)
{

}

void f2(X &x)
{

}

int main()
{
	cout << "X x" << endl;
	X x;
	cout << endl;

	cout << "非引用传递参数" << endl;
	f(x);
	cout << endl;

	cout << "引用传递参数" << endl;
	f2(x);
	cout << endl;

	cout << "动态分配" << endl;
	auto *p = new X;
	cout << endl;

	cout << "释放动态分配对象" << endl;
	delete p;
	cout << endl;

	cout << "间接初始化和赋值" << endl;
	X y = x;
	y = x;
	cout << endl;
	
	system("pause");
	return 0;
}