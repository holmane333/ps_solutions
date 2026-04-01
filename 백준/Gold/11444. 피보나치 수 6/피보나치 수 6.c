#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define ll long long
#define mod 1000000007

int n = 2;
ll ary[2][2];
ll k;

void multp(ll b, ll mat1[2][2], ll res[2][2]) {
	
	if (b == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat1[i][j] = ary[i][j] % mod;
			}
		}
	}
	else if (b % 2 == 0) {
		multp(b / 2, mat1, res);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					mat1[i][j] += res[i][k] * res[k][j];
				}
				mat1[i][j] %= mod;
			}
		}
	}
	else {
		multp(b - 1, mat1, res);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					mat1[i][j] += res[i][k] * ary[k][j];
				}
				mat1[i][j] %= mod;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = mat1[i][j];
			mat1[i][j] = 0;
		}
	}
	if (b == k) {
		printf("%lld\n", res[0][1]);
	}
	return;
}

int main() {
	ll mat1[2][2] = { 0LL, }, res[2][2] = { 0LL, };
	scanf("%lld", &k);
	
	ary[0][0] = 1LL;
	ary[0][1] = 1LL;
	ary[1][0] = 1LL;
	ary[1][1] = 0LL;
	
	multp(k, mat1, res);

	return 0;
}
