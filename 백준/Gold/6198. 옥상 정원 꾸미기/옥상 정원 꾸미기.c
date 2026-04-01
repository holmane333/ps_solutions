#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int n, k;
int s[100002], ft;

int main(void) {
	scanf("%d", &n);
	long long res = 0LL;
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		while (ft > 0 && s[ft - 1] <= a) --ft;
		res += (long long)ft;
		s[ft++] = a;
	}
	printf("%lld\n", res);
	
	
	return 0;
}
