#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, m, k, map[501][501];

int compare(const void *a, const void *b) {
    int num1 = *(long long int *)a;    
    int num2 = *(long long int *)b;
    if (num1 < num2)    
        return -1;      
    if (num1 > num2)    
        return 1;
    return 0;
}

int main(void) {
	scanf("%d %d %d", &n, &m, &k);
	int Max = INT_MIN, Min = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			Max = max(Max, map[i][j]);
			Min = min(Min, map[i][j]);
		}
	}
	
	int t = INT_MAX, res = INT_MIN;
	for (int h = Min; h <= Max; h++) {
		int now_t = 0, now_res = h, block = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > h) {
					now_t += (map[i][j] - h) * 2;
					block += (map[i][j] - h);
				}
				else if (map[i][j] < h) {
					now_t += (h - map[i][j]);
					block -= (h - map[i][j]);
				}
			}
		}
		if (block + k >= 0 && now_t <= t) {
			t = now_t;
			res = now_res;
		}
	}
	
	printf("%d %d\n", t, res);
	
	return 0;
}
