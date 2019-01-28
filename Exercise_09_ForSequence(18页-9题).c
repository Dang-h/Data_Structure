/*
���⣺��p.18ҳ��9�⣩���Ա�a1, a2, a3......an����Ԫ�ص��������Ұ�˳��洢�ڼ�����ڡ�
		Ҫ�����һ�㷨���������ʱ���ڱ��в�����ֵΪ x ��Ԫ�أ����ҵ���������Ԫ��λ���ཻ����
		���Ҳ������������в�ʹ����Ԫ���Ե�������
˼·��
ע�⣺
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

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

	int arrayTemp[10] = { 1,2,3,4,5,7,8,9,10,11 };
	//int arrayTemp[2] = { 1,2 };
	int i;
	for (i = 0; i < 10; i++)
	{
		ptr->data[i] = arrayTemp[i];
	}
	ptr->length = 10;

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
void searchAndInsertSequenceList(sequenceListNode *ptr, int number)
{
	// 1.���� --- �۰루���֣�logn
	int flag = 1;								// ������ҵ��� = 0  ���� = 1
	int low = 0, high = ptr->length - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ptr->data[mid] == number)
		{
			flag = 0;
			break;
		}
		else if (ptr->data[mid] < number)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	//2.����鵽�ˣ�����Ԫ�ؽ���
	if (flag == 0)
	{
		if (mid < ptr->length - 1)
		{
			int tempData = ptr->data[mid];
			ptr->data[mid] = ptr->data[mid + 1];
			ptr->data[mid + 1] = tempData;
		}
	}
	//3.���û�鵽������
	else
	{
		if (ptr->data[ptr->length - 1] < number)
		{
			ptr->data[ptr->length] = number;
		}
		else
		{
			for (int i = ptr->length; i >= mid; i--)
			{
				ptr->data[i] = ptr->data[i - 1];
			}
			ptr->data[mid] = number;
		}
		ptr->length++;
	}
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
	//searchAndInsertSequenceList(newPtr, 7);
	//searchAndInsertSequenceList(newPtr, 11);
	//searchAndInsertSequenceList(newPtr, 1);

	//searchAndInsertSequenceList(newPtr, 6);
	//searchAndInsertSequenceList(newPtr, 0);
	searchAndInsertSequenceList(newPtr, 12);
	//
	printSequenceList(newPtr);

	system("pause");
	return 0;
}