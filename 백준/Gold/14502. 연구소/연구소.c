#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct element {
	int i;
	int j;
}element;

int n, m, ary[8][8], data[65][2], idx = 0, tempary[8][8], ans = 0;
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };

void map_cpy(int a[][8], int b[][8]) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			a[i][j] = b[i][j];
}

void virus() {
	int spreadary[8][8];
	map_cpy(spreadary, tempary);
	element stack[10000];
	int top = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spreadary[i][j] == 2) {
				element new1 = { i,j };
				stack[++top] = new1;
			}
		}
	}
	while (top != -1) {
		int x = stack[top].i, y = stack[top--].j;
		for (int i = 0; i < 4; i++) {
			int di = x + dx[i];
			int dj = y + dy[i];
			if (di >= 0 && di < n && dj >= 0 && dj < m) {
				if (spreadary[di][dj] == 0) {
					spreadary[di][dj] = 2;
					element new1 = { di,dj };
					stack[++top] = new1;
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spreadary[i][j] == 0) res++;
		}
	}
	ans = ans > res ? ans : res;
}

void BFS(int cnt) {
	if (cnt == 3) {
		virus();
		return;
	}

	for (int i = 0; i < idx; i++) {
		if (!tempary[data[i][0]][data[i][1]]) {
			tempary[data[i][0]][data[i][1]] = 1;
			BFS(cnt+1);
			tempary[data[i][0]][data[i][1]] = 0;
		}
	}
	
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &ary[i][j]);
			if (ary[i][j] == 0) {
				data[idx][0] = i;
				data[idx++][1] = j;
			}
		}
	
	for (int i = 0; i < idx; i++) {
		map_cpy(tempary, ary);
		tempary[data[i][0]][data[i][1]] = 1;
		BFS(1);
		tempary[data[i][0]][data[i][1]] = 0;
	}
	
	printf("%d\n", ans);

	return 0;
}