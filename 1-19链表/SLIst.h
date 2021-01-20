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



// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������

//1.��ʼ��
void SListInit(SListNode** pplist)
{
	assert(pplist);
	*pplist = NULL;
}

//�ڵ㴴��
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s!=NULL);
	s->data = x;
	s->next = NULL;
	return s;

}

// ������β��
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


// �������ӡ
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

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* p = *pplist;
	SListNode* s = BuySListNode(x);
	s->next = p;
	*pplist = s;
}

// �������βɾ
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

// ������ͷɾ
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

// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* p = plist;
	while (p != NULL && p->data != x)
		p = p->next;
	return p;
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������
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