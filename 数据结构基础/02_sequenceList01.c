/*
	问题：顺序表，1、创建；2、按位插入；3、按值查找;4、按值删除；
	思路：
	注意：按位插入时间复杂度O(n)、按值删除O(n)、按值查找O(n)
 */
#include <stdio.h>
#include <stdlib.h>		//malloc(),free()
#define MAX 30

typedef struct sequenceList
{
	int data[MAX];		//
	int maxLength;		//
	int length;			//当前长度
}sequenceListNode;

//1、创建顺序表
sequenceListNode *creatSequenceList()
{
	sequenceListNode *ptr;
	int i;
	ptr = (sequenceListNode *)malloc(sizeof(sequenceListNode));		//创建了一块空间，ptr指向首地址
	ptr -> maxLength = MAX;		//顺序表空间
	ptr -> length = 20;		//顺序表实际元素个数

	for(i = 0; i < ptr->length; i++){
		ptr->data[i] = i + 1;
	}

	return ptr;

}

//输出验证
void printSequenceList(sequenceListNode *printPtr)
{
	int i;
	for(i = 0; i < printPtr->length; i++){
		printf(" %d", printPtr->data[i]);
	}
	printf("\n");
}

//2、按值插入
int insertSequenceList(sequenceListNode *insertPtr, int insertPosition, int insertValue){
	int isInsertSuc;
	int i;
	//判断插入是否合法
	if((insertPosition > insertPtr->maxLength + 1) || insertPosition <= 0){
		isInsertSuc = 0;
		return isInsertSuc;
	}
	else if(insertPtr->maxLength == insertPtr->length){
	//重新申请一块31个元素的空间，整体平移
	isInsertSuc = 0;
	}
	else{
		for(i = insertPtr->length; i >= insertPosition; i--){
			insertPtr->data[i] = insertPtr->data[i - 1];
		}
		insertPtr->data[i] = insertValue;
		insertPtr->length ++;
		isInsertSuc = 1;
	}
	return isInsertSuc;
}

//3、按值查找
int searchSequenceList(sequenceListNode *serchPtr, int searchValue)
{
	int searchPosition = -1;
	int i;
	for(i = 0; i < serchPtr->length; i++)
	{
		if(serchPtr->data[i] == searchValue){
			searchPosition = i + 1;
			break;
		}
	}
	return searchPosition;
}

int main(){
	// sequenceListNode *ptr = (sequenceListNode *)malloc(sizeof(sequenceListNode));	//堆上分配
	// sequenceListNode seq;		//相当于int a
	
	sequenceListNode *ptr = NULL;		//定义一个名为ptr的sequenceListNode类型的指针变量
	int isInsertSuc;		//0表示失败,1表示成功
	int searchPosition;

	//1、创建顺序表
	printf("1、创建长度为%d的线性表：\n", MAX);
	ptr = creatSequenceList();

	//打印验证创建的顺序表
	printf("输出线性表：\n");
	printSequenceList(ptr);

	//2、按值插入
	printf("2、按值插入(在第10号元素位置插入元素100)\n");
	isInsertSuc = insertSequenceList(ptr, 10, 100);
	if(isInsertSuc){
		printf("成功\n");
	}
	else{
		printf("失败\n");
	}

	printf("输出线性表：\n");
	printSequenceList(ptr);

	//3、按值查找
	printf("3、按值查找，找到返回下标，否则返回-1:\n");
	searchPosition = searchSequenceList(ptr, 100);
	if(searchSequenceList == -1){
		printf("查找失败\n");
	}
	else{
		printf("查找成功，下标为：%d\n", searchPosition);
	}

	return 0;
}