#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define ll long long

int main(void) {
	int n, m, a, b, x, y;
	int map[100010] = {0, };
	scanf("%d %d %d %d", &n, &m, &a, &b);
	while (m--) {
		scanf("%d %d", &x, &y);
		for (int i = x; i <= y; ++i) map[i] = -1;
	}
	
	int q[100010], v[100010] = {0, }, ft = 0, rr = 0, temp;
	q[ft++] = 0;
	v[0] = 1;
	while (ft != rr) {
		temp = q[rr++];
		if (rr >= 100000) rr = 0;
		if (temp + a <= n && map[temp + a] != -1 && !v[temp + a]) {
			v[temp + a] = v[temp] + 1;
			q[ft++] = temp + a;
			if (ft >= 100000) ft = 0;
			if (temp + a == n) {
				printf("%d\n", v[temp]);
				return 0;
			}
		}
		if (temp + b <= n && map[temp + b] != -1 && !v[temp + b]) {
			v[temp + b] = v[temp] + 1;
			q[ft++] = temp + b;
			if (ft >= 100000) ft = 0;
			if (temp + b == n) {
				printf("%d\n", v[temp]);
				return 0;
			}
		}
	}
	
	printf("-1\n");
	return 0;
}
