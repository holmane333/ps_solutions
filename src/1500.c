#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

typedef struct boom{
	char t;
	int cnt;
}boom;

int n;
boom map[201][201], submap[201][201];
int dx[] = { -1,1,0,0,0 }, dy[] = { 0,0,-1,1,0 };

int main() {
	long long int s, k;
	scanf("%lld %lld", &s, &k);

	long long int res = 1;
	long long int mlti = s / k;
	long long int cnt = s - mlti * k;
	for (int i = 0; i < k - cnt; i++) {
		res *= mlti;
	}
	for (int i = 0; i < cnt; i++) {
		res *= (mlti + 1);
	}

	printf("%lld\n", res);
	return 0;
}
