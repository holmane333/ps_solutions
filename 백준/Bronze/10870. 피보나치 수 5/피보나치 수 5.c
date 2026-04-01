#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

void z(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t + *a;
}

int main() {
	int n, a = 1, b = 1;
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		z(&a, &b);
	}
	printf("%d\n", n ? a : 0);
	return 0;
}