#include<list>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	list<int> listi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = listi.begin();
	
	while (iter != listi.end())
	{
		if (*iter % 2 ==0)
		{
			iter = listi.erase(iter);
		}
		else
		{
			iter = listi.insert(iter, *iter);
			++iter;
			++iter;
		}
	}

	for (auto l : listi)
	{
		cout << l << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}