#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int n;
long long int k, ary[10001];

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
		t += ary[i] / h;
	}
	//printf("%lld %lld %lld\n", h, k, t);
	if (t >= k) return 1;
	return 0;
}

int main(void) {
	scanf("%d %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ary[i]);
	}
	qsort(ary, n, sizeof(long long int), compare);
	
	long long int left = 1, right = ary[n - 1], res = 0;
	while (left <= right) {
		long long int mid = (left + right) / 2;
		if (check(mid)) {
			res = max(res, mid);
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%lld\n", res);
	return 0;
}
