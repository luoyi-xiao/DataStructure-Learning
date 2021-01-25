#ifndef _STACK_H_
#define _STACK_H_

#include"Sysutil.h"

#define SEQSTACK_DEFAULT_SIZE 8
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;
// 初始化栈 
void StackInit(Stack* ps);
// 入栈 
void StackPush(Stack* ps, STDataType data);
// 出栈 
void StackPop(Stack* ps);
// 获取栈顶元素 
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数 
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);

// 销毁栈 
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
		printf("栈空间已满，不能入栈\n");
		return;
	}
	ps->_a[ps->_top++] = data;
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (-1==StackEmpty(ps))
	{
		printf("栈空，不能出栈\n");
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