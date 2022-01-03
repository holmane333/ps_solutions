#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int stick[7] = { 64,32,16,8,4,2,1 };

int main() {
	int n,result=0;
	scanf("%d", &n);
	do {
		if (n == 0) break;
		for (int i = 0; i < 7; i++) {
			if (n >= stick[i]) {
				n -= stick[i];
				result++;
				break;
			}
		}
	} while (1);
	printf("%d", result);
	
	
	return 0;
}