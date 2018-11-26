#ifndef EXAM_H
#define EXAM_H

#include<bitset>
#include<iostream>
#include<vector>

using namespace std;

template <size_t N>
class exam
{
	friend ostream & operator << <N>(ostream &os, const exam<N>& e);
public:
	exam() : bset() {}
	size_t get_size() { return N; }
	void set_solution(size_t n, bool b)
	{
		bset.set(n, b);
	}
	bitset<N> get_solution() const { return bset; }
	size_t score(const bitset<N> &rhs);

private:
	bitset<N> bset;
};

template <size_t N>
size_t exam<N>::score(const bitset<N> &rhs)
{
	size_t ret = 0;
	for (size_t i = 0; i != N; i++)
	{
		if (bset[i] == rhs[i])
		{
			++ret;
		}
	}
	return ret;
}

template <size_t N>
ostream & operator << (ostream &os, const exam<N>& e)
{
	os << e.bset;
	return os;
}

#endif // !EXAM_H
