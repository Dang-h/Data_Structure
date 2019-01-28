/*
问题：（p.18页第10题）
10.  【2010 年计算机联考真题】
设将 n  (n>1) 个整数存放到一维数组 R 中。试设计一个在时间和空间两方面都尽可能高效的算法。
将 R 中保存的序列循环左移 p (0 <p <n）个位置，即将 R 中的数据由（X0,X1......Xn-1) 变换为
（Xp，Xp+1......Xn-1, X0，X1......Xp-1)。要求：

 (1) 给出算法的基本设计思想。
 (2) 根据设计思想，采用 C 或 C++或 Java 语言描述算法，关键之处给出注释。
 (3) 说明你所设计算法的时间复杂度和空间复杂度。
思路：做法同第8题
注意：
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

int * reserveSequenceList1(int twoSequenceList[], int m, int n)			// 注意这里m n传入的是下标
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

// 反转---注意函数的返回值一定不能是栈变量的地址
int *reserveSequenceList(int twoSequenceList[], int m, int n)   // 
{
	// 1.先整体反转一次
	twoSequenceList = reserveSequenceList1(twoSequenceList, 0, n);
	// 2.前半部分进行反转
	twoSequenceList = reserveSequenceList1(twoSequenceList, 0, n - m - 1);
	// 3.后半部分进行反转
	twoSequenceList = reserveSequenceList1(twoSequenceList, n - m, n);
	return twoSequenceList;
}
int main()
{
	//int twoSequenceList[MAX] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int twoSequenceList[MAX] = { 1,2,3};
	printf("反转前输出顺序表：");
	printSequenceList(twoSequenceList);

	int *twoSequenceList1;
	//twoSequenceList1 = reserveSequenceList(twoSequenceList, 2, MAX - 1);   //传入的完全为下标
	twoSequenceList1 = reserveSequenceList(twoSequenceList, 1, MAX - 1);   //传入的完全为下标
	printf("\n反转后输出顺序表：");
	printSequenceList(twoSequenceList1);
	system("pause");
	return 0;
}