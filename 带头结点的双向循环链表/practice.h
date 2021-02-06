#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;


ListNode* _BuyListNode(LTDataType x)
{
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->_next = s->_prev = NULL;
	s->_data = x;
	return s;
}

// �������������ͷ���.
ListNode* ListCreate();

// ˫����������
void ListDestory(ListNode* pHead);

// ˫�������ӡ
void ListPrint(ListNode* pHead);

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x);

// ˫������βɾ
void ListPopBack(ListNode* pHead);

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);

// ˫������ͷɾ
void ListPopFront(ListNode* pHead);

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x);

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);

ListNode* ListCreate()
{
	ListNode* s = _BuyListNode(0);
	s->_prev = s->_next = NULL;
	return s;
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* s = _BuyListNode(x);
	
	//��������β��
	ListNode* p = pHead;
	while (p->_next != NULL)
		p = p->_next;
	//�ҵ�β�����в���
	s->_prev = p;
	s->_next = NULL;
	p->_next = s;
	
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* s = _BuyListNode(x);
	if (pHead->_next == NULL)
	{
		pHead->_next = s;
		s->_prev = pHead;
	}
	else
	{
		s->_prev = pHead;
		s->_next = pHead->_next;
		pHead->_next->_prev = s;
		pHead->_next = s;
	}
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	//�ҵ�βָ��
	if (pHead->_next == NULL)
		return;
	ListNode* p = pHead;
	while (p->_next != NULL)
		p = p->_next;
	p->_prev->_next = NULL;
	free(p);
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListNode* p = pHead->_next;
	if (p != NULL)
	{
		pHead->_next = p->_next;
		p->_next->_prev = pHead;
		free(p);
	}
	
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* p = pHead->_next;
	while (p != NULL && p->_data != x)
		p = p->_next;
	return p;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* s = _BuyListNode(x);
	pos->_prev->_next = s;
	s->_prev = pos->_prev;
	s->_next = pos;
	pos->_prev = s;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* p = pos;
	if (p != NULL)
	{
		p->_prev->_next = p->_next;
		p->_next->_prev = p->_prev;
		free(p);
	}
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* p = pHead->_next;
	while (p != NULL)
	{
		printf("%d->", p->_data);
		p = p->_next;
	}
}

void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* p = pHead->_next;
	while (p != NULL)
	{
		ListNode* q = p;
		p = p->_next;
		free(q);
	}
}