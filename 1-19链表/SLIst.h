#ifndef _SLIST_H_
#define _SLIST_H_
#define ElemType int

#include"Sysutil.h"
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;



// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁

//1.初始化
void SListInit(SListNode** pplist)
{
	assert(pplist);
	*pplist = NULL;
}

//节点创建
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s!=NULL);
	s->data = x;
	s->next = NULL;
	return s;

}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* s = BuySListNode(x);
	SListNode* p = *pplist;
	if (p == NULL)
		*pplist = s;
	else {
		while (p->next != NULL)
			p = p->next;
		p -> next = s;
	}

}


// 单链表打印
void SListPrint(SListNode**plist)
{
	assert(plist);
	SListNode* p = *plist;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* p = *pplist;
	SListNode* s = BuySListNode(x);
	s->next = p;
	*pplist = s;
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	SListNode* p = *pplist;
	if (p!=NULL)
	{
		if (p->next == NULL)
			*pplist = NULL;
		else
		{
			SListNode* pre = NULL;
			while (p->next != NULL)
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;
		}
		free(p);
	}

}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	SListNode* p = *pplist;
	if (p != NULL)
	{
		*pplist = p->next;
		free(p);
	}
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* p = plist;
	while (p != NULL && p->data != x)
		p = p->next;
	return p;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestory(SListNode** plist)
{
	assert(plist);
	SListNode* p = *plist;
	while (p != NULL)
	{
		*plist = p->next;
		free(p);
		p = *plist;
	}
}

#endif