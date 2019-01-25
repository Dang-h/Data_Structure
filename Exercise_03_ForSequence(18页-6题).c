/*
问题：（p.18页第6题）从有序顺序表中删除所有其值重复的元素，使表中的所有元素的值均不同。
思路：画图解释
注意：注意最后要修改删除后顺序表的长度
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

	//int arrayTemp[10] = { 0,0,1,2,2,2,3,4,7,8};
	int arrayTemp[10] = { 0,0,0,0,0,0,0,0,0,0 };
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
void deleteReptElemSequenceList(sequenceListNode *ptr)
{
	if (ptr->length == 0)
	{
		printf("长度为0，删除失败，退出删除!\n");
		return;
	}
	int k = 0;
	for (int i = 0; i < ptr->length; i++)
	{
		if (ptr->data[k] != ptr->data[i])
		{
			k++;
			ptr->data[k] = ptr->data[i];
		}
	}
	ptr->length = k + 1;
}

int main()
{
	sequenceListNode *ptr = NULL;
	int isDeleteSucc = 0;					// 0代表删除失败    1 代表删除成功

	// 1.创建
	printf("创建线性表: \n");
	sequenceListNode *newPtr = createSequenceList(ptr);
	// 2.验证创建顺序表成功
	printSequenceList(newPtr);
	//3.删除顺序表中的元素
	deleteReptElemSequenceList(newPtr);

	printSequenceList(newPtr);

	system("pause");
	return 0;
}