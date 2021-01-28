#include"Tree.h"

void main()
{
	char* str = "ABC##DE##F##G#H##";
	BinTree bt;
	BinTreeInit(&bt);

	//BinTreeCreate_1(&bt);
	//bt = BinTreeCreate_2();

	int index = 0;
	bt = BinTreeCreate_3(str, &index);

	printf("VLR : ");
	//PreOrder(bt);
	PreOrder_Nor(bt);
	printf("\n");
	printf("LVR : ");
	InOrder(bt);
	printf("\n");
	printf("LRV : ");
	PostOrder(bt);
	printf("\n");
	printf("Level : ");
	LevelOrder(bt);
	printf("\n");

	printf("Size = %d\n", Size(bt));   //8
	printf("Height = %d\n", Height(bt));   //

	char key = 'D';
	BinTreeNode* p = Find(bt, key);

	BinTreeNode* pr = Parent(bt, p);

	BinTree bt1 = Clone(bt);

	//bool flag = Equal(bt, bt1);

}