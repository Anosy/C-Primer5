#include<string>
#include<iostream>
#include<memory>
#include<utility>

using namespace std;

class StrVec
{
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){}
	StrVec(const StrVec&); // �������캯��
	StrVec &operator=(const StrVec&); // ������ֵ�����
	~StrVec(); // ��������
	void push_back(const string &); // ����Ԫ��
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }

private:
	static allocator<string> alloc; // ����Ԫ��
	void chk_n_alloc() { if (size() == capacity()) reallocate(); } // ��֤StrVec����������һ����Ԫ�صĿռ䣬���û����ô����reallocate
	pair<string *, string *> alloc_n_copy(const string *, const string *); // ������ڴ棬����һ��������Χ�е�Ԫ��
	void free();  // �ݻٹ����Ԫ�ز����ͷ��ڴ�
	void reallocate(); // ���ڴ����������ΪStrVec�����µ��ڴ�
	string *elements; // ָ�������ڴ��е���Ԫ��
	string *first_free; // ָ�����һ��ʵ��Ԫ��֮���λ��
	string *cap; // ָ�������ڴ�ĩβ֮���λ��
};

void StrVec::push_back(const string &s)
{
	chk_n_alloc(); // ȷ���пռ��ܹ������µ�Ԫ��
	// ��first_freeָ���Ԫ���й���s�ĸ���
	alloc.construct(first_free++, s);
}

// ���ص�pair���ص�����ָ��ֱ��ʾ�¿ռ俪ʼ��λ�úͿ�����β���λ��
pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	// ���ܴ��ݸ�deallocateһ���յ�ָ��
	if (elements)
	{
		// ���������ڴ�
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