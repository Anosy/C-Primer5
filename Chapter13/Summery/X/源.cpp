#include<iostream>
#include<vector>
#include<utility>

using namespace std;

struct X
{
	X() { cout << "直接初始" << endl; }
	X(const X &) { cout << "拷贝初始" << endl; }
	X(const X&&) { cout << "移动初始" << endl; }
	X &operator=(const X&) { cout << "拷贝赋值运算符" << endl; return *this; };
	~X() { cout << "析构函数" << endl; }
};

void f(X)
{

}
void f2(X &)
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

	cout << "传递右值" << endl;
	X z(move(x));
	cout << endl;
		 

	system("pause");
	return 0;
}