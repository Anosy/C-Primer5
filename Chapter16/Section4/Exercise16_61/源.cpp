#include<memory>
#include<iostream>
#include<string>

template <typename T, typename ... Args>
std::shared_ptr<T> my_make_shared(Args && ... args)
{
	return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main()
{
	int a = 42;
	auto num = my_make_shared<int>(a);
	std::cout << *num << std::endl;

	auto str = my_make_shared<std::string>(10, 'c');
	std::cout << *str << std::endl;

	system("pause");
	return 0;
}