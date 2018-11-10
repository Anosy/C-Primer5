#include"HasPtr1.h"
#include"HasPtr2.h"

int main()
{
	//HasPtr1 h("hi bob!");
	//HasPtr1 h2(h); // 这里两者的所有的值是相同的，但是各自成员指针所指对象的地址是不同的
	//HasPtr1 h3 = h;
	//HasPtr1 h4;

	////h2 = "hi mike";
	////h3 = "hi jack";
	//h4 = h;

	//cout << "h:" << *h << endl;
	//cout << "h2:" << *h2 << endl;
	//cout << "h3:" << *h3 << endl;
	//cout << "h4:" << *h4 << endl;

	//cout << "h和h两者的指针是否相同:" << comp(h, h) << endl;
	//cout << "h和h2两者的指针是否相同:" << comp(h, h2) << endl;
	//cout << "h和h4两者的指针是否相同:" << comp(h, h4) << endl;

	HasPtr2 h("hi bob!");
	HasPtr2 h2(h); // 使用的是合成拷贝构造函数，至少简单的复制了ps对象，这时候两对象的成员指针指向的是相同的地方，改变其中一个值将影响另外一个

	h2 = "hi mike";

	cout << "h:" << *h << endl;
	cout << "h2:" << *h2 << endl;

	cout << "h和h两者的指针是否相同:" << comp2(h, h) << endl;
	cout << "h和h2两者的指针是否相同:" << comp2(h, h2) << endl;


	system("pause");
	return 0;
}