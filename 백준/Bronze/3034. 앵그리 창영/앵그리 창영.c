#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int n, w, h, len, k;
	scanf("%d %d %d", &n, &w, &h);
	len = (int)sqrt(w * w + h * h);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		printf("%s\n", len >= k ? "DA" : "NE");
	}
	return 0;
}