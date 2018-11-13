#include"IntCompare.h"


int main()
{
	vector<int> vec = { 1,2,3,2,1 };
	const int oldValue = 2;
	const int newValue = 200;
	IntCampare ic(oldValue);
	replace_if(vec.begin(), vec.end(), ic, newValue);

	for (auto v : vec)
	{
		cout << v << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}