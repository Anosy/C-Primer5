#include<iostream>
int main()
{
	// currVal����������ͳ��������val�����Ǹոն������
	int currVal = 0, val = 0;
	std::cout << "��������Ҫ����������: " << std::endl;
	// ��ȡ��һ����������ȷ�������ֿ��Դ���
	if (std::cin >> currVal)
	{
		int cnt = 1;
		while (std::cin >> val)
		{
			if (currVal == val)   // ���������ͬ����ô������+1
			{
				cnt++;
			}
			else  // ���򣬴�ӡǰһ������
			{
				std::cout << currVal << " occurs " << cnt << " times " << std::endl;
				currVal = val;   // ��ס�µ���
				cnt = 1;	// ���ü�����
			}
		}
		// ��ӡ����������
		std::cout << currVal << " occurs " << cnt << " times " << std::endl;

	}	
	system("pause");
	return 0;
}