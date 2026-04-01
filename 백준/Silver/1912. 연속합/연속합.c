#include <stdio.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
 
int main(void) {
	int n, a, dp = -2e9, res = -2e9;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
        dp = max(dp + a, a);
        res = max(res, dp);
	}
	printf("%d\n", res);
	return 0;
}