#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n;
int ary[101], check[101], max = INT_MIN;

void dfs(int score, int cnt) {
	if (n - cnt <= 2) {
		max = max > score ? max : score;
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		if (!check[i]) {
			check[i] = 1;
			int l = i, r = i;
			while (check[l]) l--;
			while (check[r]) r++;
			dfs(score + (ary[l] * ary[r]), cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	dfs(0, 0);

	printf("%d\n", max);

	return 0;
}
