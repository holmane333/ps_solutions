#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, m;
int map[20][20], check[20][20][110], cnt, c[20][20], num[20][20], q[10010][3], ft, rr;
int dx[9] = {2, 2, 1, 1, -1, -1, -2, -2}, dy[9] = {1, -1, 2, -2, 2, -2, 1, -1};

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		char a[20];
		scanf("%s", a + 1);
		for (int j = 1; j <= m; ++j) {
			if (a[j] != '.') {
				map[i][j] = (int)(a[j] - '0');
				check[i][j][cnt] = 1;
				++c[i][j];
				++cnt;
			}
		}
	}
	
	int idx = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (map[i][j]) {
				ft = 0;
				rr = 0;
				q[ft][0] = i;
				q[ft][1] = j;
				q[ft++][2] = 1;
				while (ft != rr) {
					int x = q[rr][0];
					int y = q[rr][1];
					int t = q[rr++][2];
					if (rr >= 10000) rr = 0;

					for (int k = 0; k < 8; ++k) {
						int cx = x + dx[k];
						int cy = y + dy[k];
						if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
						if (!check[cx][cy][idx]) {
							check[cx][cy][idx] = 1;
							++c[cx][cy];
							num[cx][cy] += t / map[i][j] + (t % map[i][j] ? 1 : 0);
							q[ft][0] = cx;
							q[ft][1] = cy;
							q[ft++][2] = t + 1;
							if (ft >= 10000) ft = 0;
						}
					}
				}
				
				++idx;
			}
		}
	}
	
	int res = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (c[i][j] == cnt) {
				res = res == -1 ? num[i][j] : min(res, num[i][j]);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
