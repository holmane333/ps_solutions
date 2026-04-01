#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

int n, a[60], m[60][60], len[60], v[60], d[60];
int prime_i[10010];

int cmp(const void* num1, const void* num2) {
	return *(int*)num1 > *(int*)num2;
}

void eratos() {
	for (int i = 2; i * i <= 10000; ++i) {
		if (!prime_i[i]) {
			for (int j = i * i; j <= 10000; j += i) 
				prime_i[j] = 1;
		}
	}
}

int find(int x) {
	for (int i = 0; i < len[x]; ++i) {
		if (v[m[x][i]]) continue;
		v[m[x][i]] = 1;
		if (!d[m[x][i]] || find(d[m[x][i]])) {
			d[x] = m[x][i];
			d[m[x][i]] = x;
			return 1;
		}
	}
	
	return 0;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	
	qsort(a + 2, n - 1, sizeof(int), cmp);
	eratos();
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			if (!prime_i[a[i] + a[j]]) m[i][len[i]++] = j;
		}
	}
	
	int cnt = 0, c;
	for (int i = 0; i < len[1]; ++i) {
		c = 0;
		memset(d, 0, sizeof(d));
		for (int j = 2; j <= n; ++j) {
			if (j == m[1][i]) continue;
			memset(v, 0, sizeof(v));
			v[1] = v[m[1][i]] = 1;
			if (!d[j] && !find(j)) {
				c = 1;
				break;
			}
		}
		if (!c) {
			printf("%d ", a[m[1][i]]);
			cnt = 1;
		}
	}
	
	if (cnt) puts("");
	else puts("-1");
	return 0;
}
