#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int pos[26][26];
int n;

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void set(int i, int j, int k) {
	pos[i][j] = k;
	if (j + 1 <= n && pos[i][j + 1] == 1) {
		set(i, j + 1, k);
	}
	if (i + 1 <= n && pos[i + 1][j] == 1) {
		set(i + 1, j, k);
	}
	if (j - 1 >= 1 && pos[i][j - 1] == 1) {
		set(i, j - 1, k);
	}
	if (i - 1 >= 1 && pos[i - 1][j] == 1) {
		set(i - 1, j, k);
	}
}

int main() {
	char str[26];
	int count = 2;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &str);
		for (int j = 1; j <= n; j++) {
			pos[i][j] = (int)str[j - 1]-48;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (pos[i][j] == 1) {
				set(i, j, count);
				count++;
			}
		}
	}
	count -= 2;
	int values[5000] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (pos[i][j] != 0) values[pos[i][j] - 2]++;
		}
	}
	qsort(values, count, sizeof(int), cmpfunc);
	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%d\n", values[i]);
	}
	return 0;
}