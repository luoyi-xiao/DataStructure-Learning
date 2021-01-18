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
	//�����¿ռ�
	SLDateType* new_base = (SLDateType*)malloc(sizeof(SLDateType) * (pst->capacity * 2));
	if (new_base == NULL)
	{
		printf("����ʧ��.\n");
		return false;
	}
	//��������
	memcpy(new_base, pst->a, sizeof(SLDateType) * pst->capacity);

	//�ͷžɿռ�
	free(pst->a);

	//����base��ָ��
	pst->a = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}


// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);//ͷɾ
void SeqListPopBack(SeqList* ps);//βɾ

// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
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
		printf("˳���������%d����β�����롣\n", x);
		return;
	}
	ps->a[ps->size++] = x;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	if (IsFull(ps) && !_Inc(ps))
	{
		printf("˳���������%d����ͷ �����롣\n", x);
		return;
	}
	//���ƶ�����
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

//βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (IsEmpty(ps))
	{
		printf("˳����ѿ�, ����β��ɾ��.\n");
		return;
	}
	ps->size--;
}

//ͷɾ
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	if (IsEmpty(ps))
	{
		printf("˳����ѿ�, ����ͷ��ɾ��.\n");
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
		printf("˳���������%d���ܲ��롣\n", x);
		return;
	}
	if (pos<0 || pos>ps->size)
	{
		printf("�����λ�÷Ƿ���%d ���ܰ�λ�ò���.\n", x);
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
		printf("˳���Ϊ�ա�\n");
		return;
	}
	if (pos<0 || pos>ps->size)
	{
		printf("ɾ����λ�÷Ƿ������ܰ�λ��ɾ��.\n");
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
	ps->a = NULL; // Ԥ��Ұָ��
	ps->capacity = ps->size = 0;


}
#endif