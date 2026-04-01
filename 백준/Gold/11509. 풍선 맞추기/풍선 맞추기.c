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
	int n, data, res[1000001], cnt = 0;
	scanf("%d", &n);
	memset(res, 0, sizeof(res));
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		if (!res[data + 1]) {
			res[data]++;
			cnt++;
		}
		else {
			res[data + 1]--;
			res[data]++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}
