#include <stdio.h>
#pragma warning(disable:4996)

int res[4];
int N, l, r;
int ary[5][5] = {{0, 0, 0, 0}, {0, 1, 3, 2}, {0, 2, 1, 1}, {0, 2, 3, 2}}, dp[10][30][10];

long long pow(int a, int b) {
	if (a == 1 || b == 0) return 1LL;
	if (b == 1) return (long long)a;
	return pow(a, b / 2) * pow(a, b / 2 + b % 2);
}

void loop(int num, int n, long long start, long long end, long long left, long long right) {
	//printf("%d %d %lld %lld %lld %lld\n", num, n, start, end, left, right);
	if (n < 0) return;
	if (start > right || end < left) return;
	if (left <= start && end <= right) {
		if (n >= 1) {
			res[1] += dp[num][n][1];
			res[2] += dp[num][n][2];
			res[3] += dp[num][n][3];
			//printf("%d %d %d %d\n", n, res[1], res[2], res[3]);
		}
		else {
			++res[num];
		}
		return;
	}
	long long len = (end - start + 1) / 3LL;
	loop(ary[num][1], n - 1, start, start + len - 1LL, left, right);
	loop(ary[num][2], n - 1, start + len, start + len * 2LL - 1LL, left, right);
	loop(ary[num][3], n - 1, start + len * 2LL, end, left, right);
}

void cal(){
    long long a = 1, b = 0, c = 0, da, db, dc;
	
    for (int n = 1; n <= 20; n++){
        da = a + 2 * b;
        db = a + b + 2 * c;
        dc = a + c;
        a = da; b = db; c = dc;
        dp[1][n][1] = a; dp[1][n][2] = b; dp[1][n][3] = c;
    }
    
    a = 0; b = 1; c = 0;
    for (int n = 1; n <= 20; n++){
        da = a + 2 * b;
        db = a + b + 2 * c;
        dc = a + c;
        a = da; b = db; c = dc;
        dp[2][n][1] = a; dp[2][n][2] = b; dp[2][n][3] = c;
    }
    
    a = 0; b = 0; c = 1;
    for (int n = 1; n <= 20; n++){
        da = a + 2 * b;
        db = a + b + 2 * c;
        dc = a + c;
        a = da; b = db; c = dc;
        dp[3][n][1] = a; dp[3][n][2] = b; dp[3][n][3] = c;
    }
}


int main(void) {
	int num;
	scanf("%d %d %d %d", &num, &l, &r, &N);
	cal();
	//printf("%lld\n", pow(3, N));
/*	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 20; ++j) {
			for (int k = 1; k <= 3; ++k) printf("%d ", dp[i][j][k]);
			puts("");
		}
		puts("");
	}
	puts("");*/
	loop(num, N, 0, pow(3, N) - 1LL, l, r);
	printf("%d %d %d\n", res[1], res[2], res[3]);
	
	return 0;
}
