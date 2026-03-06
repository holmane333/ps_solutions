#include <stdio.h>
#pragma warning (disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int main(void) {
	int n, ary[10010];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &ary[i]);
	int pos = -1, pos2 = -1;
	for (int i = n - 1; i >= 1; --i) {
		if (ary[i + 1] > ary[i]) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		printf("-1\n");
		return 0;
	}
	for (int i = n; i >= 1; --i) {
		if (ary[pos] < ary[i]) {
			pos2 = i;
			break;
		}
	}
	
	int temp;
	swap(ary[pos], ary[pos2], temp);
	
	++pos;
	pos2 = n;
	while (pos < pos2) {
		swap(ary[pos], ary[pos2], temp);
		++pos;
		--pos2;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ary[i]);
	}
	puts("");
	return 0;
}
