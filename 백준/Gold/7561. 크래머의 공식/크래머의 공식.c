#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long

ll A[4][4], B[4][2], A1[4][4], A2[4][4], A3[4][4];

ll det(ll a[4][4]) {
	return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	for (int t = 0; t < tc; ++t) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				scanf("%lld", &A[i][j]);
				A1[i][j] = A[i][j];
				A2[i][j] = A[i][j];
				A3[i][j] = A[i][j];
			}
			scanf("%lld", &B[i][0]);
		}
		A1[0][0] = B[0][0];
		A1[1][0] = B[1][0];
		A1[2][0] = B[2][0];
		A2[0][1] = B[0][0];
		A2[1][1] = B[1][0];
		A2[2][1] = B[2][0];
		A3[0][2] = B[0][0];
		A3[1][2] = B[1][0];
		A3[2][2] = B[2][0];
		
		ll res1, res2, res3, res;
		res1 = det(A1);
		res2 = det(A2);
		res3 = det(A3);
		res = det(A);
		
		printf("%lld %lld %lld %lld\n", res1, res2, res3, res);
		
		if (!res) {
			printf("No unique solution\n");
		}
		else {
			double c1, c2, c3;
			c1 = (double)res1 / (double)res;
			if (c1 > -0.0005 && c1 < 0.0005) c1 = 0.0;
			c2 = (double)res2 / (double)res;
			if (c2 > -0.0005 && c2 < 0.0005) c2 = 0.0;
			c3 = (double)res3 / (double)res;
			if (c3 > -0.0005 && c3 < 0.0005) c3 = 0.0;
			printf("Unique solution: %.3lf %.3lf %.3lf\n", c1, c2, c3);
		}
		if (t != tc) puts("");
	}
	
	return 0;
}
