#include"Blob.h"
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> vStr = { "Hello", "World", "!" };
	Blob<string> b(vStr.begin(), vStr.end());

	for (size_t i = 0; i != b.size(); ++i)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}