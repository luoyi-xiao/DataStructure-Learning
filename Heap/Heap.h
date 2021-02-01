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

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);

// 堆的销毁
void HeapDestory(Heap* hp);

// 堆的插入
void HeapPush(Heap* hp, HPDataType x);

// 堆的删除
void HeapPop(Heap* hp);

// 取堆顶的数据
HPDataType HeapTop(Heap* hp);

// 堆的数据个数
int HeapSize(Heap* hp);

// 堆的判空
bool HeapEmpty(Heap* hp);

//调整：排序
void _AdjustUp(Heap* php, int start);
void _AdjustDown(Heap* php, int start);

// 对数组进行堆排序
void HeapSort(int* a, int n);

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
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
	//将数组排序成堆
	int curpos = n / 2 - 1; //找到二叉树的最后一个分支
	while (curpos >= 0)
	{
		_AdjustDown(hp, curpos);
		curpos--;
	}
}

void _AdjustDown(Heap* php, int start)
{
	int i = start;    //代表父节点
	int j = 2 * i + 1;  //代表i节点的左子树

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
		printf("堆空间已满，%d 不能插入.\n", x);
		return;
	}

	hp->_a[hp->_size] = x;
	_AdjustUp(hp, hp->_size);
	hp->_size++;
}

//上调
void _AdjustUp(Heap* php, int start)
{
	int j = start;  //代表子节点
	int i = (j - 1) / 2; //代表j的父节点

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

//取栈顶元素
HPDataType HeapTop(Heap* hp)
{
	if (HeapEmpty(hp))
	{
		printf("堆空间已空，不能取堆顶元素.\n");
		return;
	}

	return hp->_a[0];
}

void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
	{
		printf("堆空间已空，不能删除堆顶元素.\n");
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
	int curpos = n / 2 - 1; //找到二叉树的最后一个分支
	while (curpos >= 0)
	{
		_Heapsort(a, curpos,n);
		curpos--;
	}
}

//堆排序
void _Heapsort(int* a, int start,int n)
{
	int i = start;    //代表父节点
	int j = 2 * i + 1;  //代表i节点的左子树

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