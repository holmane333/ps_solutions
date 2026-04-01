#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int d, tree[3000001];
int len, res;

int DP(int n) {
	if (n * 2 >= len) {
		res += tree[n];
		return tree[n];
	}
	int left = DP(n * 2);
	int right = DP(n * 2 + 1);
	res += tree[n] + abs(left - right);
	return tree[n] + max(left, right);
}

int main(void) {
	scanf("%d", &d);
	len = 1 << (d + 1);
	for (int i = 2; i < len; i++) {
		scanf("%d", &tree[i]);
	}
	
	DP(1);
	printf("%d\n", res);
	
	return 0;
}
