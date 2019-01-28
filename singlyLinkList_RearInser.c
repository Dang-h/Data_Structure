/*
	尾插法建立单链表
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList CreatLinkListByRearInsert(int n);
void Print_LinkList(LinkList L);

int main(){
	LinkList L;
	int n;
	printf("请输入单链表的长度:n=");
	scanf("%d", &n);
	L = CreatLinkListByRearInsert(n);
	Print_LinkList(L);

	free(L);

	return 0;
}

LinkList CreatLinkListByRearInsert(int n){
	LNode *L, *newNode, *rear;			//定义头指针,新节点指针,尾指针
	int i;
	L = (LNode*)malloc(sizeof(LNode));			//创建头结点
	L -> next = NULL;			//头结点指针置为空
	rear = L;		//尾指针指向头节点
	for(i = 0; i <= n - 1; i++)
	{
		newNode = (LNode*)malloc(sizeof(LNode));			//创建新节点
		printf("请输入第%d个元素的值:", i + 1);
		scanf("%d", &newNode->data);			//新节点数据域赋值
		newNode -> next = NULL;			//新节点指针的next置为空
		rear -> next = newNode;			//尾指针后移
		rear = newNode;				//尾指针置为空
	}
	
	return L;
}

void Print_LinkList(LinkList L){
	LNode *Point;			
	Point = L -> next;			//头指针指向空(0),新节点的数据域从L的next开始
	printf("\n链表中的元素为: ");
	while(Point)
	{
		printf("%d ", Point->data);
		Point = Point->next;
	}
}