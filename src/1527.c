#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

long long int dd[2] = { 4LL,7LL }, cnt = 0;
long long a, b;
void dfs(long long int n) {
	if (n > b) return;
	if (n >= a) cnt++;
	for (int i = 0; i < 2; i++) {
		dfs(n * 10 + dd[i]);
	}
}

int main() {
	scanf("%lld %lld", &a, &b);

	dfs(0);
	printf("%lld\n", cnt);
	return 0;
}
