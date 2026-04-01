#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define ll long long

int main(){
	int n, m, a[10][10];
	ll res = -1;
	scanf("%d %d", &n, &m);
	char s[12][12], c[12];
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		//printf("%s\n", s[i] + 1);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 0; k <= n; ++k) {
				for (int l = 0; l <= m; ++l) {
					if (k == 0 && l == 0) continue;
					int d = i, e = j, idx = 0;
					memset(c, 0, sizeof(c));
					while (d <= n && e <= m) {
						c[idx++] = s[d][e];
						d += k;
						e += l;
						//printf("%c ", c[idx - 1]);
					
					//puts("");
					c[idx] = '\0';
					ll sum = atoi(c);
					//printf("%s %lld\n", c, sum);
					ll sq = (ll)sqrt(sum);
					//if (sum > 0) printf("%lld\n", sum);
					if (sq * sq == sum)
						res = max(res, sum);
					}
				}
			}
			for (int k = -n; k <= 0; ++k) {
				for (int l = -m; l <= 0; ++l) {
					if (k == 0 && l == 0) continue;
					int d = i, e = j, idx = 0;
					memset(c, 0, sizeof(c));
					while (d >= 1 && e >= 1) {
						c[idx++] = s[d][e];
						d += k;
						e += l;
						//printf("%c ", c[idx - 1]);
					
					//puts("");
					c[idx] = '\0';
					ll sum = atoi(c);
					//printf("%s %lld\n", c, sum);
					ll sq = (ll)sqrt(sum);
					//if (sum > 0) printf("%lld\n", sum);
					if (sq * sq == sum) {
						//if (res < sum) printf("%lld %lld\n", res, max);
						res = max(res, sum);
					}
					}
				}
				
			}
			for (int k = -n; k <= 0; ++k) {
				for (int l = 0; l <= m; ++l) {
					if (k == 0 && l == 0) continue;
					int d = i, e = j, idx = 0;
					memset(c, 0, sizeof(c));
					while (d >= 1 && e <= m) {
						c[idx++] = s[d][e];
						d += k;
						e += l;
						//printf("%c ", c[idx - 1]);
					
					//puts("");
					c[idx] = '\0';
					ll sum = atoi(c);
					//printf("%s %lld\n", c, sum);
					ll sq = (ll)sqrt(sum);
					//if (sum > 0) printf("%lld\n", sum);
					if (sq * sq == sum) {
						//if (res < sum) printf("%lld %lld\n", res, max);
						res = max(res, sum);
					}
					}
				}
				
			}
			for (int k = 0; k <= n; ++k) {
				for (int l = -m; l <= 0; ++l) {
					if (k == 0 && l == 0) continue;
					int d = i, e = j, idx = 0;
					memset(c, 0, sizeof(c));
					while (d <= n && e >= 1) {
						c[idx++] = s[d][e];
						d += k;
						e += l;
						//printf("%c ", c[idx - 1]);
					
					//puts("");
					c[idx] = '\0';
					ll sum = atoi(c);
					//printf("%s %lld\n", c, sum);
					ll sq = (ll)sqrt(sum);
					//if (sum > 0) printf("%lld\n", sum);
					if (sq * sq == sum) {
						//if (res < sum) printf("%lld %lld\n", res, max);
						res = max(res, sum);
					}
					}
				}
				
			}
		}
	}
	
	printf("%lld\n", res);
	
	return 0;
}
