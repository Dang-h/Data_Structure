/*
���⣺��p.18ҳ��8�⣩
		��֪��һά���� A [m+n]�����δ�����������Ա�a1, a2, a3......am���ͣ�b1, b2, b3......bn����
		�Ա�дһ��������������������˳����λ�û�����������b1, b2, b3......bn�����ڣ�a1, a2, a3......am����ǰ�档
˼·��
ע�⣺
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 20

void printSequenceList(int twoSequenceList[])
{
	printf("\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", twoSequenceList[i]);
	}
}

int *reserveSequenceList1(int twoSequenceList[], int m, int n)
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

int *reserveSequenceList(int twoSequenceList[], int m, int n)			//ע�����ﴫ������±�
{
	//1.���巴תһ��
	twoSequenceList = reserveSequenceList1(twoSequenceList, 0, n);
	// printSequenceList(twoSequenceList);
	// 2.ǰ�벿�ַ�תһ��
	twoSequenceList = reserveSequenceList1(twoSequenceList,0,n-m-1);
	// 3.��벿�ַ�תһ��
	twoSequenceList = reserveSequenceList1(twoSequenceList, n-m, n);

	return twoSequenceList;
}

int main()
{
	int twoSequenceList[MAX] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	//int twoSequenceList[MAX] = { 1,2,3};
	printf("��תǰ���˳���");
	printSequenceList(twoSequenceList);

	int *twoSequenceList1;
	twoSequenceList1 = reserveSequenceList(twoSequenceList, 7, MAX-1);   //�������ȫΪ�±�
	printf("\n��ת�����˳���");
	printSequenceList(twoSequenceList1);
	system("pause");
	return 0;
}