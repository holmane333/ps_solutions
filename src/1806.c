#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int main(void) {
	int n, s;
	int ary[100001];
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	int low = 0, high = 0;
	int res = INT_MAX, sum = ary[0];
	while (low <= high && high < n) {
		if (sum > s) {
			res = min(res, high - low + 1);
			sum -= ary[low++];
		}
		else if (sum == s) {
			res = min(res, high - low + 1);
			sum += ary[++high];
		}
		else {
			sum += ary[++high];
		}
		//printf("%d %d %d %d\n", low, high, sum, res);
		if (res == 1) break;
	}
	
	if (res == INT_MAX) printf("%d\n", 0);
	else printf("%d\n", res);
	
	return 0;
}
