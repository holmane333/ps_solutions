#include <stdio.h>

int main(void) {
	int tc, n;
	scanf("%d", &tc);
	int ary[510];
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &ary[i]);
		if (n <= 4) {
			puts("YES");
			continue;
		}
		for (int i = n - 1; i >= 1; --i) {
			ary[i] -= ary[i - 1];
		}
		for (int i = n - 1; i >= 2; --i) {
			ary[i] -= ary[i - 1];
		}
		for (int i = n - 1; i >= 3; --i) {
			ary[i] -= ary[i - 1];
		}
		/*for (int i = 0; i < n; ++i) printf("%d ", ary[i]);
		puts("");*/
		int ch = 0;
		for (int i = 3; i < n - 1; ++i) {
			if (ary[i] != ary[i + 1]) {
				ch = 1;
				break;
			}
		}
		if (ch) {
			puts("NO");
		}
		else {
			puts("YES");
		}
	}
	
	
	
	return 0;
}
