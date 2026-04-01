#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int pos[81];
int n;

void print() {
	for (int i = 1; i <= n; i++) {
		printf("%d", pos[i]);
	}
	exit(0);
}

void set(int m) {
	int t = 0, countt;
	for (int i = 1; i <= 3; i++) {
		pos[m] = i;
		t = 0;
		for (int j = 1; j <= m / 2; j++) {
			countt = 0;
			for (int k = m, count = 0; count < j; count++, k--) {
				if (pos[k] == pos[k - j]) countt++;
			}
			if (countt == j) {
				t = 1;
				break;
			}
		}
		if (t == 0) {
			if (m == n) print();
			set(m + 1);
		}
		pos[m] = 0;
	}
}

int main() {
	scanf("%d", &n);
	pos[1] = 1;
	set(1);
	return 0;
}