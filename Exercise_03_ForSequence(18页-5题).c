/*
���⣺��p.18ҳ��5�⣩��˳�����ɾ������ֵ��s��t֮��(Ҫ��s<t)������Ԫ�أ����s��t���������˳���Ϊ������ʾ������Ϣ���˳����С�
˼·��˼·ͬ��3�� ������¼������ɾ������Ԫ�صĸ���
ע�⣺
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct sequenceList
{
	int data[MAX];
	int maxLength;	// ���Ա��
	int length;		// ���Ա�Ŀǰ�ĳ���
}sequenceListNode;

// 1.����
sequenceListNode *createSequenceList(sequenceListNode *ptr)
{
	ptr = (sequenceListNode *)malloc(sizeof(sequenceListNode));   // Ҳ����ֱ����ջ�Ϸ���ռ�
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


// 2.���˳���
void printSequenceList(sequenceListNode *ptr)
{
	int tmpLength = ptr->length;
	int i;
	printf("\n===��ӡ˳���===\n");
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
		printf("����Ϊ0��ɾ��ʧ�ܣ�\n");
		return;
	}
	if (!(start < end))
	{
		printf("������Ч!\n");
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
	int isDeleteSucc = 0;					// 0����ɾ��ʧ��    1 ����ɾ���ɹ�

	// 1.����
	// printf("�������Ա�: \n");
	//createSequenceList(&ptr);
	// 2.��֤����˳���ɹ�
	//printSequenceList(&ptr);

	// 1.����
	printf("�������Ա�: \n");
	sequenceListNode *newPtr = createSequenceList(ptr);
	// 2.��֤����˳���ɹ�
	printSequenceList(newPtr);
	//3.ɾ��˳����е�Ԫ��
	deleteSequenceList(newPtr, 1, 8);

	printSequenceList(newPtr);
	
	system("pause");
	return 0;
}