#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int main(void) {
	int n;
	scanf("%d", &n);
	int ary2[7] = {5000000, 3000000, 2000000, 500000, 300000, 100000}, ary3[7] = {5120000, 2560000, 1280000, 640000, 320000}, ary4[7] = {1, 2, 3, 4, 5, 6}, ary5[7] = {1, 2, 4, 8, 16}, res1[101] = {0, }, res2[65] = {0, };
	int cnt = 1;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < ary4[i]; j++) {
			res1[cnt++] = ary2[i];
		}
	}
	cnt = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < ary5[i]; j++) {
			res2[cnt++] = ary3[i];
		}
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", res1[a] + res2[b]);
	}
	
	return 0;
}
