#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n, result, qft = 0, qbk = 0, qsize = 1;
int dx[3] = { -1,1,0 };
int check[100001], v[100001];
int queue[1000001];

void bfs() {
	int x;
	while (qsize) {
		x = queue[qft++];
		dx[2] = x;
		qft %= 1000001;
		for (int i = 0; i < 3; i++) {
			int newx = x + dx[i];
			if (0 <= newx && newx < 100001 && !check[newx] && v[newx] == -1) {
				check[newx] = check[x] + 1;
				queue[qbk++] = newx;
				v[newx] = x;
				qbk %= 1000001;
				if (newx == result) return;
			}
		}
		qsize = abs(qbk - qft);

	}
}

void print_path(int x) {
	if (v[x] != x) print_path(v[x]);
	printf("%d ", x);
}

int main() {
	scanf("%d %d", &n, &result);
	queue[qbk++] = n;
	check[n] = 1;
	memset(v, -1, sizeof(v));
	v[n] = n;


	bfs();
	printf("%d\n", check[result] - 1);
	print_path(result);
	puts("");
	return 0;
}