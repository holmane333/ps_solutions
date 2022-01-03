#include <stdio.h>
#include <limits.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int main(void) {
	int n, k, ary[110], pl[110] = {0, };
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; ++i) 
		scanf("%d", &ary[i]);
	int res = 0;
	for (int i = 1; i <= k; ++i) {
		int c = 0;
		for (int j = 1; j <= n; ++j) {
			if (!pl[j] || pl[j] == ary[i]) {
				c = 1;
				if (!pl[j]) pl[j] = ary[i];
				break;
			}
		}
		if (c) 
			continue;
		++res;
		int idx = 0, cnt = 0;
		for (int j = 1; j <= n; ++j) {
			int l = i;
			while (++l && l <= k) {
				if (pl[j] == ary[l]) break;
			}
			if (cnt < l) {
				idx = j;
				cnt = l;
			}
		}
		pl[idx] = ary[i];
	}
	printf("%d\n", res);
	
	return 0;
}
