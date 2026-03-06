#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct poly {
	int data;
	int s;  //-1은 음수, 1은 양수
}poly;

poly heap[100001];
int idx = 0;

void addheap(poly n) {
	heap[++idx] = n;
	int i;
	for (i = idx; i >= 2; i >>= 1) {
		if (n.data < heap[i / 2].data || (n.data == heap[i / 2].data && n.s < heap[i / 2].s)) heap[i] = heap[i / 2];
		else break;
	}
	heap[i] = n;
}

int delheap() {
	if (idx == 0) return 0;
	poly res = heap[1];
	heap[1] = heap[idx--];
	int parent = 1;
	int child = parent * 2;
	poly temp;
	while (child <= idx) {
		if (child < idx && (heap[child].data > heap[child + 1].data || (heap[child].data==heap[child+1].data && heap[child].s>heap[child+1].s))) child++;
		if (heap[parent].data > heap[child].data || (heap[parent].data == heap[child].data && heap[parent].s > heap[child].s)) swap(heap[child], heap[parent], temp);
		parent = child;
		child *= 2;
	}

	int r1 = res.data * res.s;
	return r1;
}

int main() {
	int n, data;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		if (!data) printf("%d\n", delheap());
		else {
			poly d = { abs(data), data > 0 ? 1 : -1 };
			addheap(d);
		}

		/*
		for (int j = 1; j <= idx; j++) {
			printf("%d ", heap[j]);
		}puts("");*/
	}

	return 0;
}
