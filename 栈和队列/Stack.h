#ifndef _STACK_H_
#define _STACK_H_

#include"Sysutil.h"

#define SEQSTACK_DEFAULT_SIZE 8
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps);
// ��ջ 
void StackPush(Stack* ps, STDataType data);
// ��ջ 
void StackPop(Stack* ps);
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);

// ����ջ 
void StackDestroy(Stack* ps);

bool IsFull(Stack* ps)
{
	return ps->_top >= ps->_capacity;
}

int StackEmpty(Stack* ps)
{
	if (ps->_top == 0)
		return -1;
	return 0;
}

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_capacity = SEQSTACK_DEFAULT_SIZE;
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
	assert(ps->_a!=NULL);
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (IsFull(ps))
	{
		printf("ջ�ռ�������������ջ\n");
		return;
	}
	ps->_a[ps->_top++] = data;
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (-1==StackEmpty(ps))
	{
		printf("ջ�գ����ܳ�ջ\n");
		return;
	}
	ps->_top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps && (0==StackEmpty(ps)));
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
#endif