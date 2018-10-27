#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> iv = { 1, 1, 1, 3, 1 };
	int some_val = 1;

	auto iter = iv.begin();
	int org_size = iv.size () , new_ele = 0;

	while (iter != (iv.begin() + org_size/2 + new_ele))
	{
		if (*iter == some_val)
		{
			iter = iv.insert(iter, 2 * some_val);
			++new_ele;
			iter = iter + 2;
		}
		else
		{
			++iter;
		} 
	}

	for (const auto v : iv)
	{
		cout << v;
	}
	cout << endl;

	system("pause");
	return 0;
}