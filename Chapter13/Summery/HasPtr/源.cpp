#include"HasPtr.h"
#include<vector>
#include<algorithm>

int main()
{
	vector<HasPtr> vh;
	int n = 10;
	for (int i = 0; i < n; ++i)
	{
		vh.push_back(to_string(n - i));
	}
	for (auto p : vh)
	{
		cout << *p << " ";
	}
	cout << endl;

	sort(vh.begin(), vh.end());

	for (auto p : vh)
	{
		cout << *p << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}