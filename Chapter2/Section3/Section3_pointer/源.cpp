#include<iostream>
using namespace std;
// 本部分主要是介绍指针
int main()
{
	int *ip1, *ip2; // ip1和ip2都是指向int型对象的指针,
	double dp, *dp2; // dp2是指向double型对象的指针，dp是double型对象
	

	// 获取对象地址(取址符为&)
	int ival = 42;
	int *p = &ival; // p存放变量ival的地址, 或者说p是指向变量ival的指针
	cout << p << endl; // 输出的结果为地址

	double dval=11.00;
	double *pd = &dval; // 正确：初始值是double型对象的地址
	double *pd2 = pd;  // 正确：初始值是指向double型对象的指针

	// 错误：int *pi = pd; 指针pi和指针pd的类型不匹配
	// 错误：pi = &dval;  试图将double型对象的地址给赋值给int型指针
	

	// 利用指针来访问对象(解引用符为*)
	cout << *p << endl; // 由符号*得到指针p所指的对象，输出为42
	*p = 0;
	cout << *p << endl; // 输出为0

	// 空指针定义（指针不指向任何对象）
	int *p1 = nullptr;
	int *p2 = 0;
	
	//错误：int zero = 0; pi = zero; 不能将int变量直接赋值给指针，即使int变量的初始值为0


	// 指针和赋值(给指针赋值就是让他存放新的地址，从而指向一个新的对象)
	int i = 42;
	int *pi = 0;  // pi被初始化，但没有指向任何对象
	int *pi2 = &i; // pi2被初始化，存在i的地址
	int *pi3; 
	
	pi3 = pi2; // pi3和pi2指向同一个对象i
	pi2 = 0; // 现在pi2不指向任何对象, 但是pi3还是指向对象i
	cout << *pi3 << endl;  // 输出为42


	// 判断是改变了指针的值，还是改变指针所指的对象的值
	pi = &ival; // 改变了指针的值，现在指针指向了ival的地址
	*pi = 0; // 改变了ival的值，指针pi还是指向ival的地址
	cout << ival << endl;; // 输出0


	// 指向指针的指针
	int ival1 = 1024;
	int *pi1 = &ival1;  // 定义指针pil指向变量ival1
	int **ppi1 = &pi1;  // 定义指针ppil指向指针pil, 定义指向指针的指针需要使用(**)
	// 输出:00E1F8D8 00E1F8D8 00E1F8E4 00E1F8E4 1024 1024
	// 表示指针ppi1指向指针pi1的地址，ppil所指的对象pi1的值为pil指针指向的ival1的地址,访问原始的对象就需要解应用两次**
	cout << ppi1 << " " << &pi1 << " " << *ppi1 << " " << pi1 << " " << *pi1 << " " << **ppi1 << endl;


	// 指向指针的引用
	int t = 44;
	int *p; // p是一个int型指针
	int *&r = p; // r是对指针p的一个引用

	r = &t; // 由于r引用了一个指针，那么对r来赋值其实就是使得指针指向t
	*r = 0; // 解引用得到i，也就是p指向的对象,将i的值给改为了0



	system("pause");
	return 0;
}