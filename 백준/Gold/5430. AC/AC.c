#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int data[100001];
char op[100001];

void swap1(int n) {
	int temp;
	for (int i = 0; i < n / 2; i++) {
		swap(data[i], data[n - i - 1], temp);
	}
}

int main() {
	int testcase, n, ft, bk, R, t, term;
	char t1,t2;
	scanf("%d", &testcase);
	for (int tc = 0; tc < testcase; tc++) {
		for (int i = 0; i < 100001; i++) {
			op[i] = '\0';
		}
		R = 0;
		scanf("%s", op);
		scanf("%d", &n);
		scanf("%c%c", &t1,&t2);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d,", &data[i]);
		}
		if (n != 0) scanf("%d", &data[n - 1]);
		scanf("%c", &t1,&t2);
		ft = 0;
		bk = n;
		t = n;
		for (int i = 0; i < strlen(op); i++) {
			if (op[i] == 'R') {
				R = !R;
			}
			else {
				if (n != 0) {
					if (R == 0) {
						ft++;
					}
					else {
						bk--;
					}
					n--;
				}
				else {
					n--;
					printf("error\n");
					break;
				}
			}
		}
		if (n >= 0) {
			if (R == 1) {
				swap1(t);
				bk = t - ft;
				ft = t - ft - n;
			}
			printf("[");
			for (int i = ft; i < bk; i++) {
				printf("%d", data[i]);
				if (i != bk - 1) printf(",");
			}
			printf("]\n");
		}
	}


	return 0;
}