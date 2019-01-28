/*
问题：（p.18页第10题）
11.  【2011 年计算机联考真题】
一个长度为 L(L>=1)的升序序列 S，处在第 「L/2⌉ （向上取整） 个位置的数称为 S 的中位数。例如，若序列 S1=  (11，13，15，17，19)，则 S1 的中位数是 15，
两个序列的中位数是含它们所有元素的升序序列的中位数。例如，若 S2=  (2，4，6，8, 20)，则 S1 和 S2 的中位数是 11。
现在有两个等长升序序列 A 和 B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列 A 和 B 的中位数。要求：
(1) 给出算法的基本设计思想。
(2) 根据设计思想，采用 C 或 C++或 Java 语言描述算法，关键之处给出注释。
(3) 说明你所设计算法的时间复杂度和空间复杂度。
思路：
注意：
*/

#include<stdio.h>
#include<stdlib.h>

int searchMedian(int A[], int B[], int length)
{
	// head1表示顺序表A的首元素下标		tail1表示顺序表A的末尾元素下标
	// head2表示顺序表B的首元素下标		tail2表示顺序表B的末尾元素下标
	int head1 = 0, tail1 = length - 1, mid1, head2 = 0, tail2 = length - 1, mid2;

	while (head1 != tail1 || head2 != tail2)
	{
		mid1 = (head1 + tail1) / 2;
		mid2 = (head2 + tail2) / 2;

		if (A[mid1] == B[mid2])
			return A[mid1];											//满足条件 1)

		if (A[mid1] < B[mid2]) {							   //满足条件 2)
			if ((head1 + tail1) % 2 == 0)					   //若元素个数为奇数
			{
				head1 = mid1;										//舍弃 A 中间点以前的部分 且保留中间点
				tail2 = mid2;										  //舍弃 B 中间点以后的部分 且保留中间点
			}
			else                                                         //元素个数为偶数
			{
				head1 = mid1 + 1;								//舍弃A 中间点及中间点及中间点以前部分    （因为我们要求每次舍弃的长度一致）
				tail2 = mid2;										    //舍弃B 中间点以后部分 且保留中间点
			}
		}
		else
		{																  //满足条件 3)
			if ((head2 + tail2) % 2 == 0)
			{															 //若元素个数为奇数
				tail1 = mid1;                                     //舍弃 A 中间点以后的部分 且保留中间点
				head2 = mid2;								    //舍弃 B 中间点以前的部分  且保留中间点
			}
			else                                                     //元素个数为偶数
			{												
				tail1 = mid1;									    //舍弃 A 中间点以后部分  且保留中间点
				head2 = mid2 + 1;                           //舍弃 B 中间点及中间点以前部分
			}
		}
	}
	return A[head1] < B[head2] ? A[head1] : B[head2];
}

int main()
{
	int A[5] = { 11,13,15,17,19 };
	int B[5] = { 2,4,6,8,20 };

	printf("中位数为%d\n", searchMedian(A,B,5));
	system("pause");
	return 0;
}