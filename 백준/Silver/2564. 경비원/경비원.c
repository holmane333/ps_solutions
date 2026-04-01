#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int main() {
	int w, h, n, sum = 0;
	scanf("%d %d %d", &w, &h, &n);
	int d, o, a[102];
	for (int i = 0; i <= n; i++) {
		scanf("%d %d", &d, &o);
		switch (d)
		{
		case 1: a[i] = o; break;
		case 2: a[i] = 2 * w + h - o; break;
		case 3: a[i] = 2 * (w + h) - o; break;
		case 4: a[i] = w + o; break;
		}
	}
	for (int i = 0; i < n; i++) {
		int tmp = abs(a[i] - a[n]);
		sum += (tmp < (w + h)) ? tmp : 2 * (w + h) - tmp;
	}
	printf("%d\n", sum);
}
