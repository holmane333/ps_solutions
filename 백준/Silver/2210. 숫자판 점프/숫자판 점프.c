#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int mat[6][6], index[1000000];
int count = 0, k;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

int parse(int str[]) {
	return str[0] * 100000 + str[1] * 10000 + str[2] * 1000 + str[3] * 100 + str[4] * 10 + str[5];
}

void z(int x, int y, int str[], int t) {

	if (t == 6){
		if (index[k = parse(str)] == 0) {
			index[k] = 1;
			count++;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			int ddx = x + dx[i], ddy = y + dy[i];
			if (ddx < 1 || ddx > 5 || ddy < 1 || ddy > 5) continue;
			else {
				str[t++] = mat[ddx][ddy];
				z(ddx, ddy, str, t);
				t--;
			}
		}
	}
}

int main() {
	int x = 1, y = 1;
	for (int i = 1; i <= 5; i++) {
		scanf("%d %d %d %d %d", &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5]);
	}
	int str[6] = { 0, };
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			z(i, j, str, 0);
	
	printf("%d\n", count);

	
	return 0;
}