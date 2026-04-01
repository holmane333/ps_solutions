#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)

int data[9][2], result[5];
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void sort1(int list[][2], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i + 1; j < size;j++) {
			if (list[i][0] > list[j][0]) {
				swap(&list[i][0], &list[j][0]);
				swap(&list[i][1], &list[j][1]);
			}
		}
	}
}
void sort2(int list[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (list[i] > list[j]) swap(&list[i], &list[j]);
		}
	}
}

int main() {
	for (int i = 1; i <= 8; i++) {
		scanf("%d", &data[i][0]);
		data[i][1] = i;
	}
	sort1(data, 9);
	int sum = 0;
	for (int i = 8; i > 3; i--) {
		sum += data[i][0];
	}
	printf("%d\n", sum);
	for (int i = 4; i <= 8; i++) {
		result[i-4] = data[i][1];
	}
	sort2(result,5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", result[i]);
	}

	return 0;
}