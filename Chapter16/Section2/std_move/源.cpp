#include<iostream>
#include<type_traits>

using namespace std;

template <typename T>
typename remove_reference<T>::type&& move(T &&t)
{
	return static_cast<typename remove_reference<T>::type&&>(t);
}

