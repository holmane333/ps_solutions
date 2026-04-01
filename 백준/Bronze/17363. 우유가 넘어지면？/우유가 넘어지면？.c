#include <stdio.h>

char ary[401][401];
char res[401][401];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; ++i) {
		scanf("%s", ary[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ary[i][j] == '-')
				res[m - j - 1][i] = '|';
			else if (ary[i][j] == '|')
				res[m - j - 1][i] = '-';
			else if (ary[i][j] == '/')
				res[m - j - 1][i] = '\\';
			else if (ary[i][j] == '\\')
				res[m - j - 1][i] = '/';
			else if (ary[i][j] == '^')
				res[m - j - 1][i] = '<';
			else if (ary[i][j] == '<')
				res[m - j - 1][i] = 'v';
			else if (ary[i][j] == 'v')
				res[m - j - 1][i] = '>';
			else if (ary[i][j] == '>')
				res[m - j - 1][i] = '^';
			else
				res[m - j - 1][i] = ary[i][j];
		}
	}
	for (int i = 0; i < m; ++i) printf("%s\n", res[i]);
	return 0;
}
