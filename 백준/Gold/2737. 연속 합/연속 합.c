#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int tc, n, cnt;
	scanf("%d", &tc);
	
	while (tc--) {
		scanf("%d", &n);
		cnt = 0;
		
		--n;
		for (int i = 2; i <= n; ++i) {
			n -= i;
			if (n < 0) break;
			cnt += (n % i == 0);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
