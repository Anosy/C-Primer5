#include<iostream>
#include<memory>
#include<vector>
#include<string>

using namespace std;

shared_ptr<vector<string>> new_ptr()
{
	return shared_ptr<vector<string>>(new vector<string>());
}

void read(shared_ptr<vector<string>> ptr)
{
	string s;
	while (cin >> s)
	{
		ptr->push_back(s);
	}
}

void print(shared_ptr<vector<string>> ptr)
{
	for (const auto &p : *ptr)
	{
		cout << p << " ";
	}
	cout << endl;
}

int main()
{
	shared_ptr<vector<string>> pv = new_ptr();
	if (!pv)
	{
		cout << "ÄÚ´æ²»×ã" << endl;
		return -1;
	}
	read(pv);
	print(pv);

	system("pause");
	return 0;
}