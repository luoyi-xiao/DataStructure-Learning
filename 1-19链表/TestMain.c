#define _CRT_SECURE_NO_WARNINGS
#include"SLIst.h"

int main()
{

	SListNode* mylist;
	SListInit(&mylist);

	ElemType item, key;
	int pos;

	SListNode* p;

	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1] push_back             *\n");
		printf("* [2] push_front            *\n");
		printf("* [3] show_list             *\n");
		printf("* [4] pop_back              *\n");
		printf("* [5] pop_front             *\n");
		printf("* [6] insert_After          *\n");
		printf("* [7] find                  *\n");
		printf("* [8] EraseAfter            *\n");
		printf("* [9] destroy				*\n");
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SListPushBack(&mylist, item);
			break;
		case 2:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SListPushFront(&mylist, item);
			break;
		case 3:
			SListPrint(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;

		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			SListNode* pos = SListFind(mylist, key);
			if (pos == NULL)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d在地址为%p的位置.\n", key, pos);
			break;
		case 8:
			printf("请输入要删除的起始位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;

		case 9:
			SListDestory(&mylist);
			break;
		}
		system("pause");
		system("cls");
	}

	//SListDestroy(&mylist);

	return 0;
}