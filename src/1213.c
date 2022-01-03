#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

// 'A': 65

int main() {
	char data[100];
	scanf("%s", data);
	int alpha[30] = { 0, }, n = strlen(data);
	for (int i = 0; i < n; i++) {
		alpha[(int)(data[i] - 65)]++;
	}
	int cnt_1 = 0;
	for (int i = 0; i < 27; i++) {
		if (alpha[i] % 2) cnt_1++;
	}
	if (cnt_1 > 1) printf("I'm Sorry Hansoo");
	else {
		int idx = -1;
		for (int i = 0; i < 27; i++) {
			if (alpha[i] % 2) {
				for (int j = 0; j < alpha[i] / 2; j++) printf("%c", (char)(i + 65));
				idx = i;
			}
			else
				for (int j = 0; j < alpha[i] / 2; j++) printf("%c", (char)(i + 65));
		}
		if (idx != -1) printf("%c", (char)(idx + 65));
		for (int i = 26; i >= 0; i--) {
			for (int j = 0; j < alpha[i] / 2; j++) printf("%c", (char)(i + 65));
		}
	}
	return 0;
}