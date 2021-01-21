/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 5
void Xuanzhuan(int *p,int Size,int k)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	k %= Size;
	for (i = 0, j = k; i < j; i++, j--)
	{
		tmp = p[i];
		p[i] = p[j];
		p[j] = tmp;
	}
	for (i = k + 1, j = Size- 1; i < j; i++, j--)
	{
		tmp = p[i];
		p[i] = p[j];
		p[j] = tmp;
	}
	for (i=0, j = Size - 1; i < j; i++, j--)
	{
		tmp = p[i];
		p[i] = p[j];
		p[j] = tmp;
	}
}
int main()
{
	int a[N] = { 0 };
	int k = 0;
	printf("输入数组元素\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d", a[i]);
		if (i ==N - 1)
			printf("\n");
	}
	printf("请输入旋转下标位：->");
	scanf("%d", &k);
	Xuanzhuan(a, N,k);
	for (int i = 0; i < N; i++)
	{
		printf("%d", a[i]);
		if (i == N - 1)
			printf("\n");
	}
}*/