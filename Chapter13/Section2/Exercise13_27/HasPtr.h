#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = "") : ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) {}
	HasPtr &operator=(const HasPtr&rhs) // ��Ҫ�����Ը�ֵ�����
	{
		++*rhs.use; // �����Ҳ��������������
		if (--*use == 0) // �ݼ�����������ü����������ж��Ƿ�Ϊ0
		{
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}

	~HasPtr() // �������ж������Ƿ�Ϊ0��������ͷ�string��use�ڴ�
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