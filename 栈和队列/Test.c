#include"Queue.h"
/*#include"Stack.h"
void main()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	printf("============\n");

	while (StackEmpty(&st)==0)
	{
		STDataType val = StackTop(&st);
		StackPop(&st);
		printf("%d 出栈.\n", val);
	}
	printf("出栈完毕.\n");

	StackDestroy(&st);
}*/
void main()
{
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q, 1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	QueuePush(&Q, 4);
	QueuePush(&Q, 15);
	QueuePush(&Q, 6);
	//QueueShow(&Q);
	printf("==============\n");

	QDataType val = QueueFront(&Q);
	QueuePop(&Q);
	printf("%d 出队.\n", val);

	QueueDestroy(&Q);
}