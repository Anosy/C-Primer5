#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;
using placeholders::_1;

int main()
{
	vector<int> vec{ 1, 111, 1111, 11111 };
	auto count =count_if(vec.begin(), vec.end(), bind(greater<int>(), _1, 1024));
	cout << count << endl;

	vector<string> svec{ "pooh", "pooh", "pezy", "pooh" };
	auto found = find_if(svec.begin(), svec.end(), bind(equal_to<string>(), _1, "pooh"));
	cout << *found << endl;

	transform(vec.begin(), vec.end(), vec.begin(), bind(multiplies<int>(), _1, 2));

	for (int i : vec)
	{
		cout << i << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}