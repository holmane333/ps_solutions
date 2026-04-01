#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int arr1[10], arr2[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr2[i]);
	}
	qsort(arr1, 10, sizeof(int), cmpfunc);
	qsort(arr2, 10, sizeof(int), cmpfunc);
	printf("%d %d\n", arr1[9] + arr1[8] + arr1[7], arr2[9] + arr2[8] + arr2[7]);
	return 0;
}