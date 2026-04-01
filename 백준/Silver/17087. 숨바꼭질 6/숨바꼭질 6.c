#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int n, s;
	int ary[100001];
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
		ary[i] -= s;
		if (ary[i] < 0) ary[i] *= -1;
	}

	int res = ary[0];
	for (int i = 1; i < n; i++) {
		res = gcd(res, ary[i]);
	}
	printf("%d\n", res);
	
	return 0;
}
