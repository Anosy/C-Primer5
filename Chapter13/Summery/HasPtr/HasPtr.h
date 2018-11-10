#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
	friend void swap(HasPtr &, HasPtr &);
public:
	HasPtr(const string &s = "") :ps(new string(s)), i(0) {};
	HasPtr(const HasPtr &hp) :ps(new string(*hp.ps)), i(hp.i) {}
	HasPtr &operator=(const HasPtr &hp)
	{
		auto newps = new string(*hp.ps);
		delete ps;
		ps = hp.ps;
		i = hp.i;
		return *this;
	}
	~HasPtr() { delete ps; }

	string &operator*()
	{
		return *ps;
	}
	bool operator<(const HasPtr &rhs) const
	{
		return *ps < *rhs.ps;
	}
private:
	string *ps;
	int i;
};

void swap(HasPtr& lhs, HasPtr &rhs)
{
	cout << "½»»»" << *lhs.ps << "ºÍ" << *rhs.ps << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}