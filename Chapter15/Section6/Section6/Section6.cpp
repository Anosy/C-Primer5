#include<iostream>

using namespace std;

class Base
{
public:
	virtual void fcn() { cout << "����fcn����" << endl; }
};

class D1 :public Base
{
public:
	// �����˻����fcn()�����Ǹ���
	void fcn(int) { cout << "D1������fcn(int)����" << endl; }
	virtual void f2() { cout << "D1������f2����" << endl; }
};

class D2 :public D1
{
public:
	void fcn(int) { cout << "D2������fcn(int)����" << endl; }
	void fcn(){ cout << "D2������fcn����" << endl; }
	void f2() { cout << "D2������f2����" << endl; }
};

int main()
{
	Base bobj; D1 d1obj; D2 d2obj;
	
	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn(); // ���û����
	bp2->fcn(); // ���û����
	bp3->fcn(); // ����D2��
	cout << endl;

	D1 *d1p = &d1obj; D2 *d2p = &d2obj;
	//bp2->f2(); //���󣺻���û��f2
	d1p->f2(); // ����D1��
	d2p->f2(); // ����D2��


	system("pause");
	return 0;
}