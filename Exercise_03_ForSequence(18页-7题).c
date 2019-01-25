/*
问题：（p.18页第7题）将两个有序顺序表合并成一个新的有序顺序表，并由函数返回结果顺序表。
思路：这里我们先假定原来的顺序表是升序排列的。首先申请一块新的空间(大小等于有序顺序表a、b之和)c，然后按顺序循环取下a、b两个链表中比较小的
          当前首元素放到新的顺序表空间c。如果出现其中的一个顺序表已经遍历到了表尾(例如a链表)，则将另一个链表(b)，整块放到c上。
		  这种方法的时间复杂度为O(n)、空间 
注意：(1)此题型在链表部分还会出现，到时此解法仍然适用，但不是最好的解法。(2)申请的新的空间的大小并不是两个原来结构体之和
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

typedef struct sequenceList1
{
	int data[2*MAX];
	int maxLength;	// 线性表最长
	int length;		// 线性表目前的长度
}sequenceListNode1;

// 1.创建
sequenceListNode *createSequenceList(sequenceListNode *ptr,int flag)
{
	ptr = (sequenceListNode *)malloc(sizeof(sequenceListNode));   // 也可以直接在栈上分配空间
	ptr->maxLength = MAX;

	int arrayTemp1[10] = { 0,0,2,4,4,6,8,8,10,10 };
	int arrayTemp2[10] = { 1,1,3,3,5,7,9,11,13,14 };
	int i;
	for (i = 0; i < ptr->maxLength; i++)
	{
		if(flag == 1)
			ptr->data[i] = arrayTemp1[i];
		else
			ptr->data[i] = arrayTemp2[i];
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

// 3.输出顺序表
void printMergeSequenceList(sequenceListNode1 *ptr)
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
sequenceListNode1 mergeTwoSequenceList(sequenceListNode *ptr1, sequenceListNode *ptr2)
{
	//sequenceListNode *newPtr3 = NULL;
	sequenceListNode1 *newPtr3 = NULL;
	//sequenceListNode1 newPtr4[20];
	//printf("sizeof(newPtr4) == %d", sizeof(newPtr4));   输出20*88
	if (ptr1->length == 0 && ptr2->length == 0)
	{
		printf("顺序表都为空，无法合并！");
		//system("pause");                              为了看效果
		exit(0);
	}
	

	///sizeof是C/C++中的一个操作符（operator），简单的说其作用就是返回一个对象或者类型所占的内存字节数。
	///sizeof计算对象的大小也是转换成对对象类型的计算，也就是说，同种类型的不同对象其sizeof值都是一致的。
	/*
	int n;
	n=10;//n动态赋值
	char ary[n];//C99也支持数组的动态定义
	printf("%d\n",sizeof(ary));//ok.输出10
	*/

	/*
	学过数据结构的你应该知道指针是一个很重要的概念，它记录了另一个对象的地址。既然是来存放地址的，那么它当然等于计算机内部地址总线的宽度。
	所以在32位计算机中，一个指针变量的返回值必定是4（注意结果是以字节为单位），但是，在64位系统中指针变量的sizeof结果为8。
	*/
	/*
	char*pc="abc";
	int*pi;
	char**ppc=&pc;
	void(*pf)();//函数指针
	sizeof(pc);//结果为4
	sizeof(pi);//结果为4
	sizeof(ppc);//结果为4
	sizeof(pf);//结果为4
	*/
	/*
	一些朋友刚开始时把sizeof当作了求数组元素的个数，如今你应该知道这是不对的，那么应该怎么求数组元素的个数呢Easy，通常有下面两种写法：
	int c1=sizeof(a1)/sizeof(char);//总长度/单个元素的长度  char型
	*/

	/*
	printf("sizeof(*ptr1) == %d", sizeof(*ptr1));   //48
	printf("sizeof(*ptr2) == %d", sizeof(*ptr2));   //48
	newPtr3 = (sequenceListNode *)malloc(sizeof(*ptr1) + sizeof(*ptr2));   //48
	newPtr3 = (sequenceListNode *)malloc(sizeof(sequenceListNode)*100);   //48
	//long long*newPtr4 = (long long*)malloc(1000);
	//newPtr3 = (sequenceListNode1 *)malloc(sizeof(sequenceListNode1));                          // 按着sizeof的定义：返回一个对象或者类型所占的内存字节数。关键字：类型
	printf("测试一下 newPtr3->length == %d\n", sizeof(*newPtr3));
	printf("newPtr4 == %d, sizeof(long long) == %d\n", sizeof(*newPtr4) , sizeof( long));
	*/

	// 申请内存
	newPtr3 = (sequenceListNode1 *)malloc(sizeof(sequenceListNode1));                          // 申请的为最大空间。可能不能完全用到
	// 循环遍历
	//newPtr3->length = ptr1->length + ptr2->length;
	int i = 0, j = 0, k = 0;
	while(i < ptr1->length && j < ptr2->length)
	{
		if (ptr1->data[i] < ptr2->data[j])
		{
			newPtr3->data[k] = ptr1->data[i];
			i++;
		}
		else
		{
			newPtr3->data[k] = ptr2->data[j];
			j++;
		}
		k++;
	}
	//newPtr3->length = k + 1;
	//return *newPtr3;
	// 将剩余的(如果有)一个顺序表添加到新的顺序表上
	if (i < ptr1->length)
	{
		for (; i < ptr1->length; i++)
		{
			newPtr3->data[k] = ptr1->data[i];
			k++;
		}
	}
	else if (j < ptr2->length)
	{
		for (; j < ptr2->length; j++)
		{
			newPtr3->data[k] = ptr2->data[j];
			k++;
		}
	}
	newPtr3->length = k;
	return *newPtr3;
}

int main()
{
	sequenceListNode *ptr1 = NULL;
	sequenceListNode *ptr2 = NULL;

	// 1.创建
	// printf("创建线性表: \n");
	//createSequenceList(&ptr);
	// 2.验证创建顺序表成功
	//printSequenceList(&ptr);

	// 1.创建
	printf("创建线性表: \n");
	sequenceListNode *newPtr1 = createSequenceList(ptr1,1);
	// 2.验证创建顺序表成功
	printSequenceList(newPtr1);
	//3.合并有序顺序表中

	// 1.创建
	printf("创建线性表: \n");
	sequenceListNode *newPtr2 = createSequenceList(ptr2, 2);
	// 2.验证创建顺序表成功
	printSequenceList(newPtr2);
	//3.合并有序顺序表中
    //newPtr1->length = 0;
	newPtr1->length = 5;
	//newPtr2->length = 0;
	sequenceListNode1 newPtr3 = (mergeTwoSequenceList(newPtr1, newPtr2));
	printf("newPtr3 length = %d\n",newPtr3.length);
	printMergeSequenceList(&newPtr3);


	system("pause");
	return 0;
}