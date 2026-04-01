#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

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
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	element ary[100002];
	ary[0].key = 0;
	ary[0].data = 0;
	n++;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &ary[i].key, &ary[i].data);
		if (ary[i].data == 0) {
			n--;
			i--;
		}
	}
	quickSort(ary, 1, n - 1);
	ary[0].key = 0;
	ary[0].data = 0;
	ary[n].key = s;
	ary[n++].data = 0;
	/*for (int i = 0; i < n; i++) {
		printf("%d %d\n", ary[i].key, ary[i].data);
	}*/
	for (int i = 0; i < n; i++) {
		if (ary[i + 1].key - (ary[i].data + ary[i].key) >= m) {
			printf("%d\n", ary[i].key + ary[i].data);
			return 0;
		}
	}
	printf("%d\n", -1);
	return 0;
}