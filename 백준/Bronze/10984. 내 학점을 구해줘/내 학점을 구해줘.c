#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main()
{
	int testcase, n1, a, n2;
	double total, b;
	scanf("%d", &testcase);
	for (int tc = 0; tc < testcase; tc++) {
		n2 = 0; total = 0.0;
		scanf("%d", &n1);
		for (int i = 0; i < n1; i++) {
			scanf("%d %lf", &a, &b);
			total += (double)a * b;
			n2 += a;
		}
		printf("%d %.1lf\n", n2, total / (int)n2);
	}
	return 0;
}