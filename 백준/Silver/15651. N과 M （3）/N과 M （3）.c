#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int count = 0;
int mat1[10];


void z(int n, int m) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", mat1[i]);
		}
		puts("");
	}
	else {
		for (int i = 1; i <= n; i++) {
			mat1[count++] = i;
			z(n, m);
			mat1[--count] = 0;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	z(n, m);
	return 0;
}