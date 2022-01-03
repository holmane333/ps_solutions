#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int data[51][51];
int chess1[51][51] = { 0, };
int chess2[51][51] = { 0, };

int che(int y,int x) {
	int count1 = 0, count2 = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (chess1[i][j] != data[i][j]) count1++;
			if (chess2[i][j] != data[i][j]) count2++;
		}
	}
	return count1 > count2 ? count2 : count1;
}

int main() {
	int n,m;
	char scan[51];
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++) {
		scanf("%s", scan);
		for (int j = 0; j < m; j++) {
			data[i][j] = scan[j] == 'W' ? 1 : 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2) chess1[i][j] = 1;
			else chess2[i][j] = 1;
		}
	}
	int result = 100000, c;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			c = che(i, j);
			if (result > c) result = c;
		}
	}
	printf("%d\n", result);
	return 0;
}