/*
���⣺��p.18ҳ��6�⣩������˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ���е�����Ԫ�ص�ֵ����ͬ��
˼·����ͼ����
ע�⣺ע�����Ҫ�޸�ɾ����˳���ĳ���
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
void deleteReptElemSequenceList(sequenceListNode *ptr)
{
	if (ptr->length == 0)
	{
		printf("����Ϊ0��ɾ��ʧ�ܣ��˳�ɾ��!\n");
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
	int isDeleteSucc = 0;					// 0����ɾ��ʧ��    1 ����ɾ���ɹ�

	// 1.����
	printf("�������Ա�: \n");
	sequenceListNode *newPtr = createSequenceList(ptr);
	// 2.��֤����˳���ɹ�
	printSequenceList(newPtr);
	//3.ɾ��˳����е�Ԫ��
	deleteReptElemSequenceList(newPtr);

	printSequenceList(newPtr);

	system("pause");
	return 0;
}