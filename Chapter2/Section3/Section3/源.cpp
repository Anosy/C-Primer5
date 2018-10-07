#include<iostream>
// 本部分中主要是对引用的介绍
using namespace std;
int main()
{
	int ival = 1024;
	int &refVal = ival; //  refVal指向了ival（给ival变量取了另外一个名字）
	// 错误语句 int &refVal2; 因为引用必须被初始化
	refVal = 2; // 把2赋值给reVal指向的对象，此处将值给赋值给了ival
	int ii = refVal; // 把ival的值给赋值给reaVal,等价与ii = ival;
	
	int &refVal3 = refVal; // 将refVal3也给绑定到ival上
	
	int i = refVal; // 将ival的值拿来初始化i

	// 错误语句 int &refVal4 = 10; 因为引用必须指向一个实际存在的对象，而非字面值常量
	// 错误语句 double dval = 3.14; int &refVal5 = dval; 因为引用的类型要和绑定对象严格的匹配

	int a, &ra = a;
	a = 5, ra = 10;
	cout << a << ra << endl; // 得到的结果为10 10

	system("pause");
	return	0;
}
