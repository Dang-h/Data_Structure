/*
问题：（p.18页第9题）线性表（a1, a2, a3......an）中元素递增有序且按顺序存储于计算机内。
		要求设计一算法完成用最少时间在表中查找数值为 x 的元素，若找到将其与后继元素位置相交换，
		若找不到将其插入表中并使表中元素仍递增有序。
思路：
注意：
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct sequenceList
{
	int data[MAX];
	int maxLength;	// 线性表最长
	int length;		// 线性表目前的长度
}sequenceListNode;

// 1.创建
sequenceListNode *createSequenceList(sequenceListNode *ptr)
{
	ptr = (sequenceListNode *)malloc(sizeof(sequenceListNode));   // 也可以直接在栈上分配空间
	ptr->maxLength = MAX;

	int arrayTemp[10] = { 1,2,3,4,5,7,8,9,10,11 };
	//int arrayTemp[2] = { 1,2 };
	int i;
	for (i = 0; i < 10; i++)
	{
		ptr->data[i] = arrayTemp[i];
	}
	ptr->length = 10;

	return ptr;
}


// 2.输出顺序表
void printSequenceList(sequenceListNode *ptr)
{
	int tmpLength = ptr->length;
	int i;
	printf("\n===打印顺序表===\n");
	for (i = 0; i < tmpLength; i++)
	{
		printf("%d ", ptr->data[i]);
	}
	printf("\n");
}

// 3
void searchAndInsertSequenceList(sequenceListNode *ptr, int number)
{
	// 1.查找 --- 折半（二分）logn
	int flag = 1;								// 如果查找到了 = 0  否则 = 1
	int low = 0, high = ptr->length - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ptr->data[mid] == number)
		{
			flag = 0;
			break;
		}
		else if (ptr->data[mid] < number)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	//2.如果查到了，与后继元素交换
	if (flag == 0)
	{
		if (mid < ptr->length - 1)
		{
			int tempData = ptr->data[mid];
			ptr->data[mid] = ptr->data[mid + 1];
			ptr->data[mid + 1] = tempData;
		}
	}
	//3.如果没查到，插入
	else
	{
		if (ptr->data[ptr->length - 1] < number)
		{
			ptr->data[ptr->length] = number;
		}
		else
		{
			for (int i = ptr->length; i >= mid; i--)
			{
				ptr->data[i] = ptr->data[i - 1];
			}
			ptr->data[mid] = number;
		}
		ptr->length++;
	}
}


int main()
{
	sequenceListNode *ptr = NULL;
	int isDeleteSucc = 0;					// 0代表删除失败    1 代表删除成功

	// 1.创建
	// printf("创建线性表: \n");
	//createSequenceList(&ptr);
	// 2.验证创建顺序表成功
	//printSequenceList(&ptr);

	// 1.创建
	printf("创建线性表: \n");
	sequenceListNode *newPtr = createSequenceList(ptr);
	// 2.验证创建顺序表成功
	printSequenceList(newPtr);
	//3.删除顺序表中的元素
	//searchAndInsertSequenceList(newPtr, 7);
	//searchAndInsertSequenceList(newPtr, 11);
	//searchAndInsertSequenceList(newPtr, 1);

	//searchAndInsertSequenceList(newPtr, 6);
	//searchAndInsertSequenceList(newPtr, 0);
	searchAndInsertSequenceList(newPtr, 12);
	//
	printSequenceList(newPtr);

	system("pause");
	return 0;
}