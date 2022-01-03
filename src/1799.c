#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int flag_a[100000];
int flag_b[100000];
int count = 0, Max1 = 0, Max2 = 0;
int n, bs1[101][2], bs2[101][2], map[11][11], idx1 = 0, idx2 = 0;

void set(int i, int t) {
	int x, y;
	if (t == 0) {
		if (i == idx1) {
			Max1 = max(Max1, count);
			return;
		}
	
		x = bs1[i][0];
		y = bs1[i][1];
	}
	else {
		if (i == idx2) {
			Max2 = max(Max2, count);
			return;
		}
		
		x = bs2[i][0];
		y = bs2[i][1];
	}
	if (!flag_a[x + y] && !flag_b[x - y + 10]) {
		count++;
		flag_a[x + y] = 1;
		flag_b[x - y + 10] = 1;
		set(i + 1, t);
		count--;
		flag_a[x + y] = 0;
		flag_b[x - y + 10] = 0;
	}
	set(i + 1, t);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) {
				if ((i + j) % 2 == 0) {
					bs1[idx1][0] = i;
					bs1[idx1++][1] = j;
				}
				else {
					bs2[idx2][0] = i;
					bs2[idx2++][1] = j;
				}
			}
		}
	}
	set(0, 0);
	count = 0;
	memset(flag_a, 0, sizeof(flag_a));
	memset(flag_b, 0, sizeof(flag_b));
	set(0, 1);
	printf("%d\n", Max1 + Max2);


	return 0;
}