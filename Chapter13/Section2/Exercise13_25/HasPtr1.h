#include<string>
#include<iostream>

using namespace std;

class HasPtr1
{
	friend bool comp(HasPtr1 &rhs, HasPtr1 &lhs);
public:
	HasPtr1(const string &s = "") :ps(new string(s)), i(0) { cout << "直接初始化" << endl; }
	HasPtr1(const HasPtr1& hp):ps(new string(*hp.ps)), i(hp.i){ cout << "拷贝初始化" << endl; }
	HasPtr1 &operator=(const HasPtr1&hp)
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
	HasPtr1 &operator=(const string &s)
	{
		cout << "拷贝string操作" << endl;
		*ps = s;
		return *this;
	}
	~HasPtr1() { cout << "析构函数" << endl; delete ps; }


private:
	string *ps;
	int i;
};

bool comp(HasPtr1 &rhs, HasPtr1 &lhs)
{
	return rhs.ps == lhs.ps;
}