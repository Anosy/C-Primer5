#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;

int main()
{
	string str = "Hello";
	string phrase = "Hello World";
	string slang = "Hiya";
	
	bool ture_or_false = str > phrase;
	cout << ture_or_false << endl;

	ture_or_false = slang > phrase;
	cout << ture_or_false << endl;


	system("pause");
	return 0;
}