#include<string>
#include<vector>
#include<memory>
#include<iostream>
#include<initializer_list>

using namespace std;

class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
public:
	using size_type = vector<string>::size_type;
	StrBlob() :data(make_shared<vector<string>>()) {};
	StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {}
	size_type size() { return data->size(); }
	bool empty() { return data->empty(); }
	void push_back(const string &s) { data->push_back(s); }
	void pop_back();
	string& front();
	string& back();
	StrBlobPtr begin();
	StrBlobPtr end();

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}

string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}




class StrBlobPtr
{
	friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	string & deref() const;
	StrBlobPtr & incr();

private:
	shared_ptr<vector<string>> check(size_t i, const string &msg) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
	{
		throw runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;
}

inline
string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline
StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return (lhs.wptr.lock() != rhs.wptr.lock()) || lhs.curr != rhs.curr;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this, 0);
}

StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}


