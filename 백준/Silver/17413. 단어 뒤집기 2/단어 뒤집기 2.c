#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	char str[100002], res[100002];
	gets(str);
	int n = strlen(str), idx = 0, stk = 0, nowidx = 0;
	for (int i = 0; i < n; i++) {
		if ((str[i] == ' ' && stk == 0) || str[i] == '<') {
			for (int j = i - 1; j >= idx; j--) {
				res[nowidx++] = str[j];
			}
			res[nowidx++] = str[i];
			idx = i + 1;
			if (str[i] == '<') stk = 1;
		}
		else if (i == n - 1 && stk == 0) {
			for (int j = i; j >= idx; j--) {
				res[nowidx++] = str[j];
			}
		}
		else {
			if (stk == 1) res[nowidx++] = str[i];
			if (str[i] == '>') {
				stk = 0;
				idx = i + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%c", res[i]);
	}
	return 0;
}
