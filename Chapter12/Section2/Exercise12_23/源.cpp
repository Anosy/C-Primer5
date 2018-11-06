#include<iostream>
#include<string>
#include<memory>
#include<cstring>

using namespace std;

int main()
{
	const char * char1 = "ni";
	const char * char2 = "hao";

	char *r = new char[strlen(char1) + strlen(char2) + 1];
	strcpy(r, char1);
	strcat(r, char2);
	cout << r << endl;

	string str1 = "ni";
	string str2 = "hao";
	strcpy(r, (str1 + str2).c_str());
	cout << r << endl;

	delete[] r;
	
	system("pause");
	return 0;
}