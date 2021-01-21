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
		printf("* [10] Reverse				*\n");
		printf("* [11] Sort  				*\n");
		printf("* [12] RemoveAll  				*\n");
		printf("********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
				SListPushBack(&mylist, item);
			break;
		case 2:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
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
			printf("������Ҫ����λ�õĶ�Ӧֵ:>");
			scanf("%d", &key);
			SListNode* pos = SListFind(mylist, key);
			if (pos == NULL)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d�ڵ�ַΪ%p��λ��.\n", key, pos);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SListInsertAfter(pos, item);
			break;
		case 7:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			pos = SListFind(mylist, key);
			if (pos == NULL)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d�ڵ�ַΪ%p��λ��.\n", key, pos);
			break;
		case 8:
			printf("������Ҫɾ��λ��ǰһ��λ�ö�Ӧ��ֵ:>");
			scanf("%d", &key);
			pos = SListFind(mylist, key);
			if (pos == NULL)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("λ��Ϊ%p.\n",  pos);
				SListEraseAfter(pos);
			break;

		case 9:
			SListDestory(&mylist);
			break;

		case 10:
			SListReverse(&mylist);
			break;
		
		case 11:
			SListSort(&mylist);
			break;
		case 12:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SListRemoveAll(&mylist,key);
			break;
		system("pause");
		//system("cls");
		}
	}

	//SListDestroy(&mylist);

	return 0;
}