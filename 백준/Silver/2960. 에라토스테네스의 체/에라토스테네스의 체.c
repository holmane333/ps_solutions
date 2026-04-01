#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

int data[1001];

int sosu(int n,int m) {
	for (int i = 2; i <= n; i++) {
		
		if (data[i] == -1) {
			data[i] = 0;
			m--;
			if (m == 0) return i;
			for (int j = i; j <= n; j += i) {
				if (data[j] == -1) {
					data[j] = 0;
					m--;
				}
				if (m == 0) return j;
			}
		}
	}
	return n;
}

int main() {
	int n,m;
	memset(data, -1, sizeof(data));
	data[0] = 0;
	data[1] = 0;
	scanf("%d %d", &n,&m);
	printf("%d\n", sosu(n, m));
	return 0;
}