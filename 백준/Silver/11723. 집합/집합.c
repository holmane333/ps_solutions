#include <stdio.h>
#pragma warning(disable:4996)

int n;

int main(void) {
	int ary[30] = {0, }, count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[10];
		int a;
		scanf("%s", str);
		if (str[0] == 'a' && str[1] == 'd') {
			scanf("%d", &a);
			ary[a] = 1;
		}
		else if (str[0] == 'r') {
			scanf("%d", &a);
			ary[a] = 0;
		}
		else if(str[0] == 'c') {
			scanf("%d", &a);
			printf("%d\n", ary[a]);
		}
		else if (str[0] == 't') {
			scanf("%d", &a);
			ary[a] = !ary[a];
		}
		else if (str[0] == 'a') {
			for (int j = 1; j <= 20; j++) ary[j] = 1;
		}
		else {
			for (int j = 1; j <= 20; j++) ary[j] = 0;
		}
	}
	return 0;
}
