#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

int n;
long long ary[3030][5], cnt[3030], parent[3030];

long long ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	return x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2;
}

long long check(int i, int j) {
	long long ccw1 = ccw(ary[i][0], ary[i][1], ary[i][2], ary[i][3], ary[j][0], ary[j][1]) * ccw(ary[i][0], ary[i][1], ary[i][2], ary[i][3], ary[j][2], ary[j][3]);
	long long ccw2 = ccw(ary[j][0], ary[j][1], ary[j][2], ary[j][3], ary[i][0], ary[i][1]) * ccw(ary[j][0], ary[j][1], ary[j][2], ary[j][3], ary[i][2], ary[i][3]);
	
	if (ccw1 == 0 && ccw2 == 0) {
		if (ary[i][0] > ary[i][2] || (ary[i][0] == ary[i][2] && ary[i][1] > ary[i][3])) {
			long long temp1 = ary[i][0], temp2 = ary[i][1];
			ary[i][0] = ary[i][2];
			ary[i][1] = ary[i][3];
			ary[i][2] = temp1;
			ary[i][3] = temp2;
		}
		if (ary[j][0] > ary[j][2] || (ary[j][0] == ary[j][2] && ary[j][1] > ary[j][3])) {
			long long temp1 = ary[j][0], temp2 = ary[j][1];
			ary[j][0] = ary[j][2];
			ary[j][1] = ary[j][3];
			ary[j][2] = temp1;
			ary[j][3] = temp2;
		}
		return (ary[i][0] < ary[j][2] || (ary[i][0] == ary[j][2] && ary[i][1] <= ary[j][3])) && (ary[j][0] < ary[i][2] || (ary[j][0] == ary[i][2] && ary[j][1] <= ary[i][3]));
	}
	return ccw1 <= 0 && ccw2 <= 0;
}

long long getParent(long long a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void unionFind(long long a, long long b) {
	a = getParent(a);
	b = getParent(b);
	
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < 3010; ++i) parent[i] = i;
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld %lld %lld", &ary[i][0], &ary[i][1], &ary[i][2], &ary[i][3]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (check(i, j)) unionFind(i, j);
		}
	}
	
	long long Max = 0, res = 0;
	for (int i = 0; i < n; ++i) {
		if (i == getParent(i)) ++res;
		++cnt[getParent(i)];
		Max = max(Max, cnt[getParent(i)]);
	}
	printf("%lld\n%lld\n", res, Max);
	return 0;
}
