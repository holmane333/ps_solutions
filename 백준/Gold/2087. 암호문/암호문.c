#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct pair {
	int x, idx;
} pair;

int n, m, a[50], sum1[1 << 21];
pair sum2[1 << 21];

int cmp(const void* num1, const void* num2) {
	if ((*(pair*)num1).x == (*(pair*)num2).x) return (*(pair*)num1).idx < (*(pair*)num2).idx;
	return (*(pair*)num1).x > (*(pair*)num2).x;
}

int lower_bound(int s, int e, int t) {
	int mid;
	while (s < e) {
		mid = (s + e) / 2;
		if (sum2[mid].x >= t) e = mid;
		else s = mid + 1;
	}
	return e;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	
	int nn1 = n / 2;
	int nn2 = n - nn1;
	int t1 = (1 << nn1), t2 = (1 << nn2), temp;
	for (int i = 0; i < t1; ++i) {
		temp = 0;
		for (int j = 0; j < nn1; ++j) {
			if (i & (1 << j)) temp += a[j];
		}
		sum1[i] = temp;
	}
	
	for (int i = 0; i < t2; ++i) {
		temp = 0;
		for (int j = 0; j < nn2; ++j) {
			if (i & (1 << j)) temp += a[nn1 + j];
		}
		sum2[i].x = temp;
		sum2[i].idx = i;
	}
	
	qsort(sum2, t2, sizeof(pair), cmp);
	
	int l;
	for (int i = 0; i < t1; ++i) {
		l = lower_bound(0, t2 - 1, m - sum1[i]);
		if (l < 0 || l >= t2) continue;
		if (sum2[l].x == m - sum1[i]) {
			//printf("%d %d %d %d %d %d\n", i, l, sum1[i], sum2[l], m - sum1[i], sum1[i] + sum2[l]);
			while (nn1--) {
				printf("%d", i & 1);
				i >>= 1;
			}
			l = sum2[l].idx;
			while (nn2--) {
				printf("%d", l & 1);
				l >>= 1;
			}
			break;
		}
	}
	puts("");
	return 0;
}
