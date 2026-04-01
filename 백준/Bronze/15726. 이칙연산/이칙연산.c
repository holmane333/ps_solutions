#include <stdio.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(){
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("%d\n", (int)max(a * b / c, a / b * c));
	return 0;
}
