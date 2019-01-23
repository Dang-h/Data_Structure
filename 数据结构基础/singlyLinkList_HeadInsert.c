/*
	不带头结点的头插法建立单链表
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
	LinkList L = NULL;			//头指针置为空,不创立头节点
	LNode *newNode;			
	int i;
	for(i = 1; i <= n; i++)
	{
		newNode = (LNode *)malloc(sizeof(LNode));			//生成新节点
		printf("请输入第%d个元素的值：", i);
		scanf("%d", &newNode->data);			//新节点数据域赋值
		newNode->next = L;			//新节点的next为空
		L = newNode;			//头指针指向新节点
	}

	return L;
}

void Print_LinkList(LinkList L){
	LNode *Point;
	Point = L;			//Point中存放着数据域为n,n-1,n-2...的值
	printf("\n单链表中元素的值为：");
	while(Point)
	{
		printf("%d ", Point->data);
		Point = Point->next;
	}
}