#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int i;
    int start1 = 0, start2 = 0;
    int* res = (int*)malloc((m + n) * sizeof(int));
    memset(res, 0, (m + n) * sizeof(int));
    for (i = 0; i < nums1Size; i++) {
        if (start1 == m || start2 == n) {
            break;
        }
        if (nums1[start1] <= nums2[start2]) {
            res[i] = nums1[start1];
            start1++;
        }
        else {
            res[i] = nums2[start2];
            start2++;
        }
    }
    if (start1 == m && start2 != n) {
        for (start2; start2 < n; start2++) {
            res[i++] = nums2[start2];
        }
    }
    if (start1 != m && start2 == n) {
        for (start1; start1 < m; start1++) {
            res[i++] = nums1[start1];
        }
    }
    for (i = 0; i < nums1Size; i++) {
        nums1[i] = res[i];
    }
    free(res);
    res = NULL;
}
int main()
{
	int a[7] = { 1,3,4,5,6 };
	int b[2] = { 2,7 };
    merge(a, 7, 5, b, 2, 2);
    for (int i = 0; i < 7; i++) 
    {
        printf("%3d", a[i]);
    }

}