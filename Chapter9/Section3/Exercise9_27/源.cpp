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
		if (*curr % 2 !=0)  // ���ɾ���Ļ���ɾ����Ԫ��ǰ��Ԫ�ز���ɾ��
		{
			curr = flist.erase_after(prev);
		}
		else  // ���û��ɾ����ָ���һ��Ԫ�أ�ͬ��ָ��ǰ��Ԫ��Ҳ����ƶ�����ǰλ��
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