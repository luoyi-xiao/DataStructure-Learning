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

void SListDestory(SListNode** plist);

//单链表翻转
void SListReverse(SListNode** plist);
//链表排序
void SListSort(SListNode** plist);

void SListRemoveAll(SListNode** plist,ElemType key);

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
	SListNode* s = BuySListNode(x);
	s->data = x;
	s->next = pos->next;
	pos->next = s;

}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
		return;
	SListNode* p = pos->next;
	pos->next = NULL;
	SListNode* q = p;
	while (q != NULL)
	{
		q = q->next;
		p->next = NULL;
		free(p);
		p = q;
	}

}
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

void SListReverse(SListNode** plist)
{
	assert(plist);
	if (plist == NULL)
		return;
	if ((*plist)->next == NULL)
		return;
	SListNode* p = (*plist)->next;
	(*plist)->next = NULL;
	//首先将头结点断开连接

	SListNode* q = p;
	while (q != NULL)
	{
		q = q->next;
		p->next = *plist;
		*plist = p;
		p = q;
	}
}

void SListSort(SListNode** plist)
{
	assert(plist);
	if (*plist == NULL || (*plist)->next == NULL)
		return;
	//断开链表
	SListNode* p = (*plist)->next;
	(*plist)->next = NULL;

	SListNode* q = p;
	while (q != NULL)
	{
		q = q->next;
		SListNode* t = *plist;
		SListNode* pre = NULL;
		while (t != NULL && p->data > t->data)
		{
			pre = t;
			t = t->next;
		}
		if(pre == NULL)//在头部插入
		{
			p->next = *plist;
			*plist = p;
		}
		else
		{
			p->next = pre->next;
			pre->next = p;
		}
		p = q;
	}

}


void SListRemoveAll(SListNode** plist, ElemType key)
{
	assert(plist);

	if (*plist== NULL)
		return;
	SListNode* p = *plist;
	SListNode*pre = NULL;

	while (p != NULL)
	{
		//判断及相应删除操作
		if (p->data == key)
		{
			if (pre == NULL)//头结点相等时
				*plist = p->next;
			else
				pre->next = p->next;
			free(p);
		}
		else
		{
			pre = p;
			//p = p->next;
		}
		//指针移位
		if (pre == NULL)//删除的是头结点
			p = *plist;
		else //删除的是普通节点
			p = pre->next;
	}
}

#endif