#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int main() {
	int n, w, d;
	int data[1001];
	scanf("%d %d %d", &n, &w, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	int queue[101], idx = 0, clk = 1, m = 0;
	memset(queue, 0, sizeof(queue));
	queue[0] = data[idx++];
	m += queue[0];
	while (m != 0 || idx!=n) {
		if (idx != n && queue[0] == 0) {
			if (m + data[idx] <= d) {
				queue[0] = data[idx++];
				m += queue[0];
			}
		}
		m -= queue[w - 1];
		for (int i = w - 1; i >= 1; i--) {
			queue[i] = queue[i - 1];
		}
		queue[0] = 0;
		clk++;
	}

	printf("%d\n", clk);
	return 0;
}
