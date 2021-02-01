#include"Heap.h"

int main()
{
	Heap hp;
	HPDataType ar[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(ar) / sizeof(ar[0]);

	HeapCreate(&hp, ar, n);
	HeapSort(ar,n);

	while (!HeapEmpty(&hp))
	{
		HPDataType top_val = HeapTop(&hp);
		printf("%d ", top_val);
		HeapPop(&hp);
	}
	printf("\n");

	return 0;
}