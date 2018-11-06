#include<memory>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	allocator<string> alloc;
	auto p = alloc.allocate(100);
	string s;
	auto *q = p;
	while (cin >> s && q != p + 100)
	{
		alloc.construct(q++, s);
	}
	size_t size = q - p;
	for (size_t i = 0; i != size; ++i)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	while (q != p)
	{
		alloc.destroy(--q); // q++多加了一次
	}
	alloc.deallocate(p, 100);

	system("pause");
	return 0;
}