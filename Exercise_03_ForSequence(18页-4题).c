/*
���⣺��p.18ҳ��4�⣩������˳�����ɾ����ֵ�ڸ���s��t֮��(Ҫ��s<t)������Ԫ�أ����s��t���������˳���Ϊ������ʾ������Ϣ���˳����С�
˼·��ע��������˳�����������ƽ�ơ�
ע�⣺����ʣ��˳���ĳ���Ϊ
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

	int arrayTemp[10] = { 0, 1, 3, 5, 7, 9, 11, 13, 15, 17 };
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

// 3.������˳�����ɾ����ֵ�ڸ���s��t֮��(Ҫ��s<t)������Ԫ��
void deleteElemSectionSequenceList(sequenceListNode *ptr, int start, int end)
{
	if (ptr->length == 0)
	{
		return;
	}
	if (start >= end)
	{
		printf("����Ƿ�\n");
		return;
	}
	// 1.�ҵ����Ҷ˵�
	int leftPosition, rightPosition;
	for (int i = 0; i < ptr->length; i++)
	{
		if (ptr->data[i] >= start)
		{
			leftPosition = i;
			break;
		}
	}
	// �ҵ��Ҷ˵�
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
	// 2.�ƶ�����(ɾ��)Ԫ��
	for (int k = 0; k < moveLength; k++)
	{
		ptr->data[leftPosition] = ptr->data[rightPosition + 1];
		leftPosition++;
		rightPosition++;
	}
	// �����µ�˳���ĳ���
	// printf("==leftPosition==%d\n", leftPosition);
	ptr->length = leftPosition;
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

	// 3.������˳�����ɾ����ֵ�ڸ���s��t֮��(Ҫ��s<t)������Ԫ��
	printf("3��������˳�����ɾ����ֵ�ڸ���s��t֮��(Ҫ��s<t)������Ԫ�أ�\n");
	deleteElemSectionSequenceList(newPtr,3,10);
	printf("������˳�����ɾ����ֵ�ڸ���s��t֮��(Ҫ��s<t)������Ԫ��֮��Ĵ�ӡ���:");
	printSequenceList(newPtr);
	

	system("pause");
	return 0;
}