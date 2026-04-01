#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

char str[21];
int len;
char map[2][101];
int res[2][101][21];
int n;

int main(void) {
	scanf("%s", str);
	len = strlen(str);
	scanf("%s", map[0]);
	scanf("%s", map[1]);
	n = strlen(map[0]);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < len; k++) {
				if (i == 0) break;
				res[j][i][k] = res[j][i - 1][k];
			}
			for (int k = 0; k < len; k++) {
				if (map[j][i] == str[k]) {
					if (k == 0) res[j][i][k] += 1;
					else if (i == 0) continue;
					else res[j][i][k] += res[!j][i - 1][k - 1];
				}
			}
		}
	}
	
	printf("%d\n", res[0][n - 1][len - 1] + res[1][n - 1][len - 1]);
	
	
	
	
	return 0;
}
