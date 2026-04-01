#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)

int main() {
	int n;
	char body[1001][1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", body[i]);
	}
	int left_arm = 0, right_arm = 0, middle = 0, left_leg = 0, right_leg = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (body[i + 1][j] == '*' && body[i - 1][j] == '*' && body[i][j + 1] == '*' && body[i][j - 1] == '*') {
				printf("%d %d\n", i + 1, j + 1);
				for (int k = j + 1; k < n; k++) {
					if (body[i][k] != '*') break;
					right_arm++;
				}
				for (int k = j - 1; k >= 0; k--) {
					if (body[i][k] != '*') break;
					left_arm++;
				}
				for (int k = i + 1; k < n; k++) {
					if (body[k][j] != '*') break;
					middle++;
				}
				for (int k = i + middle + 1; k < n; k++) {
					if (body[k][j - 1] != '*') break;
					left_leg++;
				}
				for (int k = i + middle + 1; k < n; k++) {
					if (body[k][j + 1] != '*') break;
					right_leg++;
				}

			}
		}
	}
	printf("%d %d %d %d %d\n", left_arm, right_arm, middle, left_leg, right_leg);
	return 0;
}