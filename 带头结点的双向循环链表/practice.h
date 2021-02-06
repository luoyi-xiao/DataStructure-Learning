#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

// 带头+双向+循环链表增删查改实现
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

// 创建返回链表的头结点.
ListNode* ListCreate();

// 双向链表销毁
void ListDestory(ListNode* pHead);

// 双向链表打印
void ListPrint(ListNode* pHead);

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);

// 双向链表尾删
void ListPopBack(ListNode* pHead);

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x);

// 双向链表头删
void ListPopFront(ListNode* pHead);

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x);

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);

ListNode* ListCreate()
{
	ListNode* s = _BuyListNode(0);
	s->_prev = s->_next = NULL;
	return s;
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* s = _BuyListNode(x);
	
	//查找链表尾部
	ListNode* p = pHead;
	while (p->_next != NULL)
		p = p->_next;
	//找到尾部进行插入
	s->_prev = p;
	s->_next = NULL;
	p->_next = s;
	
}

// 双向链表头插
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

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	//找到尾指针
	if (pHead->_next == NULL)
		return;
	ListNode* p = pHead;
	while (p->_next != NULL)
		p = p->_next;
	p->_prev->_next = NULL;
	free(p);
}

// 双向链表头删
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

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* p = pHead->_next;
	while (p != NULL && p->_data != x)
		p = p->_next;
	return p;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* s = _BuyListNode(x);
	pos->_prev->_next = s;
	s->_prev = pos->_prev;
	s->_next = pos;
	pos->_prev = s;
}

// 双向链表删除pos位置的节点
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