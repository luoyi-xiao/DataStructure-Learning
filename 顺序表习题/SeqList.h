#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>


#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 4

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;

bool IsFull(SeqList* ps)
{
	return ps->size >= ps->capacity;
}
bool IsEmpty(SeqList* ps)
{
	return ps->size == 0;
}

bool _Inc(SeqList* pst)
{
	//申请新空间
	SLDateType* new_base = (SLDateType*)malloc(sizeof(SLDateType) * (pst->capacity * 2));
	if (new_base == NULL)
	{
		printf("扩容失败.\n");
		return false;
	}
	//拷贝数据
	memcpy(new_base, pst->a, sizeof(SLDateType) * pst->capacity);

	//释放旧空间
	free(pst->a);

	//更改base的指向
	pst->a = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}


// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);//头删
void SeqListPopBack(SeqList* ps);//尾删

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);


void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * SEQLIST_DEFAULT_SIZE);
	assert(ps->a != NULL);
	memset(ps->a, 0, sizeof(SLDateType) * SEQLIST_DEFAULT_SIZE);
	ps->capacity = SEQLIST_DEFAULT_SIZE;
	ps->size = 0;
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	if (IsFull(ps) && !_Inc(ps))
	{
		printf("顺序表已满，%d不能尾部插入。\n", x);
		return;
	}
	ps->a[ps->size++] = x;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	if (IsFull(ps) && !_Inc(ps))
	{
		printf("顺序表已满，%d不能头 部插入。\n", x);
		return;
	}
	//先移动数据
	for (int i = ps->size; i > 0; --i)
		ps->a[i] = ps->a[i - 1];

	ps->a[0] = x;
	ps->size++;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i) 
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (IsEmpty(ps))
	{
		printf("顺序表已空, 不能尾部删除.\n");
		return;
	}
	ps->size--;
}

//头删
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	if (IsEmpty(ps))
	{
		printf("顺序表已空, 不能头部删除.\n");
		return;
	}
	for (int i = 0; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i= 0; i < ps->size; i++)
	{
		if (x == ps->a[i])
			return i;
	}
	return -1;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	if (IsFull(ps) && !_Inc(ps))
	{
		printf("顺序表已满，%d不能插入。\n", x);
		return;
	}
	if (pos<0 || pos>ps->size)
	{
		printf("插入的位置非法，%d 不能按位置插入.\n", x);
		return;
	}
	for (int i = ps->size; i >pos; i++)
	{
		ps->a[i] = ps->a[i-1];
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	if (IsEmpty)
	{
		printf("顺序表为空。\n");
		return;
	}
	if (pos<0 || pos>ps->size)
	{
		printf("删除的位置非法，不能按位置删除.\n");
		return;
	}
	for (int i = ps; i<ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListDestory(SeqList* ps)
{

	assert(ps);
	free(ps->a);
	ps->a = NULL; // 预防野指针
	ps->capacity = ps->size = 0;


}
#endif