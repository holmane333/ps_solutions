#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	char a[3];
	double res = 0.0;
	scanf("%s", a);
	if (a[0] != 'F') {
		res += 4 - (int)(a[0] - 'A');
		if (a[1] == '+') res += 0.3;
		else if (a[1] == '-') res -= 0.3;
	}
	
	printf("%.1lf\n", res);
	return 0;
}
