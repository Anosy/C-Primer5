#include<string>
#include<memory>
#include<utility>
#include<initializer_list>
#include<algorithm>

using namespace std;

class StrVec
{
public:
	StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}
	StrVec(initializer_list<string> il)
	{
		auto newdata = alloc_n_copy(il.begin(), il.end());
		elements = newdata.first;
		first_free = cap = newdata.second;
	}
	StrVec(const StrVec & rhs)
	{
		auto newdata = alloc_n_copy(rhs.elements, rhs.first_free);
		elements = newdata.first;
		first_free = cap = newdata.second;
	}
	StrVec &operator = (const StrVec&);
	~StrVec() { free(); };
	void push_back(const string &s);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }
	void reserve(size_t n) { if (n > capacity()) reallocate(); };
	void resize(size_t n);
	void resize(size_t n, const string &s);
	StrVec(StrVec &&rhs) noexcept // 移动构造函数
		:elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
	{
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	StrVec &operator=( StrVec&& rhs) noexcept
	{
		if (this != &rhs)
		{
			free();
			elements = rhs.elements;
			first_free = rhs.first_free;
			cap = rhs.cap;
			rhs.elements = rhs.first_free = rhs.cap = nullptr;
		}
		return *this;
	}

private:
	static allocator<string> alloc;
	string *elements;
	string *first_free;
	string *cap;
	void chk_n_alloc();
	void free();
	void reallocate();
	pair<string *, string *> alloc_n_copy(const string *, const string *);

};

allocator<string> StrVec::alloc;

void StrVec::chk_n_alloc()
{
	if (size() == capacity())
	{
		reallocate();
	}
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) }; //将b,e之间拷贝到data开始指向的位置
}

void StrVec::free()
{
	if (elements)
	{
		for_each(elements, first_free, [](const string &s) {alloc.destroy(&s); });
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec & StrVec::operator=(const StrVec &s)
{
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i < size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

inline void StrVec::resize(size_t n)
{
	if (n > size())
	{
		while (size() < n)
		{
			push_back("");
		}
	}
	else if (n < size())
	{
		while (size() > n)
		{
			alloc.destroy(first_free--);
		}
	}
}

inline void StrVec::resize(size_t n, const string &s)
{
	if (n > size())
	{
		while (size() < n)
		{
			push_back(s);
		}
	}
	else if (n < size())
	{
		while (size() > n)
		{
			alloc.destroy(first_free--);
		}
	}
}