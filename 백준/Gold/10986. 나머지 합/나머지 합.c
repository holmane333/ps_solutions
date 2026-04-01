#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
 
int n, m;
long long int ary[1000001];
long long int sum[1000001];
long long int modulo[1001];
 
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ary[i]);
		if (i == 0) sum[i] = ary[i];
		else sum[i] = sum[i - 1] + ary[i];
		modulo[sum[i] % m] += 1;
	}
	modulo[0] += 1;
 
	long long int res = 0;
	for (int i = 0; i < m; i++) {
		if (modulo[i] <= 1) continue;
		res += modulo[i] * (modulo[i] - 1) / 2;
	}
 
	printf("%lld\n", res);
 
	return 0;
}
 