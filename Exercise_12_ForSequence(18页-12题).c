/*
问题：（p.18页第12题）
12.  [2013 年计算机联考真题】
已知一个整数序列 A=(a0, a1...... an-1)，其中 0 <= ai<n  (0 <=i <n）。若存在 ap1=ap2=......=apm=x 且 m> n/2(0<=px<n, 1 <=k <m），则称 x 为 A 的主元素。
例如 A= (0,5,5,3,5,7,5,5)，则 5 为主元素；又如 A=  (0,5,5,3,5,1,5,7)，则 A 中没有主元素。假设 A 中的 n 个元素保存在一个一维数组中，
请设计一个尽可能高效的算法，找出 A 的主元素。若存在主元素，则输出该元素；否则输出-1。要求：
(1) 给出算法的基本设计思想。
(2) 根据设计思想，采用 C 或 C++或 Java 语言描述算法，关键之处给出注释。
思路：考试的时候无论时间复杂度如何，你至少要有一个解题思路。
注意：
*/
#include<stdio.h>
#include<stdlib.h>

int searchMainElem(int A[], int n)
{
	int i, c, count = 1;												//c 用来保存候选主元素，count 用来计数
	c = A[0];															//设置 A [0] 为候选主元素
	for (i = 1; i < n; i++)											//查找候选主元素
	{
		if (A[i] == c)
		{
			count++;													//对 A 中的候选主元素计数
		}
		else
		{
			if (count > 0)											//处理不是候选主元素的情况
			{
				count--;
			}
			else															//更换候选主元素，重新计数
			{
				c = A[i];
				count = 1;
			}
		}
	}
	//printf("count==%d\n",count);
	if (count > 0)
	{
		for (i = count = 0; i < n; i++) //统计候选主元素的实际出现次数
		{
			if (A[i] == c)
			{
				count++;
			}
		}
		if (count > n / 2)
		{
			return c; //确认候选主元素
		}

	}

	return -1;    //不存在主元素
}

int main()
{
	int A[8] = { 0,5,5,3,5,7,5,5 };
	//int A[8] = { 4,4,4,4,5,5,5,5 };
	printf("%d\n",searchMainElem(A, 8));
	system("pause");
	return 0;
}