#include<string>
#include<vector>
#include<iostream>
#include<memory>
#include<initializer_list>

using namespace std;

template <typename T> class BlobPtr; // 先声明模板类

template <typename T> class Blob
{
	friend class BlobPtr<T>; // 将模板类给实例化为T类型。然后将其给作为当前类的友元
	//template <typename T> friend class BlobPtr; // 将BlobPtr的每个实例都作为Blob类的友元
	friend bool operator ==<T>
		(const Blob<T>& lhs, const Blob<T>& rhs);
	friend bool operator !=<T>
		(const Blob<T>& lhs, const Blob<T>& rhs);

public:
	typedef typename vector<T>::size_type size_type;
	Blob():data(make_shared<vector<T>>()) {};
	Blob(initializer_list<T> il) :data(make_shared<vector<T>>(il)) {}
	size_type size() { return data->size(); }
	bool empty() { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	T &front();
	T &back();
	T &operator[] (size_type i);

private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const string &msg);
};

template <typename T>
void Blob<T>::check(size_type i, const string &msg)
{
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T>
T & Blob<T>::front()
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T & Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T & Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
bool operator==(const Blob<T> & lhs, const Blob<T> &rhs)
{
	return lhs.data == rhs.data;
}
template <typename T>
bool operator!=(const Blob<T> & lhs, const Blob<T> &rhs)
{
	return lhs.data != rhs.data;
}



// 类BlobPtr部分

template <typename T>
bool operator ==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
bool operator != (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);


template <typename T> class BlobPtr
{
	friend bool operator ==<T>
		(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

	friend bool operator !=<T>
		(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0):wptr(a.data), curr(sz){ }
	T &operator*()
	{
		auto p = check(0, "dereference past end");
		return (*p)[curr];
	}
	BlobPtr &operator++();
	BlobPtr &operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);


private:
	shared_ptr<vector<T>> check(size_t i, const string &msg);
	weak_ptr<vector<T>> wptr;
	size_t curr;
};

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg)
{
	auto ret = wptr.lock();
	if (!ret)
	{
		throw runtime_error("unbound BlobPtr");
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past end of BlobPtr");
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	auto ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	auto ret = *this;
	--*this;
	return ret;
}

template <typename T> 
bool operator==(const BlobPtr<T> & lhs, const BlobPtr<T> &rhs)
{
	return (lhs.wptr.lock() == rhs.wptr.lock()) && lhs.curr == rhs.curr;
}

template <typename T> 
bool operator!=(const BlobPtr<T> & lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}




