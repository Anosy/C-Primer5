#include<iostream>
#include<memory>
#include<vector>
#include<string>

using namespace std;

vector<string> *new_ptr()
{
	return new (nothrow) vector<string>;
}

void read(vector<string> *v)
{
	string str;

	while (cin>>str)
	{
		v->push_back(str);
	}
}

void print(vector<string> *v)
{
	for (const auto &i : *v)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	auto ptr = new_ptr();
	read(ptr);
	print(ptr);
	delete ptr;
	ptr = nullptr;
	

	system("pause");
	return 0;
}