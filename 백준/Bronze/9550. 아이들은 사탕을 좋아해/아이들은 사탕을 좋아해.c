#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int n, k, data, res = 0;
		scanf("%d %d", &n, &k);
		for (int j = 0; j < n; j++) {
			scanf("%d", &data);
			res += data / k;
		}
		printf("%d\n", res);
	}
	return 0;
}