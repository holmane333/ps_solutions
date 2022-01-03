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

	int v, e, s, distance1[3000], distance2[3000], y, x, data, ary1[1001][1001] = { 0, }, ary2[1001][1001] = { 0, }, check1[2001] = { 0, }, check2[2001] = { 0, };
	scanf("%d %d\n%d", &v, &e, &s);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &y, &x, &data);
		if (ary1[y][x] > data || !ary1[y][x]) ary1[y][x] = data;
		if (ary2[x][y] > data || !ary2[x][y]) ary2[x][y] = data;
	}
	for (int i = 1; i <= v; i++) {
		distance1[i] = ary1[s][i];
		if (!distance1[i]) distance1[i] = INT_MAX;
	}
	distance1[s] = 0;
	check1[s] = 1;
	for (int i = 0; i < v - 1; i++) {
		int c = choose(distance1, v, check1);
		if (c == -1) break;
		check1[c] = 1;
		for (int w = 1; w <= v; w++) {
			if (distance1[c] != INT_MAX && ary1[c][w] && !check1[w])
				if (distance1[c] + ary1[c][w] < distance1[w]) distance1[w] = distance1[c] + ary1[c][w];
		}
	}


	for (int i = 1; i <= v; i++) {
		distance2[i] = ary2[s][i];
		if (!distance2[i]) distance2[i] = INT_MAX;
	}
	distance2[s] = 0;
	check2[s] = 1;
	for (int i = 1; i < v - 1; i++) {
		int c = choose(distance2, v, check2);
		if (c == -1) break;
		check2[c] = 1;
		for (int w = 1; w <= v; w++) {
			if (distance2[c] != INT_MAX && ary2[c][w] && !check2[w])
				if (distance2[c] + ary2[c][w] < distance2[w]) distance2[w] = distance2[c] + ary2[c][w];
		}
	}
	
	int max = INT_MIN;
	for (int i = 1; i <= v; i++) 
		if (distance1[i] != INT_MAX && distance2[i] != INT_MAX) max = max > distance1[i] + distance2[i] ? max : distance1[i] + distance2[i];

	
	printf("%d\n", max);
	
	
	
	return 0;
}