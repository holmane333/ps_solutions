#include <stdio.h>
#pragma warning(disable:4996)

int main(){
	int n, k = 1, cnt = 0;
	scanf("%d", &n);
	while (n){
		if (n >= k) {
			n -= k;
			++k;
			++cnt;
		}
		else k = 1;
	}
	printf("%d\n", cnt);
	return 0;
}
