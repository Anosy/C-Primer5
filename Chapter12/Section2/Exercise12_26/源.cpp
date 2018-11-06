#include<iostream>
#include<memory>
#include<string>

using namespace std;

int main()
{
	allocator<string> alloc;
	auto const  p = alloc.allocate(100);

	string s;
	string *q = p;
	while (cin >> s && q != p+ 100)
	{
		alloc.construct(q++, s);
	}
	size_t size = q - p;

	for (unsigned i = 0; i < size; ++i)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	while (q!=p)
	{
		alloc.destroy(--q);
	}
	alloc.deallocate(p, 100);

	system("pause");
	return 0;
}