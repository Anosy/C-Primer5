#include<iostream>

using namespace std;

class Base
{
public:
	void pub_mem() {}
protected:
	int prot_mem() {}
private:
	char priv_mem() {}
};

struct Pub_Derv:public Base
{
	int f() { return prot_mem(); }
	void memfcn(Base &b)
	{
		b = *this;
		cout << "Pub_Derv" << endl;
	}
};

struct Priv_Derv :private Base
{
	int f1() { return prot_mem(); }
	void memfcn(Base &b)
	{
		b = *this;
		cout << "Priv_Derv" << endl;
	}
};

struct Prot_Derv :protected Base
{
	int f1() { return prot_mem(); }
	void memfcn(Base &b)
	{
		b = *this;
		cout << "Priv_Derv" << endl;
	}
};


int main()
{

	Pub_Derv d1;
	d1.pub_mem(); // 正确
	//d1.prot_mem(); // 错误：派生类的对象无法访问基类的成员
	Base *p = &d1; // 正确

	Priv_Derv d2;
	//d2.pub_mem(); // 错误：private继承的派生类对象，无法访问基类成员
	//Base p = &d2; // 错误：非公共继承派生类无法向基类转换

	Prot_Derv d3;
	//d3.pub_mem(); //错误：protect继承的派生类对象，无法访问基类成员
	//Base p = &d3;// 错误：非公共继承派生类无法向基类转换

}