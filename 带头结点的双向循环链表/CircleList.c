#include"practice.h"
#define _CRT_SECURE_NO_WARNINGS 1  

int main()
{
	ListNode* head;
	head = ListCreate();

	LTDataType item, key;
	LTDataType* tmp=NULL;
	int pos;

	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1] push_back        [2] push_front      *\n");
		printf("* [3] show_list        [0] quit_system     *\n");
		printf("* [4] pop_back         [5] pop_front       *\n");
		printf("* [6] 查找             [7] 插入pos       *\n");
		printf("* [8] 删除pos          [9] 摧毁      *\n");
		printf("********************************************\n");
		printf("请选择:>");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf_s("%d", &item), item != -1)  //逗号表达式
				ListPushBack(head, item);
			break;
		case 2:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf_s("%d", &item), item != -1)  //逗号表达式
				ListPushFront(head, item);
			break;
		case 3:
			ListPrint(head);
			break;
		case 4:
			ListPopBack(head);
			break;
		case 5:
			ListPopFront(head);
			break;
		case 6:
			printf("请输入要查找的值:>");
			scanf_s("%d", &key);
			tmp = ListFind(head, key);
			if (tmp == NULL)
				printf("未找到");
			else
				printf("地址为%p", tmp);
			break;
		case 7:
			printf("请输入要插入的位置:>");
			scanf_s("%p", tmp);
			printf("请输入要插入的值:>");
			scanf_s("%d", &item);
			ListInsert(tmp, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf_s("%p", tmp);
			ListErase(tmp);
			break;
		case 9:
			ListDestory(head);
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}