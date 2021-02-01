#ifndef _HEAP_H_
#define _HEAP_H_

#include"Sysutil.h"

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);

// �ѵ�����
void HeapDestory(Heap* hp);

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
bool HeapEmpty(Heap* hp);

//����������
void _AdjustUp(Heap* php, int start);
void _AdjustDown(Heap* php, int start);

// ��������ж�����
void HeapSort(int* a, int n);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
void TestTopk();

void _Heapsort(int* a, int start, int n);

bool HeapFull(Heap* php)
{
	return php->_size >= php->_capacity;
}
bool HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}

void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	assert(hp->_a != NULL);
	hp->_capacity = n;
	hp->_size = n;
	for (int i = 0; i < n; ++i)
		hp->_a[i] = a[i];
	//����������ɶ�
	int curpos = n / 2 - 1; //�ҵ������������һ����֧
	while (curpos >= 0)
	{
		_AdjustDown(hp, curpos);
		curpos--;
	}
}

void _AdjustDown(Heap* php, int start)
{
	int i = start;    //�����ڵ�
	int j = 2 * i + 1;  //����i�ڵ��������

	HPDataType tmp = php->_a[i];

	while (j < php->_size)
	{
		if (j + 1 < php->_size && php->_a[j] > php->_a[j + 1])
			j = j + 1;

		if (tmp > php->_a[j])
		{
			php->_a[i] = php->_a[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}

	php->_a[i] = tmp;
}

void HeapPush(Heap* hp, HPDataType x)
{
	if (HeapFull(hp))
	{
		printf("�ѿռ�������%d ���ܲ���.\n", x);
		return;
	}

	hp->_a[hp->_size] = x;
	_AdjustUp(hp, hp->_size);
	hp->_size++;
}

//�ϵ�
void _AdjustUp(Heap* php, int start)
{
	int j = start;  //�����ӽڵ�
	int i = (j - 1) / 2; //����j�ĸ��ڵ�

	HPDataType tmp = php->_a[j];

	while (j > 0)
	{
		if (tmp < php->_a[i])
		{
			php->_a[j] = php->_a[i];

			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	php->_a[j] = tmp;
}

//ȡջ��Ԫ��
HPDataType HeapTop(Heap* hp)
{
	if (HeapEmpty(hp))
	{
		printf("�ѿռ��ѿգ�����ȡ�Ѷ�Ԫ��.\n");
		return;
	}

	return hp->_a[0];
}

void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
	{
		printf("�ѿռ��ѿգ�����ɾ���Ѷ�Ԫ��.\n");
		return;
	}

	hp->_size--;
	hp->_a[0] = hp->_a[hp->_size];
	_AdjustDown(hp, 0);
}


int HeapSize(Heap* hp)
{
	return hp->_size;
}

void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

void HeapSort(int* a, int n)
{
	int curpos = n / 2 - 1; //�ҵ������������һ����֧
	while (curpos >= 0)
	{
		_Heapsort(a, curpos,n);
		curpos--;
	}
}

//������
void _Heapsort(int* a, int start,int n)
{
	int i = start;    //�����ڵ�
	int j = 2 * i + 1;  //����i�ڵ��������

	int tmp = a[i];

	while (j < n)
	{
		if (j + 1 < n && a[j] > a[j + 1])
			j = j + 1;

		if (tmp > a[j])
		{
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}

	a[i] = tmp;
}
#endif