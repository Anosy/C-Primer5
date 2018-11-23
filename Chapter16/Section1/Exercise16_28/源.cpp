#include"SP_UP.h"
#include<vector>
#include<string>
#include<memory>

using namespace std;

int main()
{
	vector<string> vStr = { "Hello", "World", "!" };
	SP<vector<string>> ptr(new vector<string>(vStr));

	for (auto i = 0; i != ptr->size(); ++i)
		cout << (*ptr)[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}