#include"Sales_data.h"

using namespace std;

int main()
{
	Sales_data item1, sum;

	// 处理异常版本
	while (cin >> item1 >> sum)
	{
		try
		{
			sum += item1;
			cout << sum << endl;
		}
		catch (const isbn_mismatch &e)
		{
			cerr << e.what() << ":left isbn(" << e.left << ") right isbn(" << e.right << ")" << endl;
		}
	}

	// 不处理异常版本
	//while (cin >> item1 >> sum)
	//{
	//		sum += item1;
	//		cout << sum << endl;
	//}

	system("pause");
	return 0;
}