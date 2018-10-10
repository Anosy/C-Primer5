#include<iostream>
#include<string>
using namespace std;

int main()
{
	int arr[10]; // 含有10个整数的数组
	
	constexpr unsigned sz = 42;
	int *parr[sz]; // 含有42个整型指针的数组

	int ia1[3] = { 0 ,1, 2 };  // 含有三个元素的数组， 元素分别是0,1,2

	int ia2[] = { 1, 2, 3 }; // 含有三个元素的数组，元素分别是1，2，3

	string a4[3] = { "hi", "bye" }; // 含有三个元素的数组，元素分别是hi , bye， ''

	char a1[] = { 'C', '+', '+' }; // 含有三个元素的数组，元素分别是C, +, +

	char a2[] = "C++"; // 含有四个元素的数组，元素分别是C, +, +, ''

	int *ptr[10]; // ptr是含有10个元素的整型指针数组

	int(*Parray)[10] = &arr; // Parray是指向含有10个整型元素的数组

}