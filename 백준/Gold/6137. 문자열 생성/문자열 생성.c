#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int n, l, r, idx = 0;
	char str[2010];
	scanf("%d", &n);
	l = 0;
	r = n - 1;
	char c[3];
	for (int i = 0; i < n; ++i) {
		scanf("%s", c);
		str[i] = c[0];
	}
	
	while (l <= r) {
		if ((int)str[l] < (int)str[r]) printf("%c", str[l++]);
		else if ((int)str[l] > (int)str[r]) printf("%c", str[r--]);
		else {
			int ll = l + 1, rr = r - 1, check = 0;
			while (ll <= rr) {
				if ((int)str[ll] < (int)str[rr]) {
					printf("%c", str[l++]);
					check = 1;
					break;
				}
				if ((int)str[ll] > (int)str[rr]) {
					printf("%c", str[r--]);
					check = 1;
					break;
				}
				else {
					ll += 1;
					rr -= 1;
				}
			}
			if (!check) printf("%c", str[l++]);
		}
		++idx;
		if (!(idx % 80)) printf("\n");
	}
	if (idx % 80) printf("\n");
	return 0;
}
