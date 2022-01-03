#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int max_heap[100001], min_heap[100001], idx_max = 0, idx_min = 0;

void add_max_heap(int n) {
	max_heap[++idx_max] = n;
	int i;
	for (i = idx_max; i >= 2; i >>= 1) {
		if (n > max_heap[i / 2]) max_heap[i] = max_heap[i / 2];
		else break;
	}
	max_heap[i] = n;
}

int del_max_heap() {
	if (idx_max == 0) return 0;
	int res = max_heap[1];
	max_heap[1] = max_heap[idx_max--];
	int parent = 1;
	int child = parent * 2;
	int temp;
	while (child <= idx_max) {
		if (child < idx_max && max_heap[child] < max_heap[child + 1]) child++;
		if (max_heap[parent] < max_heap[child]) swap(max_heap[child], max_heap[parent], temp);
		parent = child;
		child *= 2;
	}

	return res;
}

void add_min_heap(int n) {
	min_heap[++idx_min] = n;
	int i;
	for (i = idx_min; i >= 2; i >>= 1) {
		if (n < min_heap[i / 2]) min_heap[i] = min_heap[i / 2];
		else break;
	}
	min_heap[i] = n;
}

int del_min_heap() {
	if (idx_min == 0) return 0;
	int res = min_heap[1];
	min_heap[1] = min_heap[idx_min--];
	int parent = 1;
	int child = parent * 2;
	int temp;
	while (child <= idx_min) {
		if (child < idx_min && min_heap[child] > min_heap[child + 1]) child++;;
		if (min_heap[parent] > min_heap[child]) swap(min_heap[child], min_heap[parent], temp);
		parent = child;
		child *= 2;
	}

	return res;
}

int main() {
	int n, data, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		if (i % 2 == 0) add_max_heap(data);
		else add_min_heap(data);
		if (idx_min != 0 && max_heap[1] > min_heap[1]) {
			int max_v = del_max_heap();
			int min_v = del_min_heap();
			add_max_heap(min_v);
			add_min_heap(max_v);
		}
		printf("%d\n", max_heap[1]);
	}
	
	return 0;
}
