#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

long long int data[2200][2200];

int star(int n, int count) {
	if (count == 0) return 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((i == 1) && (j == 1)) continue;
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= n; l++) {
					if ((k == 2) && (l == 2)) data[i * n + k][j * n + l] = 0;
					else data[i * n + k][j * n + l] = data[k][l];
				}
			}
		}
	}
	return star(n * 3, count - 1);
}


int main() {
	int n, n1, count = -1;
	scanf("%d", &n);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if ((j == 2) && (i == 2)) data[i][j] = 0;
			else data[i][j] = 1;
		}
	}
	n1 = n;
	for (int i = 0;; i++) {
		if (n1 == 1) break;
		count++;
		n1 /= 3;
	}
	star(3, count);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%c", data[i][j] ? '*' : ' ');
		}
		puts("");
	}
}