#include<string>
#include<iostream>

using namespace std;

class HasPtr
{
	friend void swap(HasPtr &, HasPtr &);
public:
	// ���캯��
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {  }
	// �������캯��
	HasPtr(const HasPtr &hp) :ps(new string(*hp.ps)), i(hp.i) {  }
	// ������ֵ����
	HasPtr &operator=(const HasPtr &hp)
	{

		auto newps = new string(*hp.ps);
		delete ps; // �ͷ�֮ǰstring����
		ps = newps;
		i = hp.i;
		return *this;
	}
	// ��ֵstring
	HasPtr &operator=(const string &s)
	{
		*ps = s;
		return *this;
	}
	// ��������
	~HasPtr() { delete ps; }
	// ������
	string &operator*()
	{
		return *ps;
	}
	// �Ƚ������
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
	cout << "����" << *lhs.ps << "��" << *rhs.ps << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

