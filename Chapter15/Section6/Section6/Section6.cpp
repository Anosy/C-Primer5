#include<iostream>

using namespace std;

class Base
{
public:
	virtual void fcn() { cout << "基类fcn函数" << endl; }
};

class D1 :public Base
{
public:
	// 隐藏了基类的fcn()，而非覆盖
	void fcn(int) { cout << "D1派生类fcn(int)函数" << endl; }
	virtual void f2() { cout << "D1派生类f2函数" << endl; }
};

class D2 :public D1
{
public:
	void fcn(int) { cout << "D2派生类fcn(int)函数" << endl; }
	void fcn(){ cout << "D2派生类fcn函数" << endl; }
	void f2() { cout << "D2派生类f2函数" << endl; }
};

int main()
{
	Base bobj; D1 d1obj; D2 d2obj;
	
	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn(); // 调用基类的
	bp2->fcn(); // 调用基类的
	bp3->fcn(); // 调用D2的
	cout << endl;

	D1 *d1p = &d1obj; D2 *d2p = &d2obj;
	//bp2->f2(); //错误：基类没有f2
	d1p->f2(); // 调用D1的
	d2p->f2(); // 调用D2的


	system("pause");
	return 0;
}