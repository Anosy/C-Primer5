#include<iostream>	
// 通过使用using声明，我们可以使用标准库中的名字
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int v1, v2;
	cin >> v1 >> v2;
	cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;
	
	system("pause");
	return 0;
}