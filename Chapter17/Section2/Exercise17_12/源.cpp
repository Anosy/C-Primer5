#include"Exam.h"

int main()
{
	exam<100> ex100;
	for (unsigned i = 1; i <= 100; i = i + 5)
	{
		ex100.set_solution(i, 1);
	}
	cout << ex100 << endl;

	bitset<100> bset100;
	bset100.set(1, 1);
	bset100.set(6, 1);

	cout << ex100.score(bset100) << endl;
	system("pause");
	return 0;
}