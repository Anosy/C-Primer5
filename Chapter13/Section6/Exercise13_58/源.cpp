#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Foo
{
public:
	Foo sorted() && ;
	Foo sorted() const &;
private:
	vector<int> data;
};


Foo Foo::sorted() &&
{
	cout << "��ֵ���ð汾" << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	cout << "��ֵ���ð汾" << endl;
	//Foo ret(*this);
	//return ret.sorted();
	return Foo(*this).sorted();
}

int main()
{
	Foo f;
	f.sorted();
	
	system("pause");
	return 0;
}