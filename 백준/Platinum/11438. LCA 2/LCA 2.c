#include <stdio.h>
#include <stdlib.h>
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int n, m;
int* ary[100010];
int d[100010], p[100010][20], len[100010];
int l = 18;

void maketree(int a, int b) {
	d[a] = d[b] + 1;
	p[a][0] = b;
	
	for (int i = 1; i <= l; ++i) 
		p[a][i] = p[p[a][i - 1]][i - 1];
	
	for (int i = 0; i < len[a]; ++i) 
		if (ary[a][i] != b) maketree(ary[a][i], a);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i <= 100000; ++i) ary[i] = (int*)malloc(sizeof(int));
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ary[a] = realloc(ary[a], sizeof(int) * (++len[a]));
		ary[b] = realloc(ary[b], sizeof(int) * (++len[b]));
		ary[a][len[a] - 1] = b;
		ary[b][len[b] - 1] = a;
	}
	
	maketree(1, 0);
	
	scanf("%d", &m);
	
	while (m--) {
		int a, b, t;
		scanf("%d %d", &a, &b);
		
		if (d[a] < d[b]) swap(a, b, t);
		int diff = d[a] - d[b];
		
		for (int i = 0; diff; ++i) {
			if (diff % 2) a = p[a][i];
			diff /= 2;
		}
		
		if (a != b) {
			for (int i = l; i >= 0; --i) {
				if (p[a][i] != p[b][i]) {
					a = p[a][i];
					b = p[b][i];
				}
			}
			a = p[a][0];
		}
		printf("%d\n", a);
	}
	
	return 0;
}
