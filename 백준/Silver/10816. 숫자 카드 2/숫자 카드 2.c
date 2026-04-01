#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int arr[500001];

int lower_binary(int target, int size) {
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start) {
		mid = (start + end) / 2;
		if (arr[mid] >= target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}

int upper_binary(int target, int size) {
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start) {
		mid = (start + end) / 2;
		if (arr[mid] > target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a > * (int*)b ? 1 : *(int*)a < *(int*)b ? -1 : 0);
}

int main() {
	int n, m, data;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	arr[n++] = 10000001;
	scanf("%d", &m);

	qsort(arr, n, sizeof(int), cmpfunc);

	for (int i = 0; i < m; i++) {
		scanf("%d", &data);
		printf("%d\n", upper_binary(data, n) - lower_binary(data, n));
	}
	return 0;
}

