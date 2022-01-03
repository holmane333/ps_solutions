#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int choose(int distance[], int v, int check[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 1; i <= v; i++) {
		if (distance[i] < min && !check[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

int main() {

	int v, e, s, f, distance[3000], y, x, data, ary[1001][1001] = { 0, }, check[2001] = { 0, };
	scanf("%d\n%d\n", &v, &e);
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			ary[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &y, &x, &data);
		if (ary[y][x] > data || ary[y][x] == INT_MAX) ary[y][x] = data;
	}
	scanf("%d %d", &s, &f);
	for (int i = 1; i <= v; i++) {
		distance[i] = ary[s][i];
	}
	distance[s] = 0;
	check[s] = 1;
	for (int i = 0; i < v - 1; i++) {
		int c = choose(distance, v, check);
		if (c == -1) break;
		check[c] = 1;
		for (int w = 1; w <= v; w++) {
			if (distance[c] != INT_MAX && ary[c][w] != INT_MAX && !check[w])
				if (distance[c] + ary[c][w] < distance[w]) distance[w] = distance[c] + ary[c][w];
		}
	}
	
	
	printf("%d\n", distance[f]);

	return 0;
}