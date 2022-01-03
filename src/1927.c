#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int heap[100001], idx = 0;

void addheap(int n) {
	heap[++idx] = n;
	int i;
	for (i = idx; i >= 2; i >>= 1) {
		if (n < heap[i / 2]) heap[i] = heap[i / 2];
		else break;
	}
	heap[i] = n;
}

int delheap() {
	if (idx == 0) return 0;
	int res = heap[1];
	heap[1] = heap[idx--];
	int parent = 1;
	int child = parent * 2;
	int temp;
	while (child <= idx) {
		if (child < idx && heap[child] > heap[child + 1]) child++;;
		if (heap[parent] > heap[child]) swap(heap[child], heap[parent], temp);
		parent = child;
		child *= 2;
	}

	return res;
}

int main() {
	int n,data;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		if (!data) printf("%d\n", delheap());
		else addheap(data);

		/*
		for (int j = 1; j <= idx; j++) {
			printf("%d ", heap[j]);
		}puts("");*/
	}

	return 0;
}
