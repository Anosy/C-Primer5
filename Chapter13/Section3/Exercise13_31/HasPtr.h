#include<string>
#include<iostream>

using namespace std;

class HasPtr
{
	friend void swap(HasPtr &, HasPtr &);
public:
	// 构造函数
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {  }
	// 拷贝构造函数
	HasPtr(const HasPtr &hp) :ps(new string(*hp.ps)), i(hp.i) {  }
	// 拷贝赋值函数
	HasPtr &operator=(const HasPtr &hp)
	{

		auto newps = new string(*hp.ps);
		delete ps; // 释放之前string对象
		ps = newps;
		i = hp.i;
		return *this;
	}
	// 赋值string
	HasPtr &operator=(const string &s)
	{
		*ps = s;
		return *this;
	}
	// 析构函数
	~HasPtr() { delete ps; }
	// 解引用
	string &operator*()
	{
		return *ps;
	}
	// 比较运算符
	bool operator<(const HasPtr &rhs) const
	{
		return *ps < *rhs.ps;
	}


private:
	string *ps;
	int i;
};

inline
void swap(HasPtr& lhs, HasPtr &rhs)
{
	cout << "交换" << *lhs.ps << "和" << *rhs.ps << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

