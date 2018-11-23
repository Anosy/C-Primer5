#include <iostream>
#include <memory>
#include <sstream>

template <typename T> void f(T)
{
	std::cout << "f(T)\n";
	std::cout << typeid(T).name() << std::endl;
}
template <typename T> void f(const T*)
{
	std::cout << "f(const T*)\n";
	std::cout << typeid(T).name() << std::endl;
}
template <typename T> void g(T)
{
	std::cout << "void g(T)\n";
	std::cout << typeid(T).name() << std::endl;
}
template <typename T> void g(T *)
{
	std::cout << "void g(T*)\n";
	std::cout << typeid(T).name() << std::endl;
}

int main()
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;

	g(42);
	g(p);
	g(ci);
	g(p2);
	std::cout << std::endl;
	f(42);
	f(p);
	f(ci);
	f(p2);


	system("pause");
	return 0;
}