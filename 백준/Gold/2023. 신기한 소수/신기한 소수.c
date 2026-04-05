#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int pos[10];
int n;

void print() {
	for (int i = 1; i <= n; i++) {
		printf("%d", pos[i]);
	}
	puts("");
}

void set(int m) {
	int t = 0, countt, l = 0;
	for (int i = 1; i < m; i++) {
		l += pos[i] * (pow(10, (m - i)));
	}
	for (int i = 1; i <= 9; i++) {
		if (m == 1 && i % 2 == 0 && i != 2) continue;
		if (m == 1 && i == 1) continue;
		if (m != 1 && i % 2 == 0) continue;
		l += i;
		pos[m] = i;
		t = 0;
		for (int j = 2; j * j <= l; j++) {
			if (l % j == 0) {
				t = 1;
				break;
			}
		}
		if (t == 0) {
			if (m == n) print();
			else set(m + 1);
		}
		l -= i;
		pos[m] = 0;
	}
}

int main() {
	scanf("%d", &n);
	set(1);
	return 0;
}