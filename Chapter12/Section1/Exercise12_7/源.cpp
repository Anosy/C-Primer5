#include<vector>
#include<iostream>
#include<memory>

using namespace std;

shared_ptr<vector<int>> new_vector()
{
	return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>> p)
{
	int v;
	while (cin >> v)
	{
		p->push_back(v);
	}
}

void print_ints(shared_ptr<vector<int>> p)
{
	for (const auto &v : *p)
	{
		cout << v << " ";
	}
	cout << endl;
}

int   main()
{
	auto p = new_vector();
	read_ints(p);
	print_ints(p);

	system("pause");
	return 0;
}

