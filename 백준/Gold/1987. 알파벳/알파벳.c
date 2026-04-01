#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

char pos[22][22];
int flag[27];
int count = 1;
int c = 0;
int n, m;
int max = 0;

void set(int i,int j) {
	c = 0;
	int t;
	if (j + 1 <= m && flag[t = ((int)(pos[i][j + 1]) - 64)] == 0) {
		c = 1;
		count++;
		flag[t] = 1;
		set(i, j + 1);
		flag[t] = 0;
		count--;
	}
	if (i + 1 <= n && flag[t = ((int)(pos[i + 1][j]) - 64)] == 0) {
		c = 1;
		count++;
		flag[t] = 1;
		set(i + 1, j);
		flag[t] = 0;
		count--;
	}
	if (j - 1 >= 1 && flag[t = ((int)(pos[i][j - 1]) - 64)] == 0) {
		c = 1;
		count++;
		flag[t] = 1;
		set(i, j - 1);
		flag[t] = 0;
		count--;
	}
	if (i - 1 >= 1 && flag[t = ((int)(pos[i - 1][j]) - 64)] == 0) {
		c = 1;
		count++;
		flag[t] = 1;
		set(i - 1, j);
		flag[t] = 0;
		count--;
	}
	if (c == 0) {
		max = max > count ? max : count;
	}
}

int main() {
	char str[21];
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &str);
		for (int j = 1; j <= m; j++) {
			pos[i][j] = str[j - 1];
		}
	}
	flag[(int)pos[1][1] - 64] = 1;
	set(1, 1);
	printf("%d", max);
	return 0;
}