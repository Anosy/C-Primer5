#include<iostream>

using namespace std;

class Base
{
public:
	void pub_mem() {}
protected:
	int prot_mem() {}
private:
	char priv_mem() {}
};

struct Pub_Derv:public Base
{
	int f() { return prot_mem(); }
	void memfcn(Base &b)
	{
		b = *this;
		cout << "Pub_Derv" << endl;
	}
};

struct Priv_Derv :private Base
{
	int f1() { return prot_mem(); }
	void memfcn(Base &b)
	{
		b = *this;
		cout << "Priv_Derv" << endl;
	}
};

struct Prot_Derv :protected Base
{
	int f1() { return prot_mem(); }
	void memfcn(Base &b)
	{
		b = *this;
		cout << "Priv_Derv" << endl;
	}
};


int main()
{

	Pub_Derv d1;
	d1.pub_mem(); // ��ȷ
	//d1.prot_mem(); // ����������Ķ����޷����ʻ���ĳ�Ա
	Base *p = &d1; // ��ȷ

	Priv_Derv d2;
	//d2.pub_mem(); // ����private�̳е�����������޷����ʻ����Ա
	//Base p = &d2; // ���󣺷ǹ����̳��������޷������ת��

	Prot_Derv d3;
	//d3.pub_mem(); //����protect�̳е�����������޷����ʻ����Ա
	//Base p = &d3;// ���󣺷ǹ����̳��������޷������ת��

}