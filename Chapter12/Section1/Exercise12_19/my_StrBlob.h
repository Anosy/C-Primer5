#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<initializer_list>

using namespace std;

class StrBlobPtr;

class StrBlob
{
friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob() :data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {}
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// 添加删除元素
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	// 访问元素
	string &front();
	string &back();

	// 提供给StrBlobPtr的接口
	StrBlobPtr begin();
	
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data;
	void check(string::size_type i, const string &msg) const;
};

inline void StrBlob::check(string::size_type i, const string &msg) const
{
	if (i>=data->size())
	{
		throw out_of_range(msg);
	}
}

inline string & StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

inline string &StrBlob::back()
{
	check(0, "back on empyty StrBlob");
	return data->back();
}

inline void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}



class StrBlobPtr
{
	friend bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	
	string &deref() const;
	StrBlobPtr incr(); // 前置递增
	StrBlobPtr decr(); // 前置递减
	

private:
	shared_ptr<vector<string>> check(size_t, const string &) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
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

inline string &StrBlobPtr::deref() const 
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline StrBlobPtr StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline StrBlobPtr StrBlobPtr::decr()
{
	--curr;
	check(-1, "increment past end of StrBlobPtr");
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

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
	{
		// 两个指针都有空的，或者都指向相同的元素
		return (!r || lhs.curr == rhs.curr);
	}
	else
	{
		return false;
	}
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}