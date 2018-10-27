#include<forward_list>
#include<iostream>

using namespace std;

int main()
{
	forward_list<int> flist = { 1,3,5,4,6,8 };
	auto prev = flist.before_begin();
	auto curr = flist.begin();

	while (curr!=flist.end())
	{
		if (*curr % 2 !=0)  // 如果删除的话，删除的元素前的元素不用删除
		{
			curr = flist.erase_after(prev);
		}
		else  // 如果没有删除，指向后一个元素，同样指向前驱元素也向后移动到当前位置
		{
			prev = curr;
			++curr;
		}
	}

	for (auto f : flist)
	{
		cout << f;
	}
	cout << endl;

	system("pause");
	return 0;
}