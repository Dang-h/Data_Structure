/*
问题：（p.18页第5题）从顺序表中删除给定值在s到t之间(要求s<t)的所有元素，如果s或t不合理或者顺序表为空则显示错误信息并退出运行。
思路：思路同第3题 ：即记录不满足删除条件元素的个数
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

	int arrayTemp[10] = { 10,1,20,0,4,5,-3,7,80,2};
	//int arrayTemp[2] = { 1,2 };
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

// 3
void deleteSequenceList(sequenceListNode *ptr, int start, int end)
{
	if (ptr->length == 0)
	{
		printf("长度为0，删除失败！\n");
		return;
	}
	if (!(start < end))
	{
		printf("区间无效!\n");
		return;
	}
	int k = 0;
	for (int i = 0; i < ptr->length; i++)
	{
		if (ptr->data[i] < start || ptr->data[i] > end)
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
	deleteSequenceList(newPtr, 1, 8);

	printSequenceList(newPtr);
	
	system("pause");
	return 0;
}