/*
	问题：顺序表：1、创建；2、按位插入；3、按值查找；4、按值删除
	注意：按值插入时间复杂度O(n)、按值查找O(n)、按值删除O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define INIT_SIZE 20

typedef struct sequenceList
{
	int data[MAX];
	int maxlength;
	int length;
}sequenceListNode;

//1、创建顺序表
sequenceListNode *creatSequenceList();
//输出验证
void printSequenceList(sequenceListNode *printPnt);
//2、按值插入
int insertSequenceList(sequenceListNode *insertPnt, int insertPosition, int insertValue);
//3、按值查找
int searchSequenceList(sequenceListNode *searchPnt, int searchValue);
//4、按值删除
int deleteSequenceList(sequenceListNode *deletePnt, int deletePnt, int *deletePnt);

int main()
{
	sequenceListNode *pnt = NULL;			//定义名为pnt的sequenceListNode类型指针，pnt指空；
	int isInsertSuc;
	int searchPositon;


	//1、创建顺序表
	printf("1、创建长度为%d的顺序表：\n", MAX);
	pnt = creatSequenceList();	


	//验证创建
	printf("创建的顺序表为：\n");
	printSequenceList(pnt);


	//2、按值插入
	printf("2、按值插入（在第10号元素位置插入元素100）\n");
	isInsertSuc = insertSequenceList(pnt, 10, 100);			//pnt头指针，在第10号元素插入100
	if(isInsertSuc)
	{
		printf("成功\n");
	}
	else
	{
		printf("失败\n");
	}

	printf("输出线性表：\n");
	printSequenceList(pnt);


	//3、按值查找
	printf("3、按值查找，找到返回下标，否则返回-1\n");
	searchPositon = searchSequenceList(pnt, 100);
	if(searchSequenceList == -1)
	{
		printf("查找失败,查找元素不存在\n");
	}
	else
	{
		printf("查找成功，下标为:%d\n", searchPositon);
	}


	//4、按值删除
	printf("4、按值删除（删除第4位的元素）\n");
	deleteSequenceList(pnt, 4, 4)
	return 0;
}

//1、创建顺序表
sequenceListNode *creatSequenceList()
{
	sequenceListNode *pnt;			//定义名为pnt的sequenceListNode类型的指针,存储空间的基地址
	int i;
	pnt = (sequenceListNode *)malloc(sizeof(sequenceListNode));			//为pnt动态分配空间，pnt指向这块空间的首地址
	pnt -> maxlength = MAX;			//顺序表分配最大空间
	pnt -> length = INIT_SIZE;			//实际初始化大小

	for(i = 0; i < pnt->length; i++)
	{
		pnt -> data[i] = i + 1;
	}
	return pnt;
}
//创建验证
void printSequenceList(sequenceListNode *printPnt)
{
	int i;
	for(i = 0; i < printPnt->length; i++)
	{
		printf(" %d", printPnt->data[i]);
	}
	printf("\n");
}
//2、按值插入
int insertSequenceList(sequenceListNode *insertPnt, int insertPosition, int insertValue)
{
	int isInsertSuc = 0;
	int i;
	//判断插入位置是否合法
	if((insertPosition > insertPnt->maxlength + 1) || insertPosition <= 0)
	{
		isInsertSuc = 0;
	}//此时插入位置在边界
	else if(insertPnt->maxlength == insertPnt->length)
	{
		isInsertSuc = 0;
	}
	//插入
	else		
	{
		for(i = insertPnt->length; i >= insertPosition; i--)
		{
			insertPnt->data[i] = insertPnt->data[i - 1];
		}
		insertPnt->data[i] = insertValue;
		insertPnt->length ++;
		isInsertSuc = 1;
	}
	return isInsertSuc;
}
//3、按值查找
int searchSequenceList(sequenceListNode *searchPnt, int searchValue)
{
	int searchPositon = -1;
	int i;
	for(i = 0; i < searchPnt->length; i++)
	{
		if(searchPnt->data[i] == searchValue)
		{
			searchPositon = i + 1;
			break;
		}
	}
	return searchPositon;
}
//4、按值删除
int deleteSequenceList(sequenceListNode *deletePnt, int deletePnt, int *deletePnt)
{

}