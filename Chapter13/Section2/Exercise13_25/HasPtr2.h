#include<string>
#include<iostream>

using namespace std;

class HasPtr2
{
	friend bool comp2(HasPtr2 &rhs, HasPtr2 &lhs);
public:
	HasPtr2(const string &s = "") :ps(new string(s)), i(0) { cout << "直接初始化" << endl; }
	//HasPtr2(const HasPtr2& hp) :ps(new string(*hp.ps)), i(hp.i) { cout << "拷贝初始化" << endl; }
	HasPtr2 &operator=(const HasPtr2&hp)
	{
		cout << "赋值拷贝操作" << endl;
		auto newps = new string(*hp.ps);
		delete ps;
		ps = newps;
		i = hp.i;
		return *this;
	}
	string &operator*()
	{
		return *ps;
	}
	HasPtr2 &operator=(const string &s)
	{
		cout << "拷贝string操作" << endl;
		*ps = s;
		return *this;
	}
	//~HasPtr2() { cout << "析构函数" << endl; delete ps; } // 如果构造了析构函数将会使得另外一个指针成为空悬指针


private:
	string *ps;
	int i;
};

bool comp2(HasPtr2 &rhs, HasPtr2 &lhs)
{
	return rhs.ps == lhs.ps;
}