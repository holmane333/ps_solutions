#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>

int main(void) {
	int tc, n, m;
	scanf("%d", &tc);
	int q[220][2], a[10] = {0, }, ft = 0, rr = 0, maxi = 0, res = 1;
	while (tc--) {
		memset(a, 0, sizeof(a));
		memset(q, 0, sizeof(q));
		ft = 0; rr = 0; maxi = 0; res = 1;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &q[i][0]);
			q[i][1] = 0;
			++a[q[i][0]];
		}
		rr = n;
		q[m][1] = 1;
		for (int i = 9; i >= 0; --i) {
			if (a[i]) {
				maxi = i;
				break;
			}
		}
		while (ft != rr) {
			if (q[ft][0] < maxi) {
				q[rr][0] = q[ft][0];
				q[rr++][1] = q[ft++][1];
				if (ft >= 200) ft = 0;
				if (rr >= 200) rr = 0;
			}
			else {
				if (q[ft][1]) {
					printf("%d\n", res);
					break;
				}
				++ft;
				++res;
				if (ft >= 200) ft = 0;
				--a[maxi];
				if (!a[maxi]) {
					for (int i = 9; i >= 0; --i) {
						if (a[i]) {
							maxi = i;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}
