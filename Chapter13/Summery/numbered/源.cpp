#include<iostream>

using namespace std;

class numbered
{
public:
	numbered() { mysn = seq++; }
	numbered(const numbered&) { mysn = seq++; }

	int mysn = 0;
private:
	static int seq;
};

void f(numbered s)
{
	cout << s.mysn << endl;
}

void f2(const numbered &s)
{
	cout << s.mysn << endl;
}

int numbered::seq = 0;


int main()
{
	numbered a, b = a, c = b;
	f2(a), f2(b), f2(c);

	system("pause");
	return 0;
}