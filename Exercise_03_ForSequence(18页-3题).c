/*
���⣺��p.18ҳ��3�⣩����Ϊn��˳���L����дһ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)���㷨�����㷨ɾ�����Ա�������ֵΪx������Ԫ��
˼·����k��¼˳����в�����x��Ԫ�صĸ���(�����޸ĵ�length��ֵ)��ѭ������ͳ��k������������x��Ԫ����ǰ����kλ���ϡ�
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

	// int arrayTemp[10] = { 0, 1, 0, 3, 0, 0, 6, 0, 8, 0 };
	int arrayTemp[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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

// 3.
void deleteElemSequenceList(sequenceListNode *ptr, int deleteValue)
{
	if (ptr->length == 0)
	{
		printf("˳�����Ϊ0��ɾ��ʧ�ܣ�\n");
		return;
	}
	int k = 0;
	for (int i = 0; i < ptr->length; i++)
	{
		if (ptr->data[i] != deleteValue)
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

	// 3.ɾ��˳�����ֵΪx��Ԫ��
	deleteElemSequenceList(newPtr,0);
	printSequenceList(newPtr);

	system("pause");
	return 0;
}