#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(void) {
	char str[32010];
	char s[32010];
	int idx;
	int nowb, transb;
	int n;
	for (int cnt = 1;; ++cnt) {
		scanf("%s", str);
		n = (int)strlen(str);
		if (n == 2) break;
		idx = 0;
		nowb = -1; // 1 : true, 0 : false
		transb = 1; // 1 : and, 0 : or
		s[idx++] = '(';
		int d = 0, maxd = -1e9;
		for (int i = 0; i < n; ++i) {
			if (str[i] == '(') ++d;
			else if (str[i] == ')') --d;
			maxd = maxd < d ? d : maxd;
		}
		if (maxd % 2) transb = 1;
		else transb = 0;
		for (int i = 1; i < n; ++i) {
			if (str[i] == ')') {
				nowb = -1;
				while (idx > 0 && s[idx - 1] != '(') {
					if (s[idx - 1] == 'T') {
						if (nowb == -1) nowb = 1;
						else {
							if (transb) nowb = nowb && 1;
							else nowb = nowb || 1;
						}
					}
					else {
						if (nowb == -1) nowb = 0;
						else {
							if (transb) nowb = nowb && 0;
							else nowb = nowb || 0;
						}
					}
					--idx;
				}
				--idx;
				if (nowb) s[idx++] = 'T';
				else s[idx++] = 'F';
				transb = !transb;
			}
			else {
				if (str[i] == '(') transb = !transb;
				s[idx++] = str[i];
			}
			/*printf("%c %d %d %d\n", str[i], nowb, transb, idx);
			for (int j = 0; j < idx; ++j) {
				printf("%c ", s[j]);
			}
			puts("");*/
		}
		printf("%d. ", cnt);
		if (s[0] == 'T') puts("true");
		else puts("false");
	}
	
	return 0;
}
