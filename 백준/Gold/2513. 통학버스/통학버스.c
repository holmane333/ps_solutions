#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct element {
	int key;
	int data;
}element;

void quickSort(element a[], int left, int right) {
	int pivot, i, j;
	element temp;
	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].key;
		do {
			do i++; while (a[i].key < pivot);
			do j--; while (a[j].key > pivot);
			if (i < j) swap(a[i], a[j], temp);
		} while (i < j);
		swap(a[left], a[j], temp);
		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}

int main() {
	element dis[50000];
	int n, k, s;
	long long cnt = 0;
	scanf("%d %d %d", &n, &k, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &dis[i].key, &dis[i].data);
		if (dis[i].data > k) {
			dis[i].data -= k;
			cnt += (long long)abs(dis[i].key - s) * 2LL;
		}
	}
	dis[n].key = s;
	dis[n].data = 0;
	quickSort(dis, 0, n);
	int idx = -1;
	for (int i = 0; i <= n; i++) if (dis[i].key == s) idx = i;
	for (int i = 0; i < idx;) {
		int size = 0, j = i;
		for (; j < idx; j++) {
			size += dis[j].data;
			if (size > k) {
				dis[j].data = size - k;
				break;
			}
		}
		cnt += (s - dis[i].key) * 2;
		i = j;
	}
	for (int i = n; i > idx;) {
		int size = 0, j = i;
		for (; j > idx; j--) {
			size += dis[j].data;
			if (size > k) {
				dis[j].data = size - k;
				break;
			}
		}
		cnt += (dis[i].key - s) * 2;
		i = j;
	}
	printf("%lld\n", cnt);

	return 0;
}