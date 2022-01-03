#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, r, c;
long long int max = 0;

void DP(int nn) {
	if (nn == 0) return;


	
}

int main() {
	scanf("%d %d %d", &n, &r, &c);
	long long int y = (1 << n) / 2;
	long long int x = y;

	while (n-- > 0) {
		long long int temp = (1LL << n) / 2;
		long long int skip = (1LL << (n * 2));

		if (r < y && c < x) {	// 1
			x -= temp;
			y -= temp;
		}
		else if (r < y && x <= c) {		// 2
			x += temp;
			y -= temp;
			max += skip;
		}
		else if (y <= r && c < x) {		// 3
			x -= temp;
			y += temp;
			max += skip * 2;
		}
		else {		// 4
			x += temp;
			y += temp;
			max += skip * 3;
		}
	}
	printf("%lld\n", max);
	return 0;
}
