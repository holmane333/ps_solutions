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
	int n;
	scanf("%d", &n);
	int ary[1000002];
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	int c1 = -1, c2 = -1, check1 = 0, check2 = 0;
	for (int i = 1; i < n; i++) {
		if (ary[i-1] < ary[i]) {
			if (c1 != -1) check1 = 1;
			c1 = i;
		}
		if (ary[i - 1] > ary[i]) {
			if (c2 != -1) check2 = 1;
			c2 = i;
		}
	}
	if (c1 != -1 && ary[0] > ary[n - 1]) check1 = 1;
	if (c2 != -1 && ary[0] < ary[n - 1]) check2 = 1;

	if (check1 == 1 && check2 == 1) {
		printf("%d\n", -1);
	}
	else if (c1 == -1 || c2 == -1) {
		printf("%d\n", 0);
	}
	else if (check1 == 1) {
		printf("%d\n", c2);
	}
	else if (check2 == 1) {
		printf("%d\n", c1);
	}
	else {
		printf("%d\n", c1 < c2 ? c1 : c2);
	}
	return 0;
}