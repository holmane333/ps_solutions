#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int x, y, w, h,result[4];
	scanf("%d %d %d %d", &x, &y, &w, &h);
	result[0] = x;
	result[1] = w - x;
	result[2] = y;
	result[3] = h - y;
	int max= result[0];
	for (int i = 1; i < 4; i++) {
		if (max > result[i]) max = result[i];
	}
	printf("%d", max);
}