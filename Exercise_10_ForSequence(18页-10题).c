/*
���⣺��p.18ҳ��10�⣩
10.  ��2010 �������������⡿
�轫 n  (n>1) ��������ŵ�һά���� R �С������һ����ʱ��Ϳռ������涼�����ܸ�Ч���㷨��
�� R �б��������ѭ������ p (0 <p <n����λ�ã����� R �е������ɣ�X0,X1......Xn-1) �任Ϊ
��Xp��Xp+1......Xn-1, X0��X1......Xp-1)��Ҫ��

 (1) �����㷨�Ļ������˼�롣
 (2) �������˼�룬���� C �� C++�� Java ���������㷨���ؼ�֮������ע�͡�
 (3) ˵����������㷨��ʱ�临�ӶȺͿռ临�Ӷȡ�
˼·������ͬ��8��
ע�⣺
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 3

void printSequenceList(int twoSequenceList[])
{
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", twoSequenceList[i]);
	}
}

int * reserveSequenceList1(int twoSequenceList[], int m, int n)			// ע������m n��������±�
{
	while (m < n)
	{
		int tempData = twoSequenceList[m];
		twoSequenceList[m] = twoSequenceList[n];
		twoSequenceList[n] = tempData;
		m++;
		n--;
	}
	return twoSequenceList;
}

// ��ת---ע�⺯���ķ���ֵһ��������ջ�����ĵ�ַ
int *reserveSequenceList(int twoSequenceList[], int m, int n)   // 
{
	// 1.�����巴תһ��
	twoSequenceList = reserveSequenceList1(twoSequenceList, 0, n);
	// 2.ǰ�벿�ֽ��з�ת
	twoSequenceList = reserveSequenceList1(twoSequenceList, 0, n - m - 1);
	// 3.��벿�ֽ��з�ת
	twoSequenceList = reserveSequenceList1(twoSequenceList, n - m, n);
	return twoSequenceList;
}
int main()
{
	//int twoSequenceList[MAX] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int twoSequenceList[MAX] = { 1,2,3};
	printf("��תǰ���˳���");
	printSequenceList(twoSequenceList);

	int *twoSequenceList1;
	//twoSequenceList1 = reserveSequenceList(twoSequenceList, 2, MAX - 1);   //�������ȫΪ�±�
	twoSequenceList1 = reserveSequenceList(twoSequenceList, 1, MAX - 1);   //�������ȫΪ�±�
	printf("\n��ת�����˳���");
	printSequenceList(twoSequenceList1);
	system("pause");
	return 0;
}