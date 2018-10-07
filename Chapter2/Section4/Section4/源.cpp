#include<iostream>
int main()
{
	const int bufSize = 512; // 输入缓冲区的大小
	// bufSize=120; 错误：试图向ocnst对象写入值


	// 初始化
	const int i = 42; // 正确
	// const int k; 错误：const对象必须初始化
	const int ci = i; // 正确：i的值被拷贝给了ci
	int j = ci; // 正确:ci的值给拷贝给了j

	
	// const的引用
	const int ct = 1024;
	const int &r1 = ct; // 正确：引用以及其对应的对象都是常量
	// r1 = 42; 错误：r1是对常量的引用,因此不能够通过引用来改变常量的值
	// int &r2 = ci;  错误：试图让一个非常量引用指向一个常量对象，因为如果r2不是常量引用那么，其值可以被赋值那么将会影响ci常量值的变化
	int t = 42;
	const int &r2 = t; // 允许const int &绑定到一个普通的int 对象上
	const int &r3 = 42; // 正确, 这是特殊的情况，如果不是常量引用的话，那么引用的初始值必须是一个对象
	const int &r4 = r2 * 2; // 正确
	// int &r5 = r2 * 2; 错误：因为r2是常量引用，从而r5必须也得是常量引用

	double dval = 3.14;
	const int &ri = dval; // 正确：这是常量引用的另外一个特殊情况。即引用的类型可以和其被引用对象的类型不相同，因为其创建了一个temp临时变量

	// 对const的引用可能引用一个非const的对象
	int k = 42;
	int &ki = k;
	const int &k2 = k; // k2也绑定对象i，但是不允许通过r2修改i的值
	ki = 0;
	// k2 = 0; 错误 k2为常量引用，因此其不能修改k的值


	//指针和const(弄清声明的含义最有效的方法就是从右往左读)
	int errNumb = 0;
	int *const curErr = &errNumb; // 将curErr将一直指向errNumb
	const double pi = 3.1415926;
	const double *const pip = &pi; // pip是一个指向常量对象的常量指针\]（pip是一个常量指针，指向的是双精度浮点型的常量）

	// *pip = 2.71; 错误：pip是指向常量的指针，因此不能改变其指向对象的值
	*curErr = 10;
	std::cout << errNumb << std::endl;


	system("pause");
	return 0;
}