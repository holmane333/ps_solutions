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
	int res = 0, sum = ary[0];
	while (low <= high && high < n) {
		if (sum > s) {
			sum -= ary[low++];
			if (low > high && low < n) {
				high = low;
				sum = ary[high];
			}
		}
		else if (sum == s) {
			res++;
			sum += ary[++high];
		}
		else {
			sum += ary[++high];
		}
		//printf("%d %d %d %d\n", low, high, sum, res);
	}
	
	printf("%d\n", res);
	
	return 0;
}
