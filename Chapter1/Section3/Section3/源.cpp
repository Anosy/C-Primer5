#include<iostream>
/*
 *����������
 *��ȡ��������������֮��ĺ�
 */
int main()
{
	//��ʾ�û�������������	
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;  //�������Ƕ�����������ݵı���
	std::cin >> v1 >> v2; //��ȡ��������
	std::cout << "The sum of " 
		<< v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
	system("pause");
	return 0;
}