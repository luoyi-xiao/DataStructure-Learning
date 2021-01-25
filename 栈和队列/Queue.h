#ifndef _QUEUE_H_
#define _QUEUE_H_

#include"Sysutil.h"

typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);


void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* s = (QNode*)malloc(sizeof(QNode));
	s->_data = data;
	s->_next = NULL;
	if (q->_front== NULL)
		q->_front = q->_rear = s;
	else
	{
		q->_rear->_next = s;
		q->_rear = s;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front != NULL)
	{
		QNode* p = q->_front;
		q->_front = q->_front->_next;
		if (q->_front == NULL)
			q->_rear = NULL;
		free(p);
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q && q->_front);
	return q->_front->_data;
}

QDataType QueueBack(Queue* q)
{
	assert(q && q->_front);
	return q->_rear->_data;
}

int QueueSize(Queue* q)
{
	assert(q);
	int len = 0;
	QNode* p = q->_front;
	while (p!=NULL)
	{
		len++;
		p = p->_next;
	}
	return len;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
		return -1;
	return 0;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->_front != NULL)
	{
		QNode* p = q->_front;
		q-> _front= p->_next;
		free(p);
	}
	q->_front = q->_rear = NULL;
}
#endif