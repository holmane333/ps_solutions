#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	long long int n;
	scanf("%lld", &n);
	int k = 0;
	if (!(n == 1)) {
		for (; n > 1;) {
			if (n % 2 == 0) n /= 2;
			else {
				k = 1;
				break;
			}
		}
	}
	if (k == 0) printf("1");
	else printf("0");

	return 0;
}
