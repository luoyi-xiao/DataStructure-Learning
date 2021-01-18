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
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
				SeqListPushBack(&mylist, item);
			break;
		case 2:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
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
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &item);
			pos=SeqListFind(&mylist, item);
			if (pos == -1)
				printf("Ҫ���ҵ�ֵ%d������.\n", item);
			else
				printf("Ҫ���ҵ�ֵ%d���±�Ϊ%d��λ��.\n", item, pos);
			break;
		case 7:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SeqListInsert(&mylist,pos, item);
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			SeqListErase(&mylist, pos);
			break;
		case 9:
			SeqListDestory;
			break;
		}
	}
}
