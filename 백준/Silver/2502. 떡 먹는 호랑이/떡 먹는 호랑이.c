#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int d, k;
	scanf("%d %d", &d, &k);
	int fibo[31];
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i <= d; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int a_fibo = fibo[d - 2];
	int b_fibo = fibo[d - 1];
	int a, b;
	for (int i = 1;; i++) {
		a = i;
		if ((k - a_fibo * a) % b_fibo) continue;
		b = (k - a_fibo * a) / b_fibo;
		break;
	}
	printf("%d\n%d\n", a, b);
	return 0;
}
