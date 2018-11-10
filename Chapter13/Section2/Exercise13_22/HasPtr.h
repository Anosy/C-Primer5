#include<string>
#include<iostream>

using namespace std;

class HasPtr
{
public:
	// 构造函数
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) { cout << "直接初始化" << endl; }
	// 拷贝构造函数
	HasPtr(const HasPtr &hp) :ps(new string(*hp.ps)), i(hp.i) { cout << "拷贝初始化" << endl; }
	// 拷贝赋值函数
	HasPtr &operator=(const HasPtr &hp)
	{
		cout << "拷贝赋值操作" << endl;
		auto newps = new string(*hp.ps);
		delete ps; // 释放之前string对象
		ps = newps;
		i = hp.i;
		return *this;
	}
	// 赋值string
	HasPtr &operator=(const string &s)
	{
		cout << "赋值string操作" << endl;
		*ps = s;
		return *this;
	}
	// 析构函数
	~HasPtr() { cout << "析构" << endl; delete ps; }
	// 解引用
	string &operator*()
	{
		return *ps;
	}


private:
	string *ps;
	int i;
};

