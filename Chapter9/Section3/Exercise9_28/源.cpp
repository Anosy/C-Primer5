#include<iostream>
#include<string>
#include<forward_list>

using namespace std;

int main()
{
	forward_list<string> flist = { "aa", "bb", "cc", "dd", "ee" , "bb"};
	string str1 = "bb";
	string str2 = "ff";

	bool inserted = false;
	auto prev = flist.before_begin();
	auto curr = flist.begin();

	while (curr != flist.end())
	{
		if (*curr == str1)
		{
			curr = flist.insert_after(curr, str2);
			inserted = true;
		}
		else
		{
			prev = curr;
			++curr;
		}
		if (!inserted)
		{
			flist.insert_after(prev, str2);
		}
	}

	for (const auto f : flist)
	{
		cout << f << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}