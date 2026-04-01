#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long

int parent[100010], s[100010];

int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

void unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	if (a != b) {
		parent[b] = a;
		s[a] += s[b];
	}
}

ll q1(ll cnt) {
	return cnt * (cnt - 1) / 2; // nC2
}

ll q2(ll cnt) {
	return (cnt + 1) * cnt * (cnt - 1) / 6; // Sum of i * (i + 1) / 2, 1 to n
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= 100000; ++i) parent[i] = i, s[i] = 1;
	ll res1 = 0, res2 = 0, cnt = 0;
	for (int i = 0; i < n - 1; ++i) {
		int idx;
		scanf("%d", &idx);
		int a = getParent(idx), b = getParent(idx + 1);
		
		if (a != b) {
			res1 -= q1(s[a]) + q1(s[b]);
			res2 -= q2(s[a]) + q2(s[b]);
			unionFind(a, b);
			a = getParent(a);
			res1 += q1(s[a]);
			res2 += q2(s[a]);
		}
		
		printf("%lld %lld\n", res1, res2);
	}
	
	return 0;
}
