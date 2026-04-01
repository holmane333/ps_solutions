#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))


int main() {
	int n, m;
	long long int left = 0, right = 0;
	long long int ary[100001];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &ary[i]);
		left = left < ary[i] ? ary[i] : left;
		right += ary[i];
	}

	while (left <= right) {
		long long int mid = (left + right) / 2;
		long long int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (sum + ary[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += ary[i];
		}
		if (sum != 0) cnt++;
		if (cnt <= m) right = mid - 1;
		else left = mid + 1;
	}
	printf("%lld\n", left);


	
	return 0;
}
