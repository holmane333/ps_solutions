#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define ll long long

int n, k;
long long int ary[1000001];

int compare(const void *a, const void *b) {
    int num1 = *(long long int *)a;    
    int num2 = *(long long int *)b;
    if (num1 < num2)    
        return -1;      
    if (num1 > num2)    
        return 1;
    return 0;
}

int check(long long int h) {
	long long int t = 0LL;
	for (int i = 0; i < n; i++) {
		t += ary[i] - h > 0LL ? ary[i] - h : 0LL;
	}
	//printf("%lld %lld %lld\n", h, k, t);
	if (t >= k) return 1;
	return 0;
}

int main(void) {
	scanf("%d %d", &k, &n);
	ll a;
	ary[0] = 0LL;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ary[i]);
		ary[i] += ary[i - 1];
	}
	while (k--) {
		scanf("%lld", &a);
		int left = 1, right = n, res = 2e9;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (a <= ary[mid]) {
				res = min(res, mid);
				right = mid - 1;
			}
			else left = mid + 1;
		}
		if (res == 2e9) puts("Go away!");
		else printf("%lld\n", res);
	}
	return 0;
}
