#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	long long int n;
	int k, q, idx = 1;
	scanf("%lld %d %d", &n, &k, &q);
	long long int data1, data2, temp;
	for (int i = 0; i < q; i++) {
		scanf("%lld %lld", &data1, &data2);
		if (data1 < data2) swap(data1, data2, temp);
		if (k == 1) {
			printf("%lld\n", data1 - data2);
			continue;
		}
		int cnt = 0;
		while (data1 != data2) {
			while (data1 > data2) {
				cnt++;
				data1 = (data1 + k - 2) / k;
			}
			while (data1 < data2) {
				cnt++;
				data2 = (data2 + k - 2) / k;
			}
		}
		printf("%d\n", cnt);
	}


	return 0;
}