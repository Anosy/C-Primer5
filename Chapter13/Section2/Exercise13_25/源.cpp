#include"HasPtr1.h"
#include"HasPtr2.h"

int main()
{
	//HasPtr1 h("hi bob!");
	//HasPtr1 h2(h); // �������ߵ����е�ֵ����ͬ�ģ����Ǹ��Գ�Աָ����ָ����ĵ�ַ�ǲ�ͬ��
	//HasPtr1 h3 = h;
	//HasPtr1 h4;

	////h2 = "hi mike";
	////h3 = "hi jack";
	//h4 = h;

	//cout << "h:" << *h << endl;
	//cout << "h2:" << *h2 << endl;
	//cout << "h3:" << *h3 << endl;
	//cout << "h4:" << *h4 << endl;

	//cout << "h��h���ߵ�ָ���Ƿ���ͬ:" << comp(h, h) << endl;
	//cout << "h��h2���ߵ�ָ���Ƿ���ͬ:" << comp(h, h2) << endl;
	//cout << "h��h4���ߵ�ָ���Ƿ���ͬ:" << comp(h, h4) << endl;

	HasPtr2 h("hi bob!");
	HasPtr2 h2(h); // ʹ�õ��Ǻϳɿ������캯�������ټ򵥵ĸ�����ps������ʱ��������ĳ�Աָ��ָ�������ͬ�ĵط����ı�����һ��ֵ��Ӱ������һ��

	h2 = "hi mike";

	cout << "h:" << *h << endl;
	cout << "h2:" << *h2 << endl;

	cout << "h��h���ߵ�ָ���Ƿ���ͬ:" << comp2(h, h) << endl;
	cout << "h��h2���ߵ�ָ���Ƿ���ͬ:" << comp2(h, h2) << endl;


	system("pause");
	return 0;
}