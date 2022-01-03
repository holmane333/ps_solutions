#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int prime[10001];
int check[10001];

int to_int(char n[]) {
	int t = 0;
	for (int i = 0; i < 4; i++) {
		t = t * 10 + (int)(n[i] - '0');
	}
	return t;
}

void bfs(int s, int f) {
	int queue[30000], ft = 0, nr = 0;
	queue[ft++] = s;
	check[s] = 0;

	while (ft != nr) {
		int curr = queue[nr++];
		nr %= 30000;
		if (curr == f) break;
		for (int i = 0; i < 4; i++) {
			char str[5];
			sprintf(str, "%d", curr);
			for (int j = 0; j < 10; j++) {
				str[i] = (char)(j + (int)'0');
				int k = to_int(str);
				if (k >= 1000 && prime[k] && check[k] == -1) {
					check[k] = check[curr] + 1;
					queue[ft++] = k;
					ft %= 30000;
				}
			}
		}
	}
}

int main() {
	for (int i = 2; i < 10001; i++) {
		prime[i] = 1;
	}
	for (int i = 2; i * i < 10001; i++) {
		if (prime[i] == 1) {
			for (int j = i * i; j < 10001; j += i) {
				prime[j] = 0;
			}
		}
	}
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int s, f;
		scanf("%d %d", &s, &f);
		memset(check, -1, sizeof(check));
		bfs(s, f);
		if (check[f] != -1) printf("%d\n", check[f]);
		else printf("Impossible\n");
	}

	return 0;
}