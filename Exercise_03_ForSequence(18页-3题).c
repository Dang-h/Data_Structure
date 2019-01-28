/*
问题：（p.18页第3题）长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素
思路：用k记录顺序表中不等于x的元素的个数(最终修改的length的值)，循环遍历统计k，并将不等于x的元素向前放置k位置上。
注意：
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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

	// int arrayTemp[10] = { 0, 1, 0, 3, 0, 0, 6, 0, 8, 0 };
	int arrayTemp[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i;
	for (i = 0; i < ptr->maxLength; i++)
	{
		ptr->data[i] = arrayTemp[i];
	}
	ptr->length = MAX;

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

// 3.
void deleteElemSequenceList(sequenceListNode *ptr, int deleteValue)
{
	if (ptr->length == 0)
	{
		printf("顺序表长度为0，删除失败！\n");
		return;
	}
	int k = 0;
	for (int i = 0; i < ptr->length; i++)
	{
		if (ptr->data[i] != deleteValue)
		{
			ptr->data[k] = ptr->data[i];
			k++;
		}
	}
	ptr->length = k;
}


int main()
{
	sequenceListNode *ptr = NULL;

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

	// 3.删除顺序表中值为x的元素
	deleteElemSequenceList(newPtr,0);
	printSequenceList(newPtr);

	system("pause");
	return 0;
}