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
		printf("* [6] ����             [7] ����pos       *\n");
		printf("* [8] ɾ��pos          [9] �ݻ�      *\n");
		printf("********************************************\n");
		printf("��ѡ��:>");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����):>");
			while (scanf_s("%d", &item), item != -1)  //���ű��ʽ
				ListPushBack(head, item);
			break;
		case 2:
			printf("������Ҫ���������(��-1����):>");
			while (scanf_s("%d", &item), item != -1)  //���ű��ʽ
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
			printf("������Ҫ���ҵ�ֵ:>");
			scanf_s("%d", &key);
			tmp = ListFind(head, key);
			if (tmp == NULL)
				printf("δ�ҵ�");
			else
				printf("��ַΪ%p", tmp);
			break;
		case 7:
			printf("������Ҫ�����λ��:>");
			scanf_s("%p", tmp);
			printf("������Ҫ�����ֵ:>");
			scanf_s("%d", &item);
			ListInsert(tmp, item);
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
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