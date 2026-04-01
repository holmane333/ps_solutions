#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main()
{
	int testcase, h1, h2, m1, m2, a1, a2, p1, p2;
	scanf("%d", &testcase);
	for (int tc = 0; tc < testcase; tc++) {
		scanf("%d %d %d %d %d %d %d %d", &h1, &m1, &a1, &p1, &h2, &m2, &a2, &p2);
		h1 = h1 + h2 < 1 ? 1 : h1 + h2;
		m1 = m1 + m2 < 1 ? 1 : m1 + m2;
		a1 = a1 + a2 < 0 ? 0 : a1 + a2;
		p1 += p2;
		printf("%d\n", h1 + 5 * m1 + 2 * a1 + 2 * p1);
	}
	return 0;
}