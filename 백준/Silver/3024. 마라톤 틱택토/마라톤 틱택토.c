#include <stdio.h>
#pragma warning(disable:4996)

int n;
char map[40][40];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", map[i] + 1);
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (map[i][j] != '.') {
				if ((map[i][j] == map[i][j + 1] && map[i][j] == map[i][j + 2]) || (map[i][j] == map[i + 1][j + 1] && map[i][j] == map[i + 2][j + 2]) || (map[i][j] == map[i + 1][j] && map[i][j] == map[i + 2][j]) || (map[i][j] == map[i + 1][j - 1] && map[i][j] == map[i + 2][j - 2])) {
					printf("%c\n", map[i][j]);
					return 0;
				}
			}
		}
	}
	
	printf("ongoing\n");
	return 0;
}
