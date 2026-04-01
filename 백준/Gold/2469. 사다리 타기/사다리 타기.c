#include <stdio.h>
#pragma warning(disable:4996)
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int main() {
	int k, n;
	char s[30], e[30], temp;
	char ladder[1010][30];
	scanf("%d %d", &k, &n);
	scanf("%s", e);
	for (int i = 0; i < k; ++i) s[i] = (char)('A' + i);
	s[k] = '\0';
	for (int i = 0; i < n; ++i) scanf("%s", ladder[i]);
	for (int i = 0; i < n; ++i) {
		if (ladder[i][0] == '?') break;
		for (int j = 0; j < k - 1; ++j) {
			if (ladder[i][j] == '-') {
				swap(s[j], s[j + 1], temp);
			}
		}
	}
	
	for (int i = n - 1; i >= 0; --i) {
		if (ladder[i][0] == '?') break;
		for (int j = 0; j < k - 1; ++j) {
			if (ladder[i][j] == '-') {
				swap(e[j], e[j + 1], temp);
			}
		}
	}
	
	char res[30];
	//printf("%s\n%s\n\n", s, e);
	
	for (int i = 0; i < k; ++i) {
		if (s[i] == e[i]) res[i] = '*';
		else {
			if (i != k - 1 && s[i] == e[i + 1] && s[i + 1] == e[i]) {
				swap(e[i], e[i + 1], temp);
				res[i] = '-';
				res[i + 1] = '*';
				++i;
			}
			else {
				for (int j = 0; j < k - 1; ++j) {
					res[j] = 'x';
				}
				break;
			}
		}
	}
	res[k - 1] = '\0';
	printf("%s\n", res);
	return 0;
}