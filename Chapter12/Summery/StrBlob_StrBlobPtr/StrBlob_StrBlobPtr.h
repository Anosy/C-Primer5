#include<map>
#include<string>
#include<memory>
#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

// 提前声明，使用friend的时候要用
class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob() : data(make_shared<vector<string>>()) {};
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {};
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &s) { data->push_back(s); }
	void pop_back();
	string & back();
	string & front();
	StrBlobPtr begin();

	StrBlobPtr end();

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

inline void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= msg.size())
	{
		throw out_of_range(msg);
	}
}

inline string &StrBlob::front()
{
	check(0, "front error");
	return data->front();
}

inline string &StrBlob::back()
{
	check(0, "back error");
	return data->back();
}

inline void StrBlob::pop_back()
{
	check(0, "pop_back error");
	return data->pop_back();
}

class StrBlobPtr
{
	friend bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	string &deref() const;
	StrBlobPtr & incr();

private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

inline
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& s) const
{
	auto ret = wptr.lock();
	if (!ret)
	{
		throw runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw out_of_range(s);
	}
	return ret; // 返回shared_ptr
}

inline
string & StrBlobPtr::deref() const {
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

inline StrBlobPtr StrBlob::begin()
{
	auto ret = StrBlobPtr(*this, 0);
	return ret;
}

inline StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
	{
		return (!r || lhs.curr == rhs.curr);
	}
	else
	{
		return false;
	}
}

bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}