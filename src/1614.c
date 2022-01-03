#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define MAX 10000000

int da[][2] = { {0,0},{8,8},{6,2},{4,4},{2,6},{8,8} };

int main() {
	long long int n, t, res = 0;
	scanf("%lld %lld", &n, &t);
	res += n - 1;
	int d = 0;
	for (int i = 0; i < t; i++) {
		res += da[n][d];
		d = !d;
	}
	printf("%lld\n", res);
	return 0;
}
