#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
int main()
{

	SeqList mylist;
	SeqListInit(&mylist);

	SLDateType item;
	int pos;

	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("*************[1] SeqListPushBack           *\n");
		printf("*************[2] SeqListPushFront          *\n");
		printf("*************[3] SeqListPrint			   *\n");			
		printf("*************[4] SeqListPopBack            *\n");
		printf("*************[5] SeqListPopFront           *\n");
		printf("*************[6] SeqListFind               *\n");
		printf("*************[7] SeqListInsert             *\n");
		printf("*************[8] SeqListErase              *\n");
		printf("*************[9] SeqListDestory            *\n");
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SeqListPushBack(&mylist, item);
			break;
		case 2:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SeqListPushFront(&mylist, item);
			break;
		case 3:
			SeqListPrint(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要查找的值:>");
			scanf("%d", &item);
			pos=SeqListFind(&mylist, item);
			if (pos == -1)
				printf("要查找的值%d不存在.\n", item);
			else
				printf("要查找的值%d在下标为%d的位置.\n", item, pos);
			break;
		case 7:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			SeqListInsert(&mylist,pos, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListErase(&mylist, pos);
			break;
		case 9:
			SeqListDestory;
			break;
		}
	}
}
