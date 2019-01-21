/*
	头插法建立单链表
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;			//LinkList是指向LNode 节点类型的指针，通常用其标识头指针；

LinkList CreatLinkListByHeadInsert(int n);
void Print_LinkList(LinkList L);

int main(){
	LinkList L;				
	int n;
	printf("请输入单链表的长度：n= ");
	scanf("%d", &n);
	L = CreatLinkListByHeadInsert(n);
	Print_LinkList(L);

	free(L);

	return 0;
}

LinkList CreatLinkListByHeadInsert(int n){
	LinkList L = NULL;			//建立空表L,空表L同时也是头节点
	LNode *newNode;			
	int i;
	for(i = 1; i <= n; i++)
	{
		newNode = (LNode *)malloc(sizeof(LNode));			//生成新节点
		printf("请输入第%d个元素的值：", i);
		scanf("%d", &newNode->data);
		newNode->next = L;			//在头结点前插入新节点
		L = newNode;
	}

	return L;
}

void Print_LinkList(LinkList L){
	LNode *Point;
	Point = L;
	printf("\n单链表中个元素的值为：");
	while(Point)
	{
		printf("%d ", Point->data);
		Point = Point->next;
	}
}