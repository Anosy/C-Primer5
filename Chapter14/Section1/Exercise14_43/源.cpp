#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;

int main()
{
	vector<int> data = { 2, 3, 4, 5 };
	int input;
	cin >> input;
	modulus<int> mod;
	auto predict = [&](int i) {return 0 == mod(input, i); };
	auto result = all_of(data.begin(), data.end(), predict);
	cout << ((result) ? "Yes" : "No") << endl;
	
	system("pause");
	return 0;
}