#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(void) {
	int tc, cnt, len;
	char s[60];
	scanf("%d", &tc);
	while (tc--) {
		cnt = 0;
		scanf("%s", s);
		len = strlen(s);
		for (int i = 0; i < len; ++i) {
			if (s[i] == '(') ++cnt;
			else {
				if (cnt == 0) {
					cnt = 1;
					break;
				}
				--cnt;
			}
		}
		if (cnt) printf("NO\n");
		else printf("YES\n");
	}
	
	return 0;
}
