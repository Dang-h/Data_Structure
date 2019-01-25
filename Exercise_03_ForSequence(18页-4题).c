/*
问题：（p.18页第4题）从有序顺序表中删除其值在给定s与t之间(要求s<t)的所有元素，如果s或t不合理或者顺序表为空则显示出错信息并退出运行。
思路：注意是有序顺序表，可以整段平移。
注意：最终剩余顺序表的长度为
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

	int arrayTemp[10] = { 0, 1, 3, 5, 7, 9, 11, 13, 15, 17 };
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

// 3.从有序顺序表中删除其值在给定s与t之间(要求s<t)的所有元素
void deleteElemSectionSequenceList(sequenceListNode *ptr, int start, int end)
{
	if (ptr->length == 0)
	{
		return;
	}
	if (start >= end)
	{
		printf("区间非法\n");
		return;
	}
	// 1.找到左右端点
	int leftPosition, rightPosition;
	for (int i = 0; i < ptr->length; i++)
	{
		if (ptr->data[i] >= start)
		{
			leftPosition = i;
			break;
		}
	}
	// 找到右端点
	for (int i = ptr->length-1; i >0; i--)
	{
		if (ptr->data[i] <= end)
		{
			rightPosition = i;
			break;
		}
	}
	//printf("leftPosition = %d\n", leftPosition);
	//printf("rightPosition = %d\n", rightPosition);
	int moveLength = rightPosition - leftPosition + 1;
	// 2.移动覆盖(删除)元素
	for (int k = 0; k < moveLength; k++)
	{
		ptr->data[leftPosition] = ptr->data[rightPosition + 1];
		leftPosition++;
		rightPosition++;
	}
	// 更改新的顺序表的长度
	// printf("==leftPosition==%d\n", leftPosition);
	ptr->length = leftPosition;
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

	// 3.从有序顺序表中删除其值在给定s与t之间(要求s<t)的所有元素
	printf("3、从有序顺序表中删除其值在给定s与t之间(要求s<t)的所有元素：\n");
	deleteElemSectionSequenceList(newPtr,3,10);
	printf("从有序顺序表中删除其值在给定s与t之间(要求s<t)的所有元素之后的打印输出:");
	printSequenceList(newPtr);
	

	system("pause");
	return 0;
}