#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct node {
	long long d;
	char c[50];
} node;

int main() {
	long long s, t;
	int useds = 0;
	scanf("%lld %lld", &s, &t);
	if (s == t) {
		printf("0\n");
		return 0;
	}
	node q[10001];
	int ft = 0, rr = 0;
	node new2;
	new2.d = s;
	strcpy(new2.c, "");
	q[ft++] = new2;
	
	while (ft != rr) {
		long long d = q[rr].d;
		char c[50];
		strcpy(c, q[rr].c);
		++rr;
		if (d == t) {
			printf("%s\n", c);
			return 0;
		}
		
		if (d * d <= t && d > 1) {
			node new1;
			new1.d = d * d;
			strcpy(new1.c, c);
			strcat(new1.c, "*");
			q[ft++] = new1;
		}
		
		if (d + d <= t && d >= 1) {
			node new1;
			new1.d = d + d;
			strcpy(new1.c, c);
			strcat(new1.c, "+");
			q[ft++] = new1;
		}
		
		if (!useds) {
			useds = 1;
			node new1;
			new1.d = 1;
			strcpy(new1.c, c);
			strcat(new1.c, "/");
			q[ft++] = new1;
		}
	}
	printf("-1\n");
	return 0;
}
