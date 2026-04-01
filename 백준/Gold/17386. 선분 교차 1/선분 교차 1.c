#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define ll long long

ll ary[2][5];

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll t = x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2;
    if (t == 0) return 0;
    else if (t > 0) return 1;
    else return -1;
}

int check(int i, int j) {
	int ccw1 = ccw(ary[i][0], ary[i][1], ary[i][2], ary[i][3], ary[j][0], ary[j][1]) * ccw(ary[i][0], ary[i][1], ary[i][2], ary[i][3], ary[j][2], ary[j][3]);
	int ccw2 = ccw(ary[j][0], ary[j][1], ary[j][2], ary[j][3], ary[i][0], ary[i][1]) * ccw(ary[j][0], ary[j][1], ary[j][2], ary[j][3], ary[i][2], ary[i][3]);
	
	if (ccw1 == 0 && ccw2 == 0) {
		if (ary[i][0] > ary[i][2] || (ary[i][0] == ary[i][2] && ary[i][1] > ary[i][3])) {
			ll temp1 = ary[i][0], temp2 = ary[i][1];
			ary[i][0] = ary[i][2];
			ary[i][1] = ary[i][3];
			ary[i][2] = temp1;
			ary[i][3] = temp2;
		}
		if (ary[j][0] > ary[j][2] || (ary[j][0] == ary[j][2] && ary[j][1] > ary[j][3])) {
			ll temp1 = ary[j][0], temp2 = ary[j][1];
			ary[j][0] = ary[j][2];
			ary[j][1] = ary[j][3];
			ary[j][2] = temp1;
			ary[j][3] = temp2;
		}
		return (ary[i][0] < ary[j][2] || (ary[i][0] == ary[j][2] && ary[i][1] <= ary[j][3])) && (ary[j][0] < ary[i][2] || (ary[j][0] == ary[i][2] && ary[j][1] <= ary[i][3]));
	}
	return ccw1 <= 0 && ccw2 <= 0;
}

int main(void) {
	scanf("%lld %lld %lld %lld", &ary[0][0], &ary[0][1], &ary[0][2], &ary[0][3]);
	scanf("%lld %lld %lld %lld", &ary[1][0], &ary[1][1], &ary[1][2], &ary[1][3]);
	
	printf("%d\n", check(0, 1));
	return 0;
}
