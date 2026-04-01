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
	int n, m, cnt = 1;
	scanf("%d %d", &n, &m);
	while (1) {
		if (n == m) {
			printf("%d\n", cnt);
			break;
		}
		if (n > m) {
			printf("-1\n");
			break;
		}
		if (!(m % 2)) m /= 2;
		else if (m % 10 == 1) m /= 10;
		else {
			printf("-1\n");
			break;
		}
		cnt++;
	}

	return 0;
}
