#include<string>
#include<iostream>
#include<memory>
#include<utility>

using namespace std;

class StrVec
{
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){}
	StrVec(const StrVec&); // 拷贝构造函数
	StrVec &operator=(const StrVec&); // 拷贝赋值运算符
	~StrVec(); // 析构函数
	void push_back(const string &); // 拷贝元素
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }

private:
	static allocator<string> alloc; // 分配元素
	void chk_n_alloc() { if (size() == capacity()) reallocate(); } // 保证StrVec至少有容纳一个新元素的空间，如果没有那么调用reallocate
	pair<string *, string *> alloc_n_copy(const string *, const string *); // 会分配内存，拷贝一个给定范围中的元素
	void free();  // 摧毁构造的元素并且释放内存
	void reallocate(); // 在内存用完的生活为StrVec分配新的内存
	string *elements; // 指向分配的内存中的首元素
	string *first_free; // 指向最后一个实际元素之后的位置
	string *cap; // 指向分配的内存末尾之后的位置
};

void StrVec::push_back(const string &s)
{
	chk_n_alloc(); // 确保有空间能够容纳新的元素
	// 在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

// 返回的pair返回的两个指针分别表示新空间开始的位置和拷贝的尾后的位置
pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	// 不能传递给deallocate一个空的指针
	if (elements)
	{
		// 逆序销毁内存
		for (auto p = first_free; p != elements; )
		{
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
	cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec&rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
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
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}