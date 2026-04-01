#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

// (: -1, ): -2, [: -3, ]: -4

int main() {
	char data[50];
	int res[50], n, ft = 0, c = 0, ans = 0;
	scanf("%s", data);
	n = strlen(data);
	for (int i = 0; i < n; i++) {
		if (c == 1) break;
		if (data[i] == '(') {
			res[ft++] = -1;
		}
		else if (data[i] == '[') {
			res[ft++] = -3;
		}
		else if (data[i] == ')') {
			if (ft == 0) {
				c = 1;
				break;
			}
			int t = 0, j;
			for (j = ft - 1; j >= 0; j--) {
				if (res[j] == -1) break;
				else if (res[j] < -1) {
					c = 1;
					break;
				}
				else t += res[j];
			}
			res[j] = t * 2;
			if (t == 0) res[j] = 2;
			ft = j + 1;
			if (ft == 1) {
				ans += res[j];
				ft = 0;
			}
		}
		else {
			if (ft == 0) {
				c = 1;
				break;
			}
			int t = 0, j;
			for (j = ft - 1; j >= 0; j--) {
				if (res[j] == -3) break;
				else if (res[j] <= -1) {
					c = 1;
					break;
				}
				else t += res[j];
			}
			res[j] = t * 3;
			if (t == 0) res[j] = 3;
			ft = j + 1;
			if (ft == 1) {
				ans += res[j];
				ft = 0;
			}
		}
	}
	if (c == 1) printf("%d\n", 0);
	else {
		printf("%d\n", ans);
	}
	return 0;
}