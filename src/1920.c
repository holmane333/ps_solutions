#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#define COMPARE(x, y)  ( ( (x) < (y) ) ? -1 : ((x) == (y)) ? 0 : 1 )

int cmpfunc(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	return 0;
}

int val1[100001], val2[100001];

int binsearch(int list[], int searchnum, int left, int right) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum)) {
		case -1:
			left = middle + 1;
			break;
		case 0:
			return 1;
		case 1:
			right = middle - 1;
		}
	}
	return 0;
}


int main() {
	int n1, n2;
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
		scanf("%d", &val1[i]);
	qsort(val1, n1, sizeof(int), cmpfunc);
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
		scanf("%d", &val2[i]);
	for (int i = 0; i < n2; i++) {
		printf("%d\n", binsearch(val1, val2[i], 0, n1 - 1));
	}
	return 0;
}