#include <stdio.h>
#include <string.h>

int main(void) {
	char res[110], s[110], a[110];
	int idx = 0, ft = 0;
	scanf("%s", a);
	int len = strlen(a);
	for (int i = 0; i < len; ++i) {
		if ((int)a[i] >= 65 && (int)a[i] <= 90) res[idx++] = a[i];
		else if (a[i] == '(') {
			s[ft++] = '(';
		}
		else if (a[i] == ')') {
			while (ft > 0 && s[ft - 1] != '(') {
				res[idx++] = s[--ft];
			}
			if (ft > 0) --ft;
		}
		else if (a[i] == '*' || a[i] == '/') {
			while (ft > 0 && (s[ft - 1] == '*' || s[ft - 1] == '/')) {
				res[idx++] = s[--ft];
			}
			s[ft++] = a[i];
		}
		else if (a[i] == '+' || a[i] == '-') {
			while (ft > 0 && s[ft - 1] != '(') {
				res[idx++] = s[--ft];
			}
			s[ft++] = a[i];
		}
	}
	while (ft > 0) res[idx++] = s[--ft];
	res[idx] = '\0';
	printf("%s\n", res);
	return 0;
}
