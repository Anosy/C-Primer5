#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	string words, results;
	while (cin >> words)
	{
		results = results + words + " ";
	}

	cout << results << endl;
	system("pause");
	return 0;
}