#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = "") : ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) {}
	HasPtr &operator=(const HasPtr&rhs) // 需要考虑自赋值的情况
	{
		++*rhs.use; // 递增右侧的运算对象的引用
		if (--*use == 0) // 递减本对象的引用计数，并且判断是否为0
		{
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}

	~HasPtr() // 析构，判断引用是否为0，如果是释放string和use内存
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}

private:
	string *ps;
	int i;
	size_t *use;
};