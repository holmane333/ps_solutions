#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define MAX_TERMS 1001
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

char str[1000001], str2[1000001], pat[1000001];
int data[1000001], cnt, rest[200000], lth1, lth2;

void failure() {
	int j = 0;
	for (int i = 0; i < lth1; i++) {
		while (j > 0 && str[i] != pat[j]) j = data[j - 1];
		if (str[i] == pat[j]) {
			if (j == lth2 - 1) {
				++cnt;
				j = data[j];
			}
			else j++;
		}
	}
}

int main() {
	scanf("%s", str2);
	scanf("%s", pat);

	lth1 = strlen(str2);
	lth2 = strlen(pat);

	int idx = 0;
	for (int i = 0; i < lth1; ++i) {
		if (((int)str2[i] >= 'a' && (int)str2[i] <= 'z') || ((int)str2[i] >= 'A' && (int)str2[i] <= 'Z')) str[idx++] = str2[i];
	}
	str[idx++] = '\0';
	lth1 = strlen(str);
	
	int j = 0;
	for (int i = 1; i < lth2; i++) {
		while (j > 0 && pat[i] != pat[j]) j = data[j - 1];
		if (pat[i] == pat[j]) data[i] = ++j;
	}
	failure();
	printf("%d\n", cnt > 0 ? 1 : 0);
	
	return 0;
}
