#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, a, idx;
int bit[40];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		idx = 0;
		scanf("%d", &a);
		while (a) {
			bit[idx++] += a & 1;
			a >>= 1;
		}
	}
	int res = -1e9;
	for (int i = 0; i < 40; ++i) res = max(res, bit[i]);
	printf("%d\n", res);
	return 0;
}