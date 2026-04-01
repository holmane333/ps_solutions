#pragma warning(disable:4996)
#include <stdio.h>
#define ll long long

int main(void) {
	int n, c;
	char a[2010];
	scanf("%d", &n);
	scanf("%s", a);
	
	for (int i = 0; i < n - 1; ++i) {
		c = 0;
		for (int j = 0; j <= i; ++j) {
			if (a[j] != a[n - i - 1 + j]) ++c;
		}
		if (c == 1) {
			printf("YES\n");
			return 0;
		}
	}
	
	printf("NO\n");
	return 0;
}
