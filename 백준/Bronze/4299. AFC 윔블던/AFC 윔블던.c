#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int main(){
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	if (a < b || ((a + b) & 1) || ((a - b) & 1)) {
		printf("-1\n");
		return 0;
	}
	c = (a + b) / 2;
	d = (a - b) / 2;
	if 	(c < 0 || d < 0) printf("-1\n");
	printf("%d %d", c, d);
	return 0;
}