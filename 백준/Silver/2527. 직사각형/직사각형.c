#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

typedef struct line {
	int s, e;
}line;

int inter(line a, line b) {
	if (a.s > b.s) {
		line tmp = a;
		a = b;
		b = tmp;
	}
	if (a.e < b.s) return 0;
	else if (a.e == b.s) return 1;
	else return 2;
}

int main() {
	line x1, y1;
	line x2, y2;
	for (int i = 0; i < 4; i++) {
		scanf("%d %d %d %d", &x1.s, &y1.s, &x1.e, &y1.e);
		scanf("%d %d %d %d", &x2.s, &y2.s, &x2.e, &y2.e);
		int ix = inter(x1, x2), iy = inter(y1, y2);
		if (ix == 2 && iy == 2) printf("a\n");
		else if (ix == 1 && iy == 2 || ix == 2 && iy == 1) printf("b\n");
		else if (ix == 1 && iy == 1) printf("c\n");
		else printf("d\n");
	}
}
