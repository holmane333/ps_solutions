#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int n, k;
int q[22][300002], ft[22], rr[22];

int main(void) {
	scanf("%d %d", &n, &k);
	long long res = 0LL;
	for (int i = 1; i <= n; ++i) {
		char a[22];
		scanf("%s", a);
		int l = strlen(a);
		while (ft[l] != rr[l]) {
			if (q[l][ft[l]] < i - k) ++ft[l];
			else break;
		}
		res += (long long)rr[l] - ft[l];
		q[l][rr[l]++] = i;
	}
	printf("%lld\n", res);
	
	
	return 0;
}
