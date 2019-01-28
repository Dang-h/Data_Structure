/*
���⣺��p.18ҳ��7�⣩����������˳���ϲ���һ���µ�����˳������ɺ������ؽ��˳���
˼·�����������ȼٶ�ԭ����˳������������еġ���������һ���µĿռ�(��С��������˳���a��b֮��)c��Ȼ��˳��ѭ��ȡ��a��b���������бȽ�С��
          ��ǰ��Ԫ�طŵ��µ�˳���ռ�c������������е�һ��˳����Ѿ��������˱�β(����a����)������һ������(b)������ŵ�c�ϡ�
		  ���ַ�����ʱ�临�Ӷ�ΪO(n)���ռ� 
ע�⣺(1)�������������ֻ�����֣���ʱ�˽ⷨ��Ȼ���ã���������õĽⷨ��(2)������µĿռ�Ĵ�С����������ԭ���ṹ��֮��
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

typedef struct sequenceList1
{
	int data[2*MAX];
	int maxLength;	// ���Ա��
	int length;		// ���Ա�Ŀǰ�ĳ���
}sequenceListNode1;

// 1.����
sequenceListNode *createSequenceList(sequenceListNode *ptr,int flag)
{
	ptr = (sequenceListNode *)malloc(sizeof(sequenceListNode));   // Ҳ����ֱ����ջ�Ϸ���ռ�
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

// 3.���˳���
void printMergeSequenceList(sequenceListNode1 *ptr)
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
sequenceListNode1 mergeTwoSequenceList(sequenceListNode *ptr1, sequenceListNode *ptr2)
{
	//sequenceListNode *newPtr3 = NULL;
	sequenceListNode1 *newPtr3 = NULL;
	//sequenceListNode1 newPtr4[20];
	//printf("sizeof(newPtr4) == %d", sizeof(newPtr4));   ���20*88
	if (ptr1->length == 0 && ptr2->length == 0)
	{
		printf("˳���Ϊ�գ��޷��ϲ���");
		//system("pause");                              Ϊ�˿�Ч��
		exit(0);
	}
	

	///sizeof��C/C++�е�һ����������operator�����򵥵�˵�����þ��Ƿ���һ���������������ռ���ڴ��ֽ�����
	///sizeof�������Ĵ�СҲ��ת���ɶԶ������͵ļ��㣬Ҳ����˵��ͬ�����͵Ĳ�ͬ������sizeofֵ����һ�µġ�
	/*
	int n;
	n=10;//n��̬��ֵ
	char ary[n];//C99Ҳ֧������Ķ�̬����
	printf("%d\n",sizeof(ary));//ok.���10
	*/

	/*
	ѧ�����ݽṹ����Ӧ��֪��ָ����һ������Ҫ�ĸ������¼����һ������ĵ�ַ����Ȼ������ŵ�ַ�ģ���ô����Ȼ���ڼ�����ڲ���ַ���ߵĿ�ȡ�
	������32λ������У�һ��ָ������ķ���ֵ�ض���4��ע���������ֽ�Ϊ��λ�������ǣ���64λϵͳ��ָ�������sizeof���Ϊ8��
	*/
	/*
	char*pc="abc";
	int*pi;
	char**ppc=&pc;
	void(*pf)();//����ָ��
	sizeof(pc);//���Ϊ4
	sizeof(pi);//���Ϊ4
	sizeof(ppc);//���Ϊ4
	sizeof(pf);//���Ϊ4
	*/
	/*
	һЩ���Ѹտ�ʼʱ��sizeof������������Ԫ�صĸ����������Ӧ��֪�����ǲ��Եģ���ôӦ����ô������Ԫ�صĸ�����Easy��ͨ������������д����
	int c1=sizeof(a1)/sizeof(char);//�ܳ���/����Ԫ�صĳ���  char��
	*/

	/*
	printf("sizeof(*ptr1) == %d", sizeof(*ptr1));   //48
	printf("sizeof(*ptr2) == %d", sizeof(*ptr2));   //48
	newPtr3 = (sequenceListNode *)malloc(sizeof(*ptr1) + sizeof(*ptr2));   //48
	newPtr3 = (sequenceListNode *)malloc(sizeof(sequenceListNode)*100);   //48
	//long long*newPtr4 = (long long*)malloc(1000);
	//newPtr3 = (sequenceListNode1 *)malloc(sizeof(sequenceListNode1));                          // ����sizeof�Ķ��壺����һ���������������ռ���ڴ��ֽ������ؼ��֣�����
	printf("����һ�� newPtr3->length == %d\n", sizeof(*newPtr3));
	printf("newPtr4 == %d, sizeof(long long) == %d\n", sizeof(*newPtr4) , sizeof( long));
	*/

	// �����ڴ�
	newPtr3 = (sequenceListNode1 *)malloc(sizeof(sequenceListNode1));                          // �����Ϊ���ռ䡣���ܲ�����ȫ�õ�
	// ѭ������
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
	// ��ʣ���(�����)һ��˳�����ӵ��µ�˳�����
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

	// 1.����
	// printf("�������Ա�: \n");
	//createSequenceList(&ptr);
	// 2.��֤����˳���ɹ�
	//printSequenceList(&ptr);

	// 1.����
	printf("�������Ա�: \n");
	sequenceListNode *newPtr1 = createSequenceList(ptr1,1);
	// 2.��֤����˳���ɹ�
	printSequenceList(newPtr1);
	//3.�ϲ�����˳�����

	// 1.����
	printf("�������Ա�: \n");
	sequenceListNode *newPtr2 = createSequenceList(ptr2, 2);
	// 2.��֤����˳���ɹ�
	printSequenceList(newPtr2);
	//3.�ϲ�����˳�����
    //newPtr1->length = 0;
	newPtr1->length = 5;
	//newPtr2->length = 0;
	sequenceListNode1 newPtr3 = (mergeTwoSequenceList(newPtr1, newPtr2));
	printf("newPtr3 length = %d\n",newPtr3.length);
	printMergeSequenceList(&newPtr3);


	system("pause");
	return 0;
}