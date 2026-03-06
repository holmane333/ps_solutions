#pragma warning(disable:4996)
#include <stdio.h>
#define ll long long

int main(void) {
	int n, t;
	int a[100010] = {0, };
	ll res = 0LL;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		++a[t];
	}
	
	//qsort(a, n, sizeof(ll), cmp);
	
	int w[200020] = {0, };
	for (int i = 1; i < 100010; ++i) {
		if (a[i - 1] < a[i]) {
			for (int j = a[i - 1] + 1; j <= a[i]; ++j){
				w[j] = i;
			}
		}
		else if (a[i - 1] > a[i]) {
			for (int j = a[i] + 1; j <= a[i - 1]; ++j) {
				res += ((ll)i - (ll)w[j]) * ((ll)i - 1LL);
			}
		}
	}
	
	printf("%lld\n", res);
	return 0;
}
