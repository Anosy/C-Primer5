#include<iostream>

using namespace std;

class numbered
{
public:
	// 13.14
	numbered() { mysn = seq++; }
	// 13.15
	numbered(const numbered& n) { mysn = seq++; }

	int mysn = 0;
private:
	static int seq; // 静态成员在类内声明在类外定义, 全部类成员共享一个static成员
};

int numbered::seq = 0;

void f(numbered s) { cout << s.mysn << endl; }
//void f(const numbered &s) { cout << s.mysn << endl; }

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	system("pause");
	return 0;
}