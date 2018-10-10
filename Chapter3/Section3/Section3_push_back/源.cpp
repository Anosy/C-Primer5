#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;

int main()
{
	vector<int> v2; // ø’vector∂‘œÛ
	for (int i = 0; i < 100; i++)
	{
		v2.push_back(i);
	}
	std::cout << v2.size() << std::endl;

	string word;
	vector<string> text;
	while (std::cin >> word)
	{
		text.push_back(word);
	}
	std::cout << text.size() << std::endl;


	system("pause");
	return 0;
}