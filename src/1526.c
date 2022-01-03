#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	while(n) {
		int t = n, c = 0;
		while(t) {
			if (t % 10 == 4 || t % 10 == 7) t /= 10;
			else {
				c = 1;
				break;
			}
		}
		if (c == 0) {
			printf("%d\n", n);
			return 0;
		}
		n--;
	}
	
	return 0;
}
