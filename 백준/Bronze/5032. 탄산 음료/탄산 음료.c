#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int n, m, l, cnt = 0;
	scanf("%d %d %d", &n, &m, &l);
	n += m;
	for (; n >= l;) {
		cnt += n / l;
		n = n / l + n % l;
	}
	printf("%d\n", cnt);
	return 0;
}