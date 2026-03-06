#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void hanoi(int n,int a,int b,int c) {
	if (n == 1) {
		printf("%d %d\n", a, c);
		return;
	}
	hanoi(n - 1, a, c, b);
	printf("%d %d\n", a, c);
	hanoi(n - 1, b, a, c);
	return;
}
int main() {
	int n,m;
	scanf("%d", &n);
	m = 1;
	for (int i = 0; i < n-1; i++) {
		m = m * 2 + 1;
	}
	printf("%d\n", m);
	hanoi(n, 1, 2, 3);
}