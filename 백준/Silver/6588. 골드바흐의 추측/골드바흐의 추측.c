#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int l[1000001];
int data[100001];
int sosu(int n) {
	for (int i = 2; i < n + 1; i++) {
		if (l[i] == -1) {
			for (int j = 2 * i; j < n + 1; j += i) {
				l[j] = 0;
			}
		}
	}
	return 0;
}


int main() {
	memset(l, -1, sizeof(l));
	l[0] = 0;
	l[1] = 0;
	int max = 0,i,a;
	for (i = 0;; i++) {
		scanf("%d", &a);
		if (a == 0) break;
		if (max < a) max = a;
		data[i] = a;
	}
	sosu(max);
	for (int j = 0; j < i ; j++) {
		a = data[j];
		for (int k = 3; k < a; k++) {
			if (k > a / 2) {
				printf("Goldbach's conjecture is wrong.\n");
				break;
			}
			if (l[k] && l[a - k]) {
				printf("%d = %d + %d\n", a, k, a - k);
				break;
			}
		}
	}
	return 0;
}