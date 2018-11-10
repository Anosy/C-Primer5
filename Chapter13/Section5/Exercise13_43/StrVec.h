#include<string>
#include<memory>
#include<utility>
#include<initializer_list>
#include<algorithm>

using namespace std;

class StrVec
{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
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
	StrVec &operator=(const StrVec&);
	~StrVec();
	void push_back(const string &);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }
	void reserve(size_t n) { if (n > capacity()) reallocate(); }
	void resize(size_t n);
	void resize(size_t n, const string &s);

private:
	static allocator<string> alloc;
	string *elements;
	string *first_free;
	string *cap;
	void chk_n_alloc()
	{
		if (size() == capacity())
		{
			reallocate();
		}
	}
	pair<string *, string *> alloc_n_copy(const string *, const string *);
	void free();
	void reallocate();
};
void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) };
}


void StrVec::free()
{
	if (elements)
	{
		for_each(elements, first_free, [](string &s) {alloc.destroy(&s); });
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec&rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

void StrVec::reallocate()
{
	auto new_capacity = size() ? size() * 2 : 1;
	auto new_data = alloc.allocate(new_capacity);
	auto dest = new_data;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, move(*elem++));
	}
	free();
	elements = new_data;
	first_free = dest;
	cap = elements + new_capacity;
}

inline
void StrVec::resize(size_t n)
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
			alloc.destroy(--first_free);
		}
	}
}

inline
void StrVec::resize(size_t n, const string &s)
{
	if (n > size())
	{
		while (size() < n)
		{
			push_back(s);
		}
	}
}