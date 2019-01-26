/*
问题：（p.18页第8题）
		已知在一维数组 A [m+n]中依次存放着两个线性表（a1, a2, a3......am）和（b1, b2, b3......bn）。
		试编写一个函数，将数组中两个顺序表的位置互换，即将（b1, b2, b3......bn）放在（a1, a2, a3......am）的前面。
思路：
注意：
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

int *reserveSequenceList(int twoSequenceList[], int m, int n)			//注意这里传入的是下标
{
	//1.整体反转一次
	twoSequenceList = reserveSequenceList1(twoSequenceList, 0, n);
	// printSequenceList(twoSequenceList);
	// 2.前半部分反转一次
	twoSequenceList = reserveSequenceList1(twoSequenceList,0,n-m-1);
	// 3.后半部分反转一次
	twoSequenceList = reserveSequenceList1(twoSequenceList, n-m, n);

	return twoSequenceList;
}

int main()
{
	int twoSequenceList[MAX] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	//int twoSequenceList[MAX] = { 1,2,3};
	printf("反转前输出顺序表：");
	printSequenceList(twoSequenceList);

	int *twoSequenceList1;
	twoSequenceList1 = reserveSequenceList(twoSequenceList, 7, MAX-1);   //传入的完全为下标
	printf("\n反转后输出顺序表：");
	printSequenceList(twoSequenceList1);
	system("pause");
	return 0;
}